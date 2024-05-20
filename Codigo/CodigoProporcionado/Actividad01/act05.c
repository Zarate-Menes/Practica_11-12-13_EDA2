#include<stdio.h>
#include<omp.h>

int main(){

    int tid; 
    int nth;

    #pragma omp parallel private(tid)
    {

        tid = omp_get_thread_num();
        nth = omp_get_num_threads();
        printf("Hola mundo desde el hilo %d de un total de %d\n", tid,nth);
    }
    printf("Adios\n");

    return 0;
}


