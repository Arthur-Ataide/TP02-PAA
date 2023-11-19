#include "./headers/terminal.h"

int main() {

    clock_t start_time = clock();

    menu();
    
    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf segundos\n", elapsed_time);
    return 0;

}
