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

void mostrarAtributos(PCaverna caverna);

void linha(int tam, bool poder);

void coluna(int tam, bool poder);

void grafico(char identificador, char bloco);

void mostrarCaverna(PCaverna caverna);

void atributos(FILE *f, PCaverna caverna);

PCaverna geradorCaverna(FILE* f);

PCaverna geradorCavernaAleatoria();

void printAtributos(PCaverna caverna);

void limparCaverna(PCaverna caverna);
