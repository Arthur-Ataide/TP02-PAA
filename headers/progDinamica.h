#include "./caverna.h"

typedef struct TipoProgDinamica* PProgDinamica;
typedef struct TipoProgDinamica{
    int tamCaminho;
    PParOrdenado vetParOrdenado;
    PCaverna caverna;
} TipoProgDinamica;

void criarVetorParOrdenado(PProgDinamica programa); // malloc vetor de pares ordenados

bool verificaPosicaoInicialFinal(PCaverna caverna); // verifica se a posicao inicial e final sao validas (a inicial tem q ser depois que a final na linha e na coluna)

int maximo(int a, int b); // verifica a maior entre duas variaveis

bool programacaoDinamica(PCaverna caverna); // retorna true se existe um caminho e cria as matrizes de programacao dinamica e visitados

void escreveArquivoSemCaminho(int* numCaverna); // escreve no arquivo de saida que nao existe caminho

void escreveArquivo(PProgDinamica programa, int* numCaverna); // escreve no arquivo de saida o caminho

void descobreCaminho(PProgDinamica programa, int* numCaverna); // descobre o caminho com base na programacaoDinamica e escreve no arquivo de saida

void limparVetParOrdenado(PParOrdenado vetParOrdenado); // libera o vetor de pares ordenados
