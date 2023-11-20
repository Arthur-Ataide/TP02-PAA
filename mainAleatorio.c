#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int vida, tamI, tamJ;

    printf("Digite a vida do jogador: ");
    scanf("%d", &vida);

    printf("Digite o tamanho de linhas caverna: ");
    scanf("%d", &tamI);

    printf("Digite o tamanho de colunas caverna: ");
    scanf("%d", &tamJ);

    srand(time(NULL));

    int finalI = rand() % tamI;
    int finalJ = rand() % tamJ;

    int inicioI;
    int inicioJ;

    if(rand() % 2 == 0){
        if (rand() % 2 == 0) // randomiza para verificar em qual ponta da matriz vai ficar
            inicioI = 0;
        else
            inicioI = tamI-1;

        inicioJ = (rand() % (tamJ-finalJ)) + finalJ; // diminuir a chance de nao encontrar caminho
    }

    else{
        inicioI = (rand() % (tamI-finalI)) + finalI;// diminuir a chance de nao encontrar caminho

        if (rand() % 2 == 0) // randomiza para verificar em qual ponta da matriz vai ficar
            inicioJ = 0;
        else
            inicioJ = tamJ-1;
    }
    
    FILE* file = fopen("./cavernaGeradora/caverna100.txt", "w");

    fprintf(file, "%d %d %d\n", tamI, tamJ, vida);

    for (int i = 0; i < tamI; i++){
        for (int j = 0; j < tamJ; j++){
            if (i == finalI && j == finalJ){
                fprintf(file, "F ");
            }
            else if (i == inicioI && j == inicioJ){
                fprintf(file, "I ");
            }
            else{
                if (rand() % 2 == 0) // se vai ser negativo ou positivo
                    fprintf(file, "%d ", rand() % vida);
                
                else
                    fprintf(file, "%d ", -(rand() % vida));
            }

        }
        fprintf(file, "\n");
    }

    fclose(file);


    return 0;
}
