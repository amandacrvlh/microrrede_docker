#include "goose_receiver.h"
#include "goose_subscriber.h"
#include "iec61850_server.h"
#include "sv_publisher.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

/* Inclusões para comunicação via Memória Compartilhada POSIX */
#include "shared_struct_mu.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Include the generated header with the model access handles */
#include "static_model.h"

/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;
static IedServer iedServer = NULL;

static int running = 0;
static int svcbEnabled = 1;

void sigint_handler(int signalId)
{
    running = 0;
}

static int amp1; static int amp2; static int amp3; static int amp4;
static int amp1q; static int amp2q; static int amp3q; static int amp4q;
static int vol1; static int vol2; static int vol3; static int vol4;
static int vol1q; static int vol2q; static int vol3q; static int vol4q;

static SVPublisher svPublisher = NULL;
static SVPublisher_ASDU asdu = NULL;

static void setupSVPublisher(const char* svInterface)
{
    svPublisher = SVPublisher_create(NULL, svInterface);

    if (svPublisher) {
        asdu = SVPublisher_addASDU(svPublisher, "VMU01", NULL, 1);

        amp1 = SVPublisher_ASDU_addINT32(asdu); amp1q = SVPublisher_ASDU_addQuality(asdu);
        amp2 = SVPublisher_ASDU_addINT32(asdu); amp2q = SVPublisher_ASDU_addQuality(asdu);
        amp3 = SVPublisher_ASDU_addINT32(asdu); amp3q = SVPublisher_ASDU_addQuality(asdu);
        amp4 = SVPublisher_ASDU_addINT32(asdu); amp4q = SVPublisher_ASDU_addQuality(asdu);

        vol1 = SVPublisher_ASDU_addINT32(asdu); vol1q = SVPublisher_ASDU_addQuality(asdu);
        vol2 = SVPublisher_ASDU_addINT32(asdu); vol2q = SVPublisher_ASDU_addQuality(asdu);
        vol3 = SVPublisher_ASDU_addINT32(asdu); vol3q = SVPublisher_ASDU_addQuality(asdu);
        vol4 = SVPublisher_ASDU_addINT32(asdu); vol4q = SVPublisher_ASDU_addQuality(asdu);

        SVPublisher_ASDU_setSmpCntWrap(asdu, 4800);
        SVPublisher_ASDU_setRefrTm(asdu, 0);

        SVPublisher_setupComplete(svPublisher);
    }
}

static void sVCBEventHandler (SVControlBlock* svcb, int event, void* parameter)
{
    if (event == IEC61850_SVCB_EVENT_ENABLE) svcbEnabled = 1;
    else if (event == IEC61850_SVCB_EVENT_DISABLE) svcbEnabled = 0;
}

static void goCbEventHandler(MmsGooseControlBlock goCb, int event, void* parameter)
{
    printf("Access to GoCB: %s\n", MmsGooseControlBlock_getName(goCb));
}

static void gooseListener(GooseSubscriber subscriber, void* parameter)
{
    MmsValue* values = GooseSubscriber_getDataSetValues(subscriber);
    char buffer[50];
    MmsValue_printToBuffer(values, buffer, 50);

    char b = buffer[1];
    char c = buffer[7];

    if(b == 116){ 
        IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_BinIO_BinaryInputs_LPDI3_In_stVal, true);
        printf("[MU GOOSE] Comando recebido: Habilitar Entradas Lógicas.\n");
    }
    if(c == 116){ 
        IedServer_updateBooleanAttributeValue(iedServer, IEDMODEL_BinIO_BinaryInputs_LPDI3_In_stVal, false);
        printf("[MU GOOSE] Comando recebido: Desabilitar Entradas Lógicas.\n");
    }
}

