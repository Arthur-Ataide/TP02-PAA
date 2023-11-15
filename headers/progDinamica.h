#include "./caverna.h"

typedef struct PilhaParOrdenado* PPilhaParOrdenado;
typedef struct PilhaParOrdenado{
    PParOrdenado pilha;
} PilhaParOrdenado;

void teste();

void verificaPosicaoInicialFinal(PCaverna caverna);

void programacaoDinamica(PCaverna caverna);