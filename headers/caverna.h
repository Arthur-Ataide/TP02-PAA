#include "./progDinamica.h"

typedef struct TipoCaverna{
    unsigned int tamI, tamJ;
    char **Matrix;
    char **MatrixMovimento;
    PCaminho caminhosPossiveis;
}TipoCaverna;

TipoCaverna* generateCaverna(FILE* f);

TipoCaverna* generateCavernaAleatoria();

void showCaverna(TipoCaverna* caverna);

void printAtributos(TipoCaverna* caverna);

void freeCaverna(TipoCaverna* caverna);
