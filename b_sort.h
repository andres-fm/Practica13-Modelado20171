#ifndef B_SORT_H_   /* Protección del Include*/
#define B_SORT_H_

//para tener acceso a memcpy y poder hacer el swap en bubble sort
#include <string.h>
//para poder hacer uso de malloc
#include <stdlib.h>

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size,
            int (*compar)(const void*, const void*));

#endif // B_SORT_H_