#include "../headers/terminal.h"

void lerArquivo(FILE** f){
    
    char file_path[250];
    char ch[2];
    
    do{
        printf("\nDigite o caminho do arquivo: (apenas o numero do mapa)\n");

        strcpy(file_path, "./mapGenerator/");
        strcat(file_path, "map");

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
    TipoCaverna* caverna;
    // TipoRecursividade rec;

    int opcao = -1;
    int cavernaCriada = 0;
    int caminhosJaVistos = 0;

    while (opcao){

        // printar menu

        // printf("\n1 - Ler arquivo e gerar mapa\n2 - Gerar mapa aleatorio\n3 - Printar atributos do mapa\n4 - Printar mapa\n5 - Achar o menor caminho\n6 - Tentar achar algum caminho possivel sozinho\n0 - Sair\n");
        
        scanf("%d", opcao);
        limparTela();

        switch (opcao){

            case 1:
                // if (caminhosJaVistos)
                //     freeCaminhos(map->caminhosPossiveis->proxCaminho);

                if (cavernaCriada)
                    freeCaverna(caverna);
                
                lerArquivo(&f);

                caverna = generateCaverna(f);
                // generateRec(&rec);

                fclose(f);
                
                cavernaCriada = 1;
                caminhosJaVistos = 0;
                break;
            
            case 2:
                limparInput();
                
                // if (caminhosJaVistos)
                //     freeCaminhos(map->caminhosPossiveis->proxCaminho);

                if (cavernaCriada)
                    freeCaverna(caverna);
        
                caverna = generateCavernaAleatorio();
                // generateRec(&rec);
                // printf("\nMapa aleatorio foi gerado, para ver seus atributos selecione 3\n");
                cavernaCriada = 1;
                caminhosJaVistos = 0;
                break;

            case 3:
                if(cavernaCriada){
                    printAtributos(caverna);
                    break;
                }

            case 4:
                if(cavernaCriada){
                    showCaverna(caverna);
                    break;
                }

            case 5:
                if(cavernaCriada){
                    procurarCaminho(caverna, &caminhosJaVistos);
                    break;
                }

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
                    freeCaverna(caverna);
                
                // endwin();

                exit(0);
                    
            
        }
        pausarLimparTela();
    }
    
}

