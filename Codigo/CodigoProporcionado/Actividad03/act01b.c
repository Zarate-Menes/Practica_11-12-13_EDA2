
/* 
    Buscar el valor maximo en un arreglo
    
    Version paralela
*/

#include <stdio.h>

void buscarMax(void);


int main(){

    int arreglo[80] = {
        17, 3, 45, 12, 56, 78, 32, 1, 15, 22, 64, 28, 53, 7, 41, 66, 11, 73, 6, 35,
        18, 24, 39, 59, 2, 26, 44, 68, 31, 5, 77, 16, 21, 49, 70, 8, 62, 19, 58, 30,
        13, 4, 25, 63, 38, 52, 10, 33, 61, 20, 57, 72, 9, 47, 67, 36, 50, 74, 14, 40,
        29, 37, 65, 43, 23, 75, 54, 48, 27, 71, 80, 79, 42, 34, 76, 51, 60, 69, 46, 55
    };

    int tam = sizeof(arreglo) / sizeof(arreglo[0]);

    buscarMax(arreglo, tam);

    return 0;
}


void buscarMax(int arr[], int tam){

    int max = arr[0];

    #pragma omp parallel for
    for(int i=0; i<tam; i++){
        if(arr[i]>max) {
            #pragma omp critical
            {
                if(arr[i] > max)
                    max = arr[i];
            }
        }       
    }

    printf("El valor maximo es: %d\n", max);
}