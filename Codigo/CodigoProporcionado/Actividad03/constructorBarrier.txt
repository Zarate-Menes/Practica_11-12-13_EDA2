
/*CONSTRUCTOR BARRIER*/

/*Ente constructor se usa cuando el resultado de algun hilo se requiere
en el proceso de otro hilo diferente, en ese caso el segundo hilo se
pone en espera, hasta que el primer hilo termine su tarea*/

// Usamos barrier para que sincronizar hilos en etapas del progama donde
// se necesiten SINTAXIS


void ejemplo(){

    #pragma omp parallel shared(A,B,C)
    {
        realizarUnTrabajo(A,B);
        printf("Procesando A y B\n");

        #pragma omp barrier //esperan
        {
            realizarUnTrabajo(B,C);
            printf("Procesando B y C\n");
        }
    }
}



