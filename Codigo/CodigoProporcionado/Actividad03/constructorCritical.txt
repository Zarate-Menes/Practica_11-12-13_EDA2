
/*CONSTRUCTOR CRITICAL*/

/*Para esta explicacion usaremos este ejemplo*/
/*Se parte del ejemplo que se requiere buscar el valor maximo en un arreglo
usando hilos, para eso se divide el arreglo en parte con las cuales trabajara
cada hilo*/

//Primera forma de buscar el valor max en un arreglo con hilos
int buscarMaximo(int *a, int n){
    int max, i;
    max = a[0];

    #pragma omp parallel
    {
        #pragma omp for
        {
            for(i=1; i<n; i++){
                if(a[i]>max){
                    max = a[i];
                }
            }
        }
    }

    return max;
}


//Segundo forma de buscar el valor max en un arreglo con hilos
int buscarMaximo(int *a, int n){

    int max, i;
    max = a[0];

    #pragma omp parallel for
    {
        for(i=1; i<n; i++){
            if(a[i]>max){
                max = a[i];
            }
        }
    }

    return max;
}


// Como ambos codigo comparte una sola variable, podria pasar que
// un hilo puede actualizar el valor con un valor menor al que otro 
// hilo lo hizo por lo tanto se obtien el siguiente codigo

// Tercera forma de buscar el valor max en un arreglo con hilos
int buscarMaximo(int *a, int n){

    int max, i;
    max = a[0];

    #pragma omp parallel for
    {
        for(i=1; i<n; i++){
            #pragma omp critical
            {
                if(a[i]>max){
                    max = a[i];
                }
            }
            
        }
    }

    return max;
}


