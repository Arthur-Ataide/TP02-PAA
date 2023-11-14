#include "./include.h"

typedef struct TipoParOrdenado{
    int X;
    int Y;
} TipoParOrdenado;

typedef struct TipoCaminho* PCaminho;
typedef struct TipoCaminho{

    int ** vetCaminho;
    int tamanho;
    PCaminho proxCaminho;

} TipoCaminho;

PCaminho procurarCaminho(int** matrix);
