#include "./progDinamica.h"

typedef struct TipoCaverna* PCaverna;
typedef struct TipoCaverna{
    TipoParOrdenado tam;
    unsigned int vida;
    TipoParOrdenado entrada;
    TipoParOrdenado saida;
    int** Matrix;
    char** MatrixMovimento;
    PCaminho caminhosPossiveis;
}TipoCaverna;

void teste();

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
