#include <stdio.h>

int main(){

    int i;
	#pragma omp parallel num_threads(3)
	{
		printf("Hola Mundo \n");

		for(i=0; i<10; i++){
			printf("Iteracion: %d \n", i);
        }
	}
	printf("\nAdios\n");

	return 0;
}

/*Para cambiar el numero de hilos desde consola

export OMP_NUM_THREADS=n

*/


