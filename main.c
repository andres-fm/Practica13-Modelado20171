/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"
//para entrada y salida estandar (hago uso de printf)
#include <stdio.h>

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 100);
    double *arr2 = arreglo_double(20, 0, 100);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    printf("\n");
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);
    printf("\n");

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    printf("\n");
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);
    return 0;
}

// función que compara dos enteros
int cmp_int(const void *a, const void *b){
    // casting a los apuntadores para obtener sus valores enteros
    const int *ia = (const int *) a;  
    const int *ib = (const int *) b;
    // si ia > ib se regresa entero mayor que 0, si son iguales 0 y en otro caso menor que 0
    return *ia  - *ib; 
}

// función que compara dos doubles
int cmp_double(const void *a, const void *b){
    // casting a los apuntadores para obtener sus valores doubles
    const double *ia = (const double *) a;  
    const double *ib = (const double *) b;
    //si son iguales regreso 0
    if(*ia == *ib)
        return 0;
    // si ia > ib se regresa 1, en otro caso -1
    return ((*ia > *ib) ? 1 : -1);
}
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num){
    //itero sobre el arreglo e imprimo elementos
    for(int i = 0; i < num; i++)
        printf("%d  ", arreglo[i]);
}
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num){
    //itero sobre el arreglo e imprimo elementos
    for(int i = 0; i < num; i++)
        printf("%f  ", arreglo[i]);
}