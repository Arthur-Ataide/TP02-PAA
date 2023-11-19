#include "./caverna.h"

typedef struct TipoProgDinamica* PProgDinamica;
typedef struct TipoProgDinamica{
    int tamCaminho;
    PParOrdenado vetParOrdenado;
    PCaverna caverna;
} TipoProgDinamica;

void teste();

void criarVetorParOrdenado(PProgDinamica programa);

bool verificaPosicaoInicialFinal(PCaverna caverna);

int maximo(int a, int b);

bool programacaoDinamica(PCaverna caverna);

void escreveArquivoSemCaminho(int* numCaverna);

void escreveArquivo(PProgDinamica programa, int* numCaverna);

void descobreCaminho(PProgDinamica programa, int* numCaverna);

void limparVetParOrdenado(PParOrdenado vetParOrdenado);
