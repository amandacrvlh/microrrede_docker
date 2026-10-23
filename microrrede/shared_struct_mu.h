#ifndef SHARED_STRUCT_MU_H
#define SHARED_STRUCT_MU_H

#define SHM_NAME "/shm_microrrede"
#define BUFFER_SIZE 1000

// Amostra individual gravada no buffer da SHM
typedef struct {
    double tempo;

    /* Entradas (Inputs) */
    double Irr1;
    double Irr2;
    double Irr3;
    double LoadA;
    double LoadB;
    double LoadC;
    double Fator1;
    double Fator2;
    double Fator3;
    double XCBR_PCC_in;
    double XCBR_N_in;
    double XCBR_CC_1_in;
    double XCBR_CC_2_in;
    double XCBR_CC_3_in;

    /* Saídas Elétricas (Outputs) */
    double VPCC1[3];
    double IPCC1[3];
    double VPCC2[3];
    double IPCC2[3];

    /* Estado e Contagem de Operações do Disjuntor */
    int XCBR_PCC_Pos_stVal;
    int XCBR_PCC_OpCnt;
} AmostraMU;

// Estrutura principal da Memória Compartilhada
typedef struct {
    int simulacao_ativa;
    int indice_escrita;
    AmostraMU dados[BUFFER_SIZE];
} MemoriaCompartilhada;

#endif /* SHARED_STRUCT_MU_H */
