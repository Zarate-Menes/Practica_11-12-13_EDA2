
/*CLAUSULA REDUCTION*/

/*Para esta explicacion saremos este ejemplo*/
/*Se parte del ejemplo que se quiere obtener el producto punto
entre dos vectores de n elementos, para eso se divide el arreglo 
en parte con las cuales trabajara cada hilo*/

// Primera forma de obtener el producto punto de vectores sin hilos
double prodPunto(double *a, double *b, int n){
    
    double res = 0;
    int i;

    for(i=0; i<n, i++){
        res += a[i]*b[i];
    }

    return res;
}


// Para usar hilos en este proceso usamos un proceso similar para 
// saber el valor maximo de un arreglo, dividimos las sumas de las 
// multiplicaciones en varios hilos

// Segunda forma de obtener el producto punto de vectores con hilos
double prodPunto(double *a, double *b, int n){

    double res = 0;
    int i;

    #pragma omp parallel for
    for(i=0; i<n; i++){
        res += a[i]*a[i];
    }

    return res;
}


// Con el codigo anterior se resuelve el problema pero como seguimos
// usando una sola varable res para almacenar varios valores con 
// diferentes hilos estos no se suman si no que se reescriben

// Tercera forma de obtener el producto punto de vectores con hilos
double prodPunto(double *a, double *b, int n){

    double res = 0, resp[n_hilos];
    int i, tid, nth;

    #pragma omp parallel private(tid) nthreads(n_hilos)
    {
        tid = omp_get_thread_num;
        resp[tid] = 0;

        #pragma omp for
        for(i=0; i<n; i++){
            resp[tid] += a[i]*a[i];
        }


        if(tid == 0){
            nth = omp_get_threads();
            for(i=0; i<n; i++){
                res += resp[i];
            }
        }
           
    }

    return res;
}


// Ahora en lugar de usar un arreglo para almacenar varios resultados
// utilizamos la cláusula reduction. Lo que hace esta clausula en tomar
// los resultados de aportados por cada hilo y usar la operacion sobre
// ellos mismos para obtener un solo valor.

//Cuarta forma de obneter el producto punto de vectores con hilos
double prodPunto(double *a, double *b, int n){

    double res = 0;
    int i;

    #pragma omp parallel for reduction(+:res)
    for(i=0; i<n; i++){
        res += a[i]*b[i];
    }

}



/* Alguno operadores que puedes utilizar con la clausula reduction

  TODAS ESTAS OPERACIONES SE CONOCEN COMO:

        OPEREACIONES DE REDUCCIÓN 

    Operador        Valor inicial
        +               0
        -               1
        *               0
        ^               0
        &               0
        |               0
        &&              1
        ||              0
        min y max   

*/