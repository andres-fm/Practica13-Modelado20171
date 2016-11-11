#ifndef ARREGLOS_RANDOM_H
#define ARREGLOS_RANDOM_H
//para poder hacer uso de malloc, sizeof y (s)rand
#include <stdlib.h>
//para poder generar numeros, aleatorios. Inicializar una semilla
#include <time.h>

                     
/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max);

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max);

#endif // ARREGLOS_RANDOM_H