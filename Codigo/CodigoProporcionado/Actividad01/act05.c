#include<stdio.h>
#include<omp.h>

int main(){

    int tid, nth;

    #pragma omp parallel //private(tid)
    {
        tid = omp_get_thread_num();
        nth = omp_get_num_threads();
        printf("Hola mundo desde el hilo %d de un total de %d\n", tid,nth);
    }
    printf("Adios\n");
    return 0;
}


/*Para cambiar el numero de hilos desde consola

export OMP_NUM_THREADS=n

*/


