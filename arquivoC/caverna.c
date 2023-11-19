#include "../headers/caverna.h"

void teste(){ // so para testar onde esta o erro
    printf("\n\nteste\n\n");
}

void mostrarAtributos(PCaverna caverna){
    puts("\nAtributos da caverna:");
    printf("Tamanho: %d %d\n", caverna->tam.linha, caverna->tam.coluna);
    printf("Vida: %d\n", caverna->vida);
    printf("Entrada: %d %d\n", caverna->entrada.linha, caverna->entrada.coluna);
    printf("Saida: %d %d\n", caverna->saida.linha, caverna->saida.coluna);
    puts("\n");
}

void linha(int tam, bool poder){

    for (int i = 0; i < 2*(tam)+2; i++) {

        if (poder){
            printf("\033[46m  \033[0m");
        }
        else
            printf("\033[41m  \033[0m");
        
    }

    puts("");
}

void coluna(int tam, bool poder){
    
    if (poder){
        printf("\033[46m  \033[0m");
    }
    else 
        printf("\033[41m  \033[0m");

}

void grafico(char identificador, char bloco){
    if (identificador == 'I'){
        printf("\033[47m  \033[0m");
    }

    else if (identificador == 'F'){
        printf("\033[47m  \033[0m");
    }

    else if (identificador == 'N'){
        if (bloco > 0){
            printf("\033[43m  \033[0m");
        }

        else if (bloco < 0){
            printf("\033[46m  \033[0m");
        }

        else {
            printf("\033[42m  \033[0m");
        }
    }
}

void mostrarCaverna(PCaverna caverna){
    bool poder = false;
    
    linha(caverna->tam.coluna, poder);

    for(int i = 0; i < caverna->tam.linha; i++) {
        for (int c = 0; c < 2; c++){
            for(int j = 0; j < caverna->tam.coluna; j++){
                if (j == 0) {
                    coluna(caverna->tam.coluna, poder);
                }

                // if (movimento)
                //     grafic(caverna->MatrixMovimento[i][j]);
                
                // else 
                    if (caverna->entrada.linha == i && caverna->entrada.coluna == j){
                        grafico('I', caverna->Matrix[i][j]);
                        grafico('I', caverna->Matrix[i][j]);
                    }
                    
                    else if (caverna->saida.linha == i && caverna->saida.coluna == j){
                        grafico('F', caverna->Matrix[i][j]);
                        grafico('F', caverna->Matrix[i][j]);
                    }
                    
                    else{
                        grafico('N',caverna->Matrix[i][j]);
                        grafico('N',caverna->Matrix[i][j]);
                    }
                


                if (j == caverna->tam.coluna - 1) {
                    coluna(caverna->tam.coluna, poder);
                }
            }
            puts("");
        }
    }

    
    linha(caverna->tam.coluna, poder); 

}

void mostrarMatrix(PCaverna caverna){
    puts("\nMatrix Dinamica");
    for(int i = 0; i < caverna->tam.linha; i++){
        for(int j = 0; j < caverna->tam.coluna; j++){
            printf("%d ", caverna->MatrixDinamica[i][j]);
        }
        puts("");
    }
    
    puts("\n");
    
    puts("\nMatrix Visitados");
    
    for(int i = 0; i < caverna->tam.linha; i++){
        for(int j = 0; j < caverna->tam.coluna; j++){
            if(caverna->MatrixVisitados[i][j])
                printf("1 ");
            else
                printf("0 ");
        }
        puts("");
    }
}

void atributos(FILE *f, PCaverna caverna){
    fscanf(f, "%d %d", &(caverna->tam.linha), &(caverna->tam.coluna));
    fscanf(f, "%d", &(caverna->vida));
}

PCaverna geradorCaverna(FILE* f){
    int readInt;
    char readChar;

    PCaverna caverna = (PCaverna) malloc(sizeof(TipoCaverna));


    atributos(f, caverna);

    caverna->Matrix = (int**) malloc(sizeof(int*) * caverna->tam.linha);
    caverna->MatrixDinamica = (int**) malloc(sizeof(int*) * caverna->tam.linha);
    caverna->MatrixVisitados = (bool**) malloc(sizeof(bool*) * caverna->tam.linha);

    int tamanhoTotal = caverna->tam.linha * caverna->tam.coluna;

    // for (int i = 0; i < caverna->tam.linha; i++) {
    //     caverna->Matrix[i] = (int*)malloc(sizeof(int) * caverna->tam.coluna);
    //     caverna->MatrixDinamica[i] = (int*)malloc(sizeof(int) * caverna->tam.coluna);
    //     caverna->MatrixVisitados[i] = (bool*)malloc(sizeof(bool) * caverna->tam.coluna);
        
    //     for (int j = 0; j < caverna->tam.coluna; j++){
    //         caverna->MatrixVisitados[i][j] = false;
    //         caverna->MatrixDinamica[i][j] = 0;
    //     }
        
    // }

    caverna->Matrix[0] = (int*)malloc(sizeof(int) * tamanhoTotal);
    caverna->MatrixDinamica[0] = (int*)malloc(sizeof(int) * tamanhoTotal);
    caverna->MatrixVisitados[0] = (bool*)malloc(sizeof(bool) * tamanhoTotal);
    for (int j = 0; j < caverna->tam.coluna; j++){
        caverna->MatrixVisitados[0][j] = false;
        caverna->MatrixDinamica[0][j] = 0;
    }


    for (int i = 1; i < caverna->tam.linha; i++) {
        caverna->Matrix[i] = caverna->Matrix[0] + i * caverna->tam.coluna;
        caverna->MatrixDinamica[i] = caverna->MatrixDinamica[0] + i * caverna->tam.coluna;
        caverna->MatrixVisitados[i] = caverna->MatrixVisitados[0] + i * caverna->tam.coluna;
        for (int j = 0; j < caverna->tam.coluna; j++){
            caverna->MatrixVisitados[i][j] = false;
            caverna->MatrixDinamica[i][j] = 0;
        }
        
    }

    // memset(caverna->MatrixVisitados, false, sizeof(caverna->MatrixVisitados));
    
    // for (int i = 0; i < caverna->tam.linha; i++)
    //     for (int j = 0; j < caverna->tam.coluna; j++)
    //         caverna->MatrixVisitados[i][j] = false;

    // mostrarMatrix(caverna);
    // pausarLimparTela();

    

    for(int i = 0; i < caverna->tam.linha; i++){
        for(int j = 0; j < caverna->tam.coluna; j++){
            
            if (fscanf(f, "%d", &readInt) == 1)
                caverna->Matrix[i][j] = readInt;
            
            else {
                if(fscanf(f, "%c", &readChar) == 1 & (readChar == 'I' || readChar == 'F')){
                    
                    if (readChar == 'I'){
                        caverna->entrada.linha = i;
                        caverna->entrada.coluna = j;
                    }

                    else if (readChar == 'F'){
                        caverna->saida.linha = i;
                        caverna->saida.coluna = j;
                    }

                    caverna->Matrix[i][j] = 0;
                }
            }
        }
    }

    return caverna;
}

void limparCaverna(PCaverna caverna){
    
    for(int i = 0; i < caverna->tam.linha; i++){
        free(caverna->Matrix[i]);
        free(caverna->MatrixDinamica[i]);
        free(caverna->MatrixVisitados[i]);
    }
    
    free(caverna->Matrix);
    free(caverna->MatrixDinamica);
    free(caverna->MatrixVisitados);
    free(caverna);
}
