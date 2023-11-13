#include "./progDinamica.h"

typedef struct TipoCaverna* PCaverna;
typedef struct TipoCaverna{
    unsigned int tamI, tamJ;
    char **Matrix;
    char **MatrixMovimento;
    PCaminho caminhosPossiveis;
}TipoCaverna;

void teste();

PCaverna geradorCaverna(FILE* f);

PCaverna generateCavernaAleatoria();

void showCaverna(PCaverna caverna);

void printAtributos(PCaverna caverna);

void freeCaverna(PCaverna caverna);
