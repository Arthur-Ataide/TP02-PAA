#include "./caverna.h"

typedef struct TipoProgDinamica* PProgDinamica;
typedef struct TipoProgDinamica{
    PParOrdenado vetParOrdenado;
    PCaverna caverna;
} TipoProgDinamica;

void teste();

PParOrdenado criarVetorParOrdenado(PCaverna caverna);

bool verificaPosicaoInicialFinal(PCaverna caverna);

int maximo(int a, int b);

bool programacaoDinamica(PCaverna caverna);

void escreverCaminho(FILE * file, int i, int j);

void descobreCaminho(PCaverna caverna, PProgDinamica programa);
