#include "../headers/terminal.h"

void lerArquivo(FILE** f){
    
    char file_path[250];
    char ch[2];
    
    do{
        printf("\nDigite o caminho do arquivo: (apenas o numero da caverna)\n");

        strcpy(file_path, "./cavernaGeradora/");
        strcat(file_path, "caverna");

        scanf("%s", ch);
        
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

    FILE* f;
    PCaverna caverna;
    // TipoRecursividade rec;

    int opcao = -1;
    int cavernaCriada = 0;
    int caminhosJaVistos = 0;

    while (opcao){

        // printar menu

        printf("\n1 - Ler arquivo e gerar mapa\n2 - Gerar mapa aleatorio\n3 - Printar atributos do mapa\n4 - Printar mapa\n5 - Achar o menor caminho\n/* 6 - Tentar achar algum caminho possivel sozinho*/\n0 - Sair\n");
        
        scanf("%d", &opcao);
        limparTela();

        switch (opcao){

            case 1:
                // if (caminhosJaVistos)
                //     freeCaminhos(map->caminhosPossiveis->proxCaminho);

                if (cavernaCriada)
                    limparCaverna(caverna);
                
                lerArquivo(&f);

                caverna = geradorCaverna(f);
                // generateRec(&rec);

                fclose(f);
                
                cavernaCriada = 1;
                caminhosJaVistos = 0;
                break;
            
            // case 2:
            //     limparInput();
                
            //     // if (caminhosJaVistos)
            //     //     freeCaminhos(map->caminhosPossiveis->proxCaminho);

            //     if (cavernaCriada)
            //         freeCaverna(caverna);
        
            //     caverna = generateCavernaAleatoria();
            //     // generateRec(&rec);
            //     // printf("\nMapa aleatorio foi gerado, para ver seus atributos selecione 3\n");
            //     cavernaCriada = 1;
            //     caminhosJaVistos = 0;
            //     break;

            case 3:
                if(cavernaCriada){
                    mostrarAtributos(caverna);
                    break;
                }

            case 4:
                if(cavernaCriada){
                    mostrarCaverna(caverna);
                    break;
                }

            // case 5:
            //     if(cavernaCriada){
            //         procurarCaminho(caverna->Matrix);
            //         break;
            //     }

            // case 6:
            //     if(mapCriado){
            //         chaminharUsuario(map);
            //         break;
            //     }

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;

            case 0:
                // if (caminhosJaVistos)
                //     freeCaminhos(map->caminhosPossiveis->proxCaminho);

                if (cavernaCriada)
                    limparCaverna(caverna);
                
                // endwin();

                exit(0);
                    
            
        }
        pausarLimparTela();
    }
    
}

