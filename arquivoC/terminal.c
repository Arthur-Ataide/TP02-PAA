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
    
    char file_path[250];
    char ch[2];
    
    do{
        printf("\nDigite o caminho do arquivo: (apenas o numero da caverna)\n");

        strcpy(file_path, "./cavernaGeradora/");
        strcat(file_path, "caverna");

        sprintf(ch, "%d", numCaverna);
        
        strcat(file_path, ch);
        strcat(file_path, ".txt");
        
        printf("\nArquivo: %s\n", file_path);

        *f = fopen(file_path, "r");

        if(*f == NULL){
            printf("\nArquivo nao encontrado\n\n");
            pausarLimparTela();
        }

        else{
            printf("\nArquivo encontrado!!!\n\n");
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
                descobreCaminho(&programa);
            }

            else
                printf("\nNao existe caminho possivel\n");
            
            limparCaverna(programa.caverna);
        }

        else
            printf("\nNao existe caminho possivel\n");
        
    }

}
