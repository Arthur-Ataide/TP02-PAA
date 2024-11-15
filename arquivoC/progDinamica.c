#include "../headers/progDinamica.h"

void criarVetorParOrdenado(PProgDinamica programa){

    programa->tamCaminho = ((programa->caverna->entrada.linha - programa->caverna->saida.linha) + (programa->caverna->entrada.coluna - programa->caverna->saida.coluna));

    programa->vetParOrdenado = ((PParOrdenado)malloc(sizeof(TipoParOrdenado) * programa->tamCaminho));

}

bool verificaPosicaoInicialFinal(PCaverna caverna){
    if (((caverna->entrada.linha) < (caverna->saida.linha)) || ((caverna->entrada.coluna) < (caverna->saida.coluna)))
        return false;
    return true;
}

int maximo(int a, int b){
    return (a > b) ? a : b;
}

bool programacaoDinamica(PCaverna caverna){

    TipoParOrdenado saida, entrada;
    saida.linha = caverna->saida.linha;
    saida.coluna = caverna->saida.coluna;
    entrada.linha = caverna->entrada.linha;
    entrada.coluna = caverna->entrada.coluna;

    int cont = 0;

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
                if (caverna->MatrixVisitados[i + 1][j] == true){
                    atual = caverna->MatrixDinamica[i + 1][j] + caverna->Matrix[i][j];
                    if (atual < 0){
                        entrada.coluna--;
                    }
                }

                else{
                    entrada.coluna--;
                }

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
    if(caverna->MatrixVisitados[caverna->saida.linha][caverna->saida.coluna]){
        return true;
    }

    return false;
}

//caminho nao achado escreve arquivo com uma frase
void escreveArquivoSemCaminho(int* numCaverna){
    char nomeFile[250];
    char ch[2];
    FILE* file;

    strcpy(nomeFile, "./arquivosResultados/resultado");

    sprintf(ch, "%d", (*numCaverna));
    
    strcat(nomeFile, ch);
    strcat(nomeFile, ".txt");
    
    file = fopen(nomeFile, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeFile);
        return;
    }

    fprintf(file, "Caverna sem caminho possivel\n");


    fclose(file);
}

void escreveArquivo(PProgDinamica programa, int* numCaverna) {
    char nomeFile[250];
    char ch[2];
    FILE* file;

    strcpy(nomeFile, "./arquivosResultados/resultado");

    sprintf(ch, "%d", (*numCaverna));
    
    strcat(nomeFile, ch);
    strcat(nomeFile, ".txt");
    
    file = fopen(nomeFile, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeFile);
        return;
    }

    for (int i = programa->tamCaminho-1; i >= 0; i--){
        fprintf(file, "%d %d\n", programa->vetParOrdenado[i].linha, programa->vetParOrdenado[i].coluna);
    }

    fprintf(file, "%d %d\n", programa->caverna->saida.linha, programa->caverna->saida.coluna);

    fclose(file);
}

void descobreCaminho(PProgDinamica programa, int* numCaverna){ // descobrir o caminho

    criarVetorParOrdenado(programa);

    TipoParOrdenado saida, entrada;
    saida.linha = programa->caverna->saida.linha;
    saida.coluna = programa->caverna->saida.coluna;
    entrada.linha = programa->caverna->entrada.linha;
    entrada.coluna = programa->caverna->entrada.coluna;

    int i = saida.linha, j = saida.coluna;
    for (int c = 0; c < programa->tamCaminho; c++){
        
        if (i+1 <= entrada.linha && j+1 > entrada.coluna){
            programa->vetParOrdenado[c].linha = i + 1;     programa->vetParOrdenado[c].coluna = j; 
            i++;
        }

        else if (i+1 > entrada.linha && j+1 <= entrada.coluna){
            programa->vetParOrdenado[c].linha = i;         programa->vetParOrdenado[c].coluna = j + 1; 
            j++;
        }

        else if (i+1 <= entrada.linha && j+1 <= entrada.coluna){
            if (programa->caverna->MatrixDinamica[i + 1][j] > programa->caverna->MatrixDinamica[i][j + 1]) {
                programa->vetParOrdenado[c].linha = i + 1;     programa->vetParOrdenado[c].coluna = j; 
                i++;
            }

            else{
                programa->vetParOrdenado[c].linha = i;         programa->vetParOrdenado[c].coluna = j + 1; 
                j++;
            }
        }
    }
    escreveArquivo(programa, numCaverna);
    
}

void limparVetParOrdenado(PParOrdenado vetParOrdenado){
    free(vetParOrdenado);
}
