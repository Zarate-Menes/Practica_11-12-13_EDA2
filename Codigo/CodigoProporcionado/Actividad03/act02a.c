
/* 
    Buscar el valor maximo en un arreglo

    Version secuencial
*/

#include <stdio.h>

void prodPunto(int vec1[], int vec2[], int tam);

int main(){

    int vec01[]= {
        12, 7, 19, 3, 8, 5, 14, 2, 17, 6, 11, 15, 9, 4, 1, 13, 10, 18, 20, 16,
        7, 3, 12, 5, 19, 2, 14, 8, 6, 11, 17, 4, 9, 15, 1, 10, 18, 13, 20, 16
    };

    int vec02[] = {
        1, 14, 7, 10, 3, 18, 9, 5, 20, 11, 4, 13, 6, 16, 2, 15, 19, 8, 12, 17,
        10, 4, 13, 7, 20, 5, 14, 2, 16, 1, 19, 9, 6, 15, 18, 8, 3, 11, 12, 17
    };

    int tam = sizeof(vec01) / sizeof(vec01[0]);

    prodPunto(vec01, vec02, tam);

    return 0;
}

void prodPunto(int vec1[], int vec2[], int tam){

    int val = 0;

    for(int i=0; i<tam; i++){
        val += vec1[i]*vec2[i];
    }

    printf("El producto puntod del vector 1 y el vector 2 es: %d\n", val);
}