#include "../headers/terminal.h"

void lerSelecao(int Selecao[10], int* quantidadeCavernas){
    char file_path[250];
    char ch[2];
    *quantidadeCavernas = 0;

    FILE* f = fopen("./selecaoDeCavernas/selecao.txt", "r");
    
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Ler e exibir o conteúdo do arquivo
    int numCaverna;

    while (fscanf(f, "%d", &numCaverna) == 1) {
        Selecao[*quantidadeCavernas] = numCaverna;
        (*quantidadeCavernas)++;
    }

    // Fechar o arquivo
    fclose(f);
}
    
void abrirCaverna(FILE** f, int numCaverna){
    
    char nomeFile[250];
    char ch[2];
    
    do{
        strcpy(nomeFile, "./cavernaGeradora/caverna");
        // strcat(nomeFile, "caverna");

        sprintf(ch, "%d", numCaverna);
        
        strcat(nomeFile, ch);
        strcat(nomeFile, ".txt");
        
        *f = fopen(nomeFile, "r");

        if(*f == NULL){
            printf("\nArquivo nao encontrado\n\n");
        }
    }

    while(*f == NULL);
}

void menu(){

    FILE* fileCaverna;
    TipoProgDinamica programa;
    int Selecao[10];
    bool caminhoPossivel;
    int quantidadeCavernas = 0;
    bool cavernaCriada = false;


    lerSelecao(Selecao, &quantidadeCavernas);

    for (int i = 0; i < quantidadeCavernas; i++){
        abrirCaverna(&fileCaverna, Selecao[i]);
        

        programa.caverna = geradorCaverna(fileCaverna);

        fclose(fileCaverna);

        cavernaCriada = true;
        caminhoPossivel = verificaPosicaoInicialFinal(programa.caverna);

        if(caminhoPossivel){
            caminhoPossivel = programacaoDinamica(programa.caverna);
            
            if(caminhoPossivel){
                descobreCaminho(&programa, &(Selecao[i]));
                limparVetParOrdenado(programa.vetParOrdenado);
            }

            else
                escreveArquivoSemCaminho(&(Selecao[i]));
        }

        else
            escreveArquivoSemCaminho(&(Selecao[i]));
        
        limparCaverna(programa.caverna);
    }

}