int main(int argc, char** argv)
{
    char* svInterface = "eth0";

    if (argc > 1){
        svInterface = argv[1];
    }
    
    /* CONFIGURAÇÃO DA CONEXÃO VIA MEMÓRIA COMPARTILHADA NATIVA */
    printf("[MU] Tentando mapear a Memória Compartilhada (%s)...\n", SHM_NAME);
    int shm_fd = -1;
    int tentativas = 0;

    while (shm_fd == -1) {
        shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
        if (shm_fd == -1) {
            printf("[MU] Aguardando inicialização do Simulador Simulink... (tentativa %d)\n", ++tentativas);
            sleep(1);
        }
    }

    const MemoriaCompartilhada *shm_ptr = (const MemoriaCompartilhada *)mmap(
        0, sizeof(MemoriaCompartilhada), PROT_READ, MAP_SHARED, shm_fd, 0
    );

    if (shm_ptr == MAP_FAILED) {
        perror("[MU] Erro no mmap");
        close(shm_fd);
        return 1;
    }

    printf("[MU] Memória Compartilhada vinculada com sucesso!\n");

    /* Inicialização do Servidor IEC 61850 */
    IedServerConfig config = IedServerConfig_create();
    iedServer = IedServer_createWithConfig(&iedModel, NULL, config);
    IedServerConfig_destroy(config);
    
    IedServer_enableGoosePublishing(iedServer);
    GooseReceiver receiver = GooseReceiver_create();
    GooseReceiver_setInterfaceId(receiver, svInterface);
    GooseSubscriber subscriber = GooseSubscriber_create("VIED_21L9CFG/LLN0$GO$CONTROL_BK", NULL);
    GooseSubscriber_setListener(subscriber, gooseListener, iedServer);
    GooseReceiver_addSubscriber(receiver, subscriber);
    GooseReceiver_start(receiver);

    IedServer_setGoCBHandler(iedServer, goCbEventHandler, NULL);
    IedServer_start(iedServer, 120);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
        munmap((void*)shm_ptr, sizeof(MemoriaCompartilhada));
        close(shm_fd);
        exit(-1);
    }

    running = 1;
    signal(SIGINT, sigint_handler);

    // Tenta inicializar o publicador de Sampled Values
    setupSVPublisher(svInterface);

    if (!svPublisher) {
        printf("[ERRO CRÍTICO MU] Não foi possível iniciar o SV Publisher na interface '%s'!\n", svInterface);
        printf("[ERRO CRÍTICO MU] Verifique se o nome da interface está correto e se possui privilégios de ROOT (NET_ADMIN).\n");
        printf("[ERRO CRÍTICO MU] Abortando execução por segurança.\n");
        running = 0; 
    } else {
        printf("=== MERGING UNIT EM TEMPO REAL: Processando dados da Barra 1 do PCC ===\n");
    }

    /* ESPERA SINCRONIZADA: Aguarda o Simulador de fato iniciar e ligar a flag simulacao_ativa */
    if (running) {
        printf("[MU] Aguardando sinal de início de simulação do Simulador...\n");
        while (running && !shm_ptr->simulacao_ativa) {
            usleep(100000); // Aguarda 100ms até o simulador iniciar
        }
        if (running) {
            printf("[MU] Simulação Detectada! Iniciando envio de pacotes SV...\n");
        }
    }

    Quality q = QUALITY_VALIDITY_GOOD;
    int voltageA, voltageB, voltageC, voltageN;
    int currentA, currentB, currentC, currentN;
    int sampleCount = 0;
    int local_leitura = 0; /* Ponteiro local de leitura exclusivo da MU */

    /* LOOP PRINCIPAL PROCESSADO PASSO A PASSO (CONSUMIDOR READ-ONLY) */
    while (running && (shm_ptr->simulacao_ativa || local_leitura != shm_ptr->indice_escrita)) {
        
        // Verifica se o simulador colocou um dado novo na esteira da RAM
        if (local_leitura != shm_ptr->indice_escrita) {
            int idx = local_leitura;

            /* Extração Exclusiva da Tensão da Barra 1 do PCC (VPCC1) */
            //  CORRETO:
		/* Leitura dos dados da Shared Memory em mu.c */
voltageA = (int)(shm_ptr->dados[idx].VPCC1[0] * 100.0);
voltageB = (int)(shm_ptr->dados[idx].VPCC1[1] * 100.0);
voltageC = (int)(shm_ptr->dados[idx].VPCC1[2] * 100.0);

currentA = (int)(shm_ptr->dados[idx].IPCC1[0] * 1000.0);
currentB = (int)(shm_ptr->dados[idx].IPCC1[1] * 1000.0);
currentC = (int)(shm_ptr->dados[idx].IPCC1[2] * 1000.0);
            /* Atualização do Modelo de Dados IEC 61850 MmsServer com dados do PCC1 */
            IedServer_lockDataModel(iedServer);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_I01ATCTR1_AmpSv_instMag_i, currentA);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_I01ATCTR1_AmpSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_I01BTCTR2_AmpSv_instMag_i, currentB);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_I01BTCTR2_AmpSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_I01CTCTR3_AmpSv_instMag_i, currentC);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_I01CTCTR3_AmpSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_I01NTCTR4_AmpSv_instMag_i, currentN);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_I01NTCTR4_AmpSv_q, q);

            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_U01ATVTR1_VolSv_instMag_i, voltageA);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_U01ATVTR1_VolSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_U01BTVTR2_VolSv_instMag_i, voltageB);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_U01BTVTR2_VolSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_U01CTVTR3_VolSv_instMag_i, voltageC);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_U01CTVTR3_VolSv_q, q);
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Mod3_MU2_U01NTVTR4_VolSv_instMag_i, voltageN);
            IedServer_updateQuality(iedServer, IEDMODEL_Mod3_MU2_U01NTVTR4_VolSv_q, q);
            IedServer_unlockDataModel(iedServer);

            /* Transmissão do Pacote de Rede Sampled Values (SV) com dados do PCC1 */
            if (svcbEnabled && svPublisher) {
                SVPublisher_ASDU_setINT32(asdu, amp1, currentA);   SVPublisher_ASDU_setQuality(asdu, amp1q, q);
                SVPublisher_ASDU_setINT32(asdu, amp2, currentB);   SVPublisher_ASDU_setQuality(asdu, amp2q, q);
                SVPublisher_ASDU_setINT32(asdu, amp3, currentC);   SVPublisher_ASDU_setQuality(asdu, amp3q, q);
                SVPublisher_ASDU_setINT32(asdu, amp4, currentN);   SVPublisher_ASDU_setQuality(asdu, amp4q, q);

                SVPublisher_ASDU_setINT32(asdu, vol1, voltageA);   SVPublisher_ASDU_setQuality(asdu, vol1q, q);
                SVPublisher_ASDU_setINT32(asdu, vol2, voltageB);   SVPublisher_ASDU_setQuality(asdu, vol2q, q);
                SVPublisher_ASDU_setINT32(asdu, vol3, voltageC);   SVPublisher_ASDU_setQuality(asdu, vol3q, q);
                SVPublisher_ASDU_setINT32(asdu, vol4, voltageN);   SVPublisher_ASDU_setQuality(asdu, vol4q, q);

                SVPublisher_ASDU_setRefrTmNs(asdu, Hal_getTimeInNs());
                SVPublisher_ASDU_setSmpCnt(asdu, (uint16_t) sampleCount);
                SVPublisher_publish(svPublisher);
            }

            sampleCount = ((sampleCount + 1) % 4800);

            // Avança unicamente o índice local de leitura da MU
            local_leitura = (local_leitura + 1) % BUFFER_SIZE;
        } else {
            // Se o buffer estiver vazio, aguarda 10 microsegundos
            usleep(10);
        }
    }

    /* Finalização e Limpeza de Recursos de Forma Segura */
    printf("[MU] Encerrando servidores e liberando canais de memória...\n");
    if (iedServer) {
        IedServer_stop(iedServer);
        IedServer_destroy(iedServer);
    }
    if (svPublisher) {
        SVPublisher_destroy(svPublisher);
    }

    munmap((void*)shm_ptr, sizeof(MemoriaCompartilhada));
    close(shm_fd);

    return 0;
}
