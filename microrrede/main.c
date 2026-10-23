#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>

// Definição das constantes de cor ANSI para o terminal
#define ANSI_CLEAR      "\033[2J\033[H"
#define ANSI_BOLD       "\033[1m"
#define ANSI_GREEN      "\033[32m"
#define ANSI_RED        "\033[31m"
#define ANSI_CYAN       "\033[36m"
#define ANSI_RESET      "\033[0m"

#include "microrrede_v8.h"
#include "shared_struct_mu.h"

#define TS_NS               4167L       // 4.1666667 us em nanosegundos (arredondado)
#define FREQ_HZ             60.0
#define SAMPLES_PER_CYCLE   80
#define DECIMATION          50          // 50 * 4.1666667us = 208.333 us

static volatile sig_atomic_t g_stop = 0;

static void handle_sigint(int sig) {
    (void)sig;
    g_stop = 1;
}

// Eleva a prioridade do processo para SCHED_FIFO no Linux (Tempo Real)
void set_realtime_priority(void) {
    struct sched_param param;
    param.sched_priority = 99; // Prioridade máxima de RT
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("[Aviso] Nao foi possivel definir prioridade SCHED_FIFO (Execute com sudo/privilegios)");
    } else {
        printf("[Simulador] Prioridade de Tempo Real (SCHED_FIFO) configurada com sucesso!\n");
    }
}

typedef enum {
    IEC61850_DBPOS_INTERMEDIATE = 0,
    IEC61850_DBPOS_OFF = 1,          // ABERTO
    IEC61850_DBPOS_ON = 2,           // FECHADO
    IEC61850_DBPOS_BAD = 3
} DbposStatus;

