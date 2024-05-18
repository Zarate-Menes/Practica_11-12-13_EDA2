#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 10

void llenarArreglo(int *a);
void suma(int *a, int *b, int *c);

int main(){

    int max, *a, *b, *c;

    a = (int *)malloc(sizeof(int)*n);
    b = (int *)malloc(sizeof(int)*n);
    c = (int *)malloc(sizeof(int)*n);

    llenarArreglo(a);
    llenarArreglo(b);

    suma(a, b, c);

    return 0;
}


void llenarArreglo(int *a){

    int i;
    for(i=0; i<n; i++)
    {
        a[i] = rand()%n;
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void suma(int *A, int *B, int *C){

    int i;

    for(i=0; i<n; i++)
    {
        C[i] = A[i]+B[i];
        printf("%d\t", C[i]);
    }
}


