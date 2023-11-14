#include "../headers/caverna.h"

void teste(){ // so para testar onde esta o erro
    // printw("\n\nteste\n\n");
    printf("\n\nteste\n\n");
    // refresh();
}

void mostrarAtributos(PCaverna caverna){
    puts("\nAtributos da caverna:");
    printf("Tamanho: %d %d\n", caverna->tam.X, caverna->tam.Y);
    printf("Vida: %d\n", caverna->vida);
    printf("Entrada: %d %d\n", caverna->entrada.X, caverna->entrada.Y);
    printf("Saida: %d %d\n", caverna->saida.X, caverna->saida.Y);
    puts("\n");
}

void linha(int tam, bool poder){
    // if (poder)
    //     color(7);
    // else
    //     color(1);

    for (int i = 0; i < 2*(tam)+2; i++) {
        // printw("  ");

        if (poder){
            printf("\033[46m  \033[0m");
        }
        else
            printf("\033[41m  \033[0m");
        
        // refresh();
    }
    // if (poder)
    //     exitColor(7);
    // else  
    //     exitColor(1);

    // printw("\n");
    puts("");
    // refresh();
}

void coluna(int tam, bool poder){

    // if (poder)
    //     color(7);
    // else
    //     color(1);

    // printw("  ");
    
    if (poder){
        printf("\033[46m  \033[0m");
    }
    else 
        printf("\033[41m  \033[0m");

    // exitColor(7);
    // refresh();

    // if (poder)
    //     exitColor(7);
    // else  
    //     exitColor(1);

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
    
    linha(caverna->tam.Y, poder);

    for(int i = 0; i < caverna->tam.X; i++) {
        for (int c = 0; c < 2; c++){
            for(int j = 0; j < caverna->tam.Y; j++){
                if (j == 0) {
                    coluna(caverna->tam.Y, poder);
                }

                // if (movimento)
                //     grafic(caverna->MatrixMovimento[i][j]);
                
                // else 
                    if (caverna->entrada.X == i && caverna->entrada.Y == j){
                        grafico('I', caverna->Matrix[i][j]);
                        grafico('I', caverna->Matrix[i][j]);
                    }
                    
                    else if (caverna->saida.X == i && caverna->saida.Y == j){
                        grafico('F', caverna->Matrix[i][j]);
                        grafico('F', caverna->Matrix[i][j]);
                    }
                    
                    else{
                        grafico('N',caverna->Matrix[i][j]);
                        grafico('N',caverna->Matrix[i][j]);
                    }
                
                // refresh();


                if (j == caverna->tam.Y - 1) {
                    coluna(caverna->tam.Y, poder);
                }
            }
            // printw("\n");
            puts("");
            // refresh();
        }
    }

    
    linha(caverna->tam.Y, poder); 

}

void atributos(FILE *f, PCaverna caverna){
    fscanf(f, "%d %d", &(caverna->tam.X), &(caverna->tam.Y));
    fscanf(f, "%d", &(caverna->vida));
}

PCaverna geradorCaverna(FILE* f){
    int readInt;
    char readChar;

    PCaverna caverna = (PCaverna) malloc(sizeof(TipoCaverna));
    caverna->caminhosPossiveis = malloc(sizeof(TipoCaminho));
    caverna->caminhosPossiveis->proxCaminho = NULL;
    caverna->caminhosPossiveis->tamanho = 0;

    atributos(f, caverna);

    caverna->Matrix = (int**) malloc(sizeof(int*) * caverna->tam.X);

    for(int i = 0; i < caverna->tam.X; i++)
        caverna->Matrix[i] = (int*) malloc(sizeof(int) * caverna->tam.Y);
    
    for(int i = 0; i < caverna->tam.X; i++){
        for(int j = 0; j < caverna->tam.Y; j++){
            
            if (fscanf(f, "%d", &readInt) == 1)
                caverna->Matrix[i][j] = readInt;
            
            else {
                if(fscanf(f, "%c", &readChar) == 1 & (readChar == 'I' || readChar == 'F')){
                    
                    if (readChar == 'I'){
                        caverna->entrada.X = i;
                        caverna->entrada.Y = j;
                    }

                    else if (readChar == 'F'){
                        caverna->saida.X = i;
                        caverna->saida.Y = j;
                    }

                    caverna->Matrix[i][j] = 0;
                }
            }
        }
    }

    return caverna;
}

void limparCaverna(PCaverna caverna){
    for(int i = 0; i < caverna->tam.X; i++)
        free(caverna->Matrix[i]);
    
    free(caverna->Matrix);
    free(caverna);
}
