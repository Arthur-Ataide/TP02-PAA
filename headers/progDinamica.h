#include "./caverna.h"

typedef struct PilhaParOrdenado* PPilhaParOrdenado;
typedef struct PilhaParOrdenado{
    PParOrdenado pilha;
} PilhaParOrdenado;

void teste();

void verificaPosicaoInicialFinal(PCaverna caverna);

int maximo(int a, int b);

void programacaoDinamica(PCaverna caverna);

void escreverCaminho(FILE * file, int i, int j);

void Caminho(PCaverna caverna, ParOrdenado* caminho);
