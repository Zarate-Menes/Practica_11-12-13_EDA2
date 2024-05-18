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


