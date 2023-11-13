#include "./include.h"

typedef struct TipoCaminho* PCaminho;
typedef struct TipoCaminho{

    int ** vetCaminho;
    int tamanho;
    PCaminho proxCaminho;

} TipoCaminho;

PCaminho procurarCaminho(char** matrix,int &caminhosJaVistos);
