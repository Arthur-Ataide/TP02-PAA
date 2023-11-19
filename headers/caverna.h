#include "./include.h"


typedef struct TipoParOrdenado* PParOrdenado;
typedef struct TipoParOrdenado{
    int linha;
    int coluna;
} TipoParOrdenado;

typedef struct TipoCaverna* PCaverna;
typedef struct TipoCaverna{
    TipoParOrdenado tam;
    unsigned int vida;
    TipoParOrdenado entrada;
    TipoParOrdenado saida;
    int** Matrix;
    int** MatrixDinamica;
    bool** MatrixVisitados;
}TipoCaverna;

// Funcoes de modelagem do problema
// void teste();                                    // Funcao de teste para identificar erros
// void linha(int tam, bool poder);                 // Funcao que imprime uma linha de tamanho tam colorida
// void coluna(int tam, bool poder);                // Funcao que imprime uma coluna de tamanho tam colorida
// void mostrarAtributos(PCaverna caverna);         // Funcao que imprime os atributos da caverna
// void grafico(char identificador, char bloco);    // Funcao que imprime um bloco de tamanho 1x1 colorido dependendo do identificador
// void mostrarCaverna(PCaverna caverna);           // Funcao que imprime a caverna
// void mostrarMatrix(PCaverna caverna);            // Funcao que imprime matrix visitados e matrix dinamica

void atributos(FILE *f, PCaverna caverna); // Leitura dos atributos da caverna

PCaverna geradorCaverna(FILE* f); // da malloc nas matrizes e recebe a caverna a colocando no tad TipoCaverna

void limparCaverna(PCaverna caverna); // libera as matrizes da caverna
