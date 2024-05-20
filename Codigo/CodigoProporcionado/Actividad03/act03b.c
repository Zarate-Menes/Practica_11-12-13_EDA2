
/* 
    Aproximacion del numero pi atraves usando la regla del trapecio

    Version paralela 
*/

#include <stdio.h>
#include <omp.h>

long long num_steps = 100000000;
double step;
double empezar, terminar;

int main(int argc, char* argv[]){

    double x, pi, sum = 0.0;
    int i;

    step= 1.0/(double)num_steps;
    empezar = omp_get_wtime();

    #pragma omp for 
    for(i=0; i<num_steps; i++){
        x = (i + 0.5)*step;
            sum = sum + 4.0/(1.0 + x*x);
    }

    pi = sum*step;
    terminar=omp_get_wtime();

    printf("El valor de PI es: %15.12f\n", pi);
    printf("El tiempo de calculo del numero pi es: %1f segundos\n", terminar-empezar);

    return 0;
}