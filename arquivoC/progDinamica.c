#include "../headers/progDinamica.h"

void teste(){ // so para testar onde esta o erro
    printf("\n\nteste\n\n");
}

PParOrdenado criarVetorParOrdenado(PCaverna caverna){
    return ((PParOrdenado) malloc(sizeof(TipoParOrdenado) * ((caverna->entrada.linha - caverna->saida.linha) + (caverna->entrada.coluna - caverna->saida.coluna))));
}

bool verificaPosicaoInicialFinal(PCaverna caverna){
    if (((caverna->entrada.linha) < (caverna->saida.linha)) || ((caverna->entrada.coluna) < (caverna->saida.coluna)))
        return false;
    return true;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

void programacaoDinamica(PCaverna caverna){

    TipoParOrdenado saida, entrada;
    saida.linha = caverna->saida.linha;         saida.coluna = caverna->saida.coluna;
    entrada.linha = caverna->entrada.linha;     entrada.coluna = caverna->entrada.coluna;

    

    for (int i = entrada.linha; i >= saida.linha; i--){
        for (int j = entrada.coluna; j >= saida.coluna; j--){

            int atual = 0;

            if (i == entrada.linha && j == entrada.coluna){
                atual = caverna->vida;
            }

            else if (i == entrada.linha && j != entrada.coluna){
                atual = caverna->MatrixDinamica[i][j + 1] + caverna->Matrix[i][j];

                if (atual < 0){
                    break;
                }
                
            }

            else if (i != entrada.linha && j == entrada.coluna){
                if (caverna->MatrixVisitados[i + 1][j] == true)
                    atual = caverna->MatrixDinamica[i + 1][j] + caverna->Matrix[i][j];

                else
                    saida.coluna--;
                    
            }

            else{
                if (caverna->MatrixVisitados[i + 1][j] == true){
                    if (caverna->MatrixVisitados[i][j + 1] == true){
                        atual = maximo(caverna->MatrixDinamica[i + 1][j], caverna->MatrixDinamica[i][j + 1]) + caverna->Matrix[i][j];
                    }
                    else
                        atual = caverna->MatrixDinamica[i + 1][j] + caverna->Matrix[i][j];
                }

                else if (caverna->MatrixVisitados[i][j + 1] == true)
                    atual = caverna->MatrixDinamica[i][j + 1] + caverna->Matrix[i][j];

                
            }

            if (atual > 0){
                    caverna->MatrixDinamica[i][j] = atual;
                    caverna->MatrixVisitados[i][j] = true;
            }
        
        }
        
    }
}

// void escreverCaminho(FILE * file, int i, int j) {
//     char buffer[] = {i, ' ', j, '\n'};
//     fwrite(buffer, 1, sizeof(buffer), file);
// }

// void Caminho(PCaverna caverna, PProgDinamica programa){ // descobrir o caminho
//     FILE * file;
//     file = fopen("./arquivosResultados/resultado.txt", "w");
//     int linha, coluna;
   
//     // (*caminho)[i].linha = começa salvando pela entrada ou pela saida
//     // (*caminho)[i].coluna = 

//     caverna.MatrixDinamica[caverna.entrada.linha][caverna.entrada.coluna] = true;

//     for (int i = caverna->entrada.linha; i < caverna->saida.linha; i--){
//         for (int j = caverna->entrada.coluna; j >= caverna->saida.coluna; j--){
//             if ((i > caverna->entrada.linha) && (caverna->MatrixDinamica[i][j] == true)){
                
//                 caverna->MatrixDinamica[i][j] = fmax(caverna->MatrixDinamica[i][j], caverna->MatrixDinamica[i - 1][j]);
//             }
//             if (i > caverna->entrada.coluna){
//                 caverna->MatrixDinamica[i][j] = fmax(caverna->MatrixDinamica[i][j], caverna->MatrixDinamica[i][j - 1]);
//             }
//             if (caverna->MatrixDinamica[i-1][j] > caverna->MatrixDinamica[i][j-1]){
//                 escreverCaminho(file, i-, j);
//             }
            
//             caverna.MatrixDinamica[i][j] += caverna.Matrix[i][j];
//         }
//     }

//     int i = caverna.saida.linha;
//     int j = caverna.saida.coluna;
//     int k = 0;

//     while (i != caverna.entrada.linha || j != caverna.entrada.coluna) {
//         caminho[k].linha = i;
//         caminho[k].coluna = j;
//         k++;

//         if (i > 0 && caverna.MatrixDinamica[i][j] - caverna.Matrix[i][j] == caverna.MatrixDinamica[i - 1][j]) {
//             i--;
//         } else {
//             j--;
//         }
//     }

//     caminho[k].linha = caverna.entrada.linha;
//     caminho[k].coluna = caverna.entrada.coluna;

//     for (int l = k; l >= 0; l--) {
//         fprintf(file, "Linha: %d, Coluna: %d\n", caminho[l].linha, caminho[l].coluna);
//     }

    
//     fclose(file);    
// }
//         // void mandarEmailProDaniel(int matricula, char email[50]){
            
//         // }