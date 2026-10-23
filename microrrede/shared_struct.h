#ifndef SHARED_STRUCT_MU_H
#define SHARED_STRUCT_MU_H

#define SHM_NAME "/shm_microrrede"
#define BUFFER_SIZE 1000

/* Estrutura para os Sinais de Entrada (Inputs) */
typedef struct {
    /* Irradiâncias */
    double Irr1;
    double Irr2;
    double Irr3;

    /* Cargas */
    double LoadA;
    double LoadB;
    double LoadC;

    /* Fatores */
    double Fator1;
    double Fator2;
    double Fator3;

    /* Comandos de Disjuntores */
    double XCBR_PCC_in;
    double XCBR_N_in;
    double XCBR_CC_1_in;
    double XCBR_CC_2_in;
    double XCBR_CC_3_in;
    double XCBR_banco3p_in;
    double XCBR_banco1p_in;
} EntradasMicrorrede;

/* Estrutura para os Sinais de Saída (Outputs) */
typedef struct {
    /* Medições Trifásicas */
    double VPCC1[3];
    double IPCC1[3];
    double VPCC2[3];
    double IPCC2[3];
    double Vload3[3];
    double Iload3[3];

    /* Medições Escalares */
    double V1; double I1;
    double V2; double I2;
    double V3; double I3;

    /* Status de Retorno dos Disjuntores */
    double XCBR_PCC_out;
    double XCBR_N_out;
    double XCBR_CC_1_out;
    double XCBR_CC_2_out;
    double XCBR_CC_3_out;
    double XCBR_banco3p_out;
    double XCBR_banco1p_out;
} SaidasMicrorrede;

/* Estrutura da Amostra Completa por Passo de Tempo */
typedef struct {
    double tempo;
    EntradasMicrorrede in;
    SaidasMicrorrede out;
} AmostraMU;

/* Memória Compartilhada Principal */
typedef struct {
    int simulacao_ativa;            // Controla se o solver está rodando
    int indice_escrita;             // Ponteiro do buffer circular
    AmostraMU dados[BUFFER_SIZE];   // Buffer circular de amostras completas
} MemoriaCompartilhada;

#endif
