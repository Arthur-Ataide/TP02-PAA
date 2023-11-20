#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    FILE* file = fopen("./selecaoDeCavernas/selecao.txt", "w");
    
    int caverna = 1;
    
    while (caverna > 0){
        printf("Digite alguma caverna valida / um numero <= 0 para parar!\n");
        
        scanf("%d", &caverna);
        if (caverna > 0)
            fprintf(file, "%d\n", caverna);
        
    }

    fclose(file);

    return 0;
}
