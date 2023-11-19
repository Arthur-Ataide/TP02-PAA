#include "./progDinamica.h"

void lerSelecao(int Selecao[10], int* quantidadeCavernas); // Leitura do arquivo selecao para identificar as cavernas que serao abertas

void abrirCaverna(FILE** f, int numCaverna); // deixa o arquivo caverna, que foi selecionado pronto para leitura

void menu(); // Menu das selecao de cavernas