int main(void) {
    long step_count = 0;
    int op_counter = 0;
    DbposStatus last_status = IEC61850_DBPOS_ON;
    setbuf(stdout, NULL);

    signal(SIGINT, handle_sigint);

    /* 1. Criar/Mapear região de Memória Compartilhada POSIX */
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Erro ao criar a memoria compartilhada");
        return 1;
    }

    if (ftruncate(shm_fd, sizeof(MemoriaCompartilhada)) == -1) {
        perror("Erro no ftruncate");
        close(shm_fd);
        return 1;
    }

    MemoriaCompartilhada *shm_ptr = (MemoriaCompartilhada *)mmap(0, sizeof(MemoriaCompartilhada), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("Erro ao mapear memoria");
        close(shm_fd);
        return 1;
    }

    memset(shm_ptr, 0, sizeof(MemoriaCompartilhada));
    shm_ptr->indice_escrita = 0;

    /* 2. Criar e Inicializar o Arquivo CSV */
    FILE *csv_file = fopen("simulacao_microrrede.csv", "w");
    if (csv_file == NULL) {
        perror("Erro ao criar o arquivo CSV");
        munmap(shm_ptr, sizeof(MemoriaCompartilhada));
        close(shm_fd);
        return 1;
    }

    fprintf(csv_file,
        "tempo,"
        "Irr1,Irr2,Irr3,LoadA,LoadB,LoadC,Fator1,Fator2,Fator3,"
        "XCBR_PCC_in,XCBR_N_in,XCBR_CC_1_in,XCBR_CC_2_in,XCBR_CC_3_in,"
        "VPCC1_A,VPCC1_B,VPCC1_C,IPCC1_A,IPCC1_B,IPCC1_C,"
        "VPCC2_A,VPCC2_B,VPCC2_C,IPCC2_A,IPCC2_B,IPCC2_C,"
        "XCBR_PCC_Pos_stVal,XCBR_PCC_OpCnt\n");

    /* 3. SOLICITAÇÃO INTERATIVA DOS DADOS VIA TERMINAL */
    printf("\n==================================================\n");
    printf("    CONFIGURAÇÃO DE PARÂMETROS DA MICRORREDE      \n");
    printf("==================================================\n");

    /* Irradiâncias */
    printf("Irradiância GD1 (Irr1) [W/m²] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.Irr1) != 1) microrrede_v8_U.Irr1 = 1000.0;

    printf("Irradiância GD2 (Irr2) [W/m²] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.Irr2) != 1) microrrede_v8_U.Irr2 = 1000.0;

    printf("Irradiância GD3 (Irr3) [W/m²] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.Irr3) != 1) microrrede_v8_U.Irr3 = 1000.0;

    /* Cargas */
    printf("\nCarga A (LoadA) [W] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.LoadA) != 1) microrrede_v8_U.LoadA = 1000.0;

    printf("Carga B (LoadB) [W] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.LoadB) != 1) microrrede_v8_U.LoadB = 1000.0;

    printf("Carga C (LoadC) [W] (Padrão 1000): ");
    if (scanf("%lf", &microrrede_v8_U.LoadC) != 1) microrrede_v8_U.LoadC = 1000.0;

    /* Fatores */
    printf("\nFator 1 (Fator1) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.Fator1) != 1) microrrede_v8_U.Fator1 = 1.0;

    printf("Fator 2 (Fator2) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.Fator2) != 1) microrrede_v8_U.Fator2 = 1.0;

    printf("Fator 3 (Fator3) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.Fator3) != 1) microrrede_v8_U.Fator3 = 1.0;

    /* Disjuntores */
    printf("\n--- ESTADO DOS DISJUNTORES (1 = Fechado, 0 = Aberto) ---\n");

    printf("Disjuntor PCC (XCBR_PCC_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_PCC_in) != 1) microrrede_v8_U.XCBR_PCC_in = 1.0;

    printf("Disjuntor Neutro (XCBR_N_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_N_in) != 1) microrrede_v8_U.XCBR_N_in = 1.0;

    printf("Disjuntor CC 1 (XCBR_CC_1_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_CC_1_in) != 1) microrrede_v8_U.XCBR_CC_1_in = 1.0;

    printf("Disjuntor CC 2 (XCBR_CC_2_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_CC_2_in) != 1) microrrede_v8_U.XCBR_CC_2_in = 1.0;

    printf("Disjuntor CC 3 (XCBR_CC_3_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_CC_3_in) != 1) microrrede_v8_U.XCBR_CC_3_in = 1.0;

    printf("Disjuntor Banco Trifásico (XCBR_banco3p_in) (Padrão 1.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_banco3p_in) != 1) microrrede_v8_U.XCBR_banco3p_in = 1.0;

    printf("Disjuntor Banco Monofásico (XCBR_banco1p_in) (Padrão 0.0): ");
    if (scanf("%lf", &microrrede_v8_U.XCBR_banco1p_in) != 1) microrrede_v8_U.XCBR_banco1p_in = 0.0;

    /* 4. ATIVAR TEMPO REAL E INICIALIZAR O MODELO */
    set_realtime_priority();

    printf("\n[1/3] Sinalizando início de simulação para a Merging Unit (SHM)...\n");
    shm_ptr->simulacao_ativa = 1;

    printf("[2/3] Executando microrrede_v8_initialize()...\n");
    microrrede_v8_initialize();

    printf("[3/3] Modelo inicializado com sucesso! Iniciando simulação em Tempo Real...\n\n");

    /* 5. ESTRUTURA DE TEMPORIZAÇÃO EM TEMPO REAL */
    struct timespec next_step_time;
    clock_gettime(CLOCK_MONOTONIC, &next_step_time);

    /* 6. LOOP PRINCIPAL DE SIMULAÇÃO */
    while (!g_stop) {
        double t = step_count * (4.1666667e-6);

        /* Passo do Solver C (Simulink) */
        microrrede_v8_step();

        /* Atualização da Memória Compartilhada e CSV a cada 50 passos (~208.33 us) */
        if (step_count % DECIMATION == 0) {
            int idx = shm_ptr->indice_escrita;

            /* Preenchimento da Memória Compartilhada */
            shm_ptr->dados[idx].tempo = t;
            shm_ptr->dados[idx].Irr1 = microrrede_v8_U.Irr1;
            shm_ptr->dados[idx].Irr2 = microrrede_v8_U.Irr2;
            shm_ptr->dados[idx].Irr3 = microrrede_v8_U.Irr3;
            shm_ptr->dados[idx].LoadA = microrrede_v8_U.LoadA;
            shm_ptr->dados[idx].LoadB = microrrede_v8_U.LoadB;
            shm_ptr->dados[idx].LoadC = microrrede_v8_U.LoadC;
            shm_ptr->dados[idx].Fator1 = microrrede_v8_U.Fator1;
            shm_ptr->dados[idx].Fator2 = microrrede_v8_U.Fator2;
            shm_ptr->dados[idx].Fator3 = microrrede_v8_U.Fator3;
            shm_ptr->dados[idx].XCBR_PCC_in = microrrede_v8_U.XCBR_PCC_in;
            shm_ptr->dados[idx].XCBR_N_in = microrrede_v8_U.XCBR_N_in;
            shm_ptr->dados[idx].XCBR_CC_1_in = microrrede_v8_U.XCBR_CC_1_in;
            shm_ptr->dados[idx].XCBR_CC_2_in = microrrede_v8_U.XCBR_CC_2_in;
            shm_ptr->dados[idx].XCBR_CC_3_in = microrrede_v8_U.XCBR_CC_3_in;

            memcpy(shm_ptr->dados[idx].VPCC1, (void*)microrrede_v8_Y.VPCC1, 3 * sizeof(double));
            memcpy(shm_ptr->dados[idx].IPCC1, (void*)microrrede_v8_Y.IPCC1, 3 * sizeof(double));
            memcpy(shm_ptr->dados[idx].VPCC2, (void*)microrrede_v8_Y.VPCC2, 3 * sizeof(double));
            memcpy(shm_ptr->dados[idx].IPCC2, (void*)microrrede_v8_Y.IPCC2, 3 * sizeof(double));

            DbposStatus current_status = (microrrede_v8_Y.XCBR_PCC_out > 0.5) ? 
                                         IEC61850_DBPOS_ON : IEC61850_DBPOS_OFF;

            if (current_status != last_status) {
                op_counter++;
                last_status = current_status;
            }

            shm_ptr->dados[idx].XCBR_PCC_Pos_stVal = current_status;
            shm_ptr->dados[idx].XCBR_PCC_OpCnt = op_counter;

            /* Gravação no CSV */
            fprintf(csv_file,
                    "%.6f,"
                    "%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,"
                    "%.1f,%.1f,%.1f,%.1f,%.1f,"
                    "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,"
                    "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,"
                    "%d,%d\n",
                    shm_ptr->dados[idx].tempo,
                    shm_ptr->dados[idx].Irr1, shm_ptr->dados[idx].Irr2, shm_ptr->dados[idx].Irr3,
                    shm_ptr->dados[idx].LoadA, shm_ptr->dados[idx].LoadB, shm_ptr->dados[idx].LoadC,
                    shm_ptr->dados[idx].Fator1, shm_ptr->dados[idx].Fator2, shm_ptr->dados[idx].Fator3,
                    shm_ptr->dados[idx].XCBR_PCC_in, shm_ptr->dados[idx].XCBR_N_in,
                    shm_ptr->dados[idx].XCBR_CC_1_in, shm_ptr->dados[idx].XCBR_CC_2_in, shm_ptr->dados[idx].XCBR_CC_3_in,
                    shm_ptr->dados[idx].VPCC1[0], shm_ptr->dados[idx].VPCC1[1], shm_ptr->dados[idx].VPCC1[2],
                    shm_ptr->dados[idx].IPCC1[0], shm_ptr->dados[idx].IPCC1[1], shm_ptr->dados[idx].IPCC1[2],
                    shm_ptr->dados[idx].VPCC2[0], shm_ptr->dados[idx].VPCC2[1], shm_ptr->dados[idx].VPCC2[2],
                    shm_ptr->dados[idx].IPCC2[0], shm_ptr->dados[idx].IPCC2[1], shm_ptr->dados[idx].IPCC2[2],
                    shm_ptr->dados[idx].XCBR_PCC_Pos_stVal, shm_ptr->dados[idx].XCBR_PCC_OpCnt);

            // Avança o índice circular da SHM para a Merging Unit consumir
            shm_ptr->indice_escrita = (idx + 1) % BUFFER_SIZE;
        }

        /* Impressão suave no Terminal a cada ~200ms (48.000 passos) */
        if (step_count % 48000 == 0) {
            printf("[t=%8.5fs] | L1_V:[%7.1f %7.1f %7.1f] V | L1_I:[%6.1f %6.1f %6.1f] A\n",
                   t,
                   microrrede_v8_Y.VPCC1[0], microrrede_v8_Y.VPCC1[1], microrrede_v8_Y.VPCC1[2],
                   microrrede_v8_Y.IPCC1[0], microrrede_v8_Y.IPCC1[1], microrrede_v8_Y.IPCC1[2]);
        }

        step_count++;

        /* --- TRAVA DE TEMPO REAL DE ALTA PRECISÃO (4.1666667 us) --- */
        next_step_time.tv_nsec += TS_NS;
        if (next_step_time.tv_nsec >= 1000000000L) {
            next_step_time.tv_nsec -= 1000000000L;
            next_step_time.tv_sec += 1;
        }

        /* Dorme até o instante exato do próximo passo sem derivar (drift-free) */
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next_step_time, NULL);
    }

    printf("\nEncerrando simulação da Microrrede...\n");
    
    shm_ptr->simulacao_ativa = 0;

    if (csv_file != NULL) {
        fflush(csv_file);
        fclose(csv_file);
        printf("Dados salvos com sucesso em 'simulacao_microrrede.csv'!\n");
    }

    microrrede_v8_terminate();
    munmap(shm_ptr, sizeof(MemoriaCompartilhada));
    close(shm_fd);
    shm_unlink(SHM_NAME);
    return 0;
}
