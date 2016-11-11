#include "b_sort.h"

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
            int (*compar)(const void*, const void*)){
	// como el tamaño en bytes de char es 1, podre iterar sobre el arreglo facilmente (utilizando aritmetica de 
	// apuntadores) dado que conozco el tamaño en bytes de cada elemento del arreglo (size, recibido como argumento)
	char* array = (char*)base;
	// apuntador void auxiliar de tamaño size para hacer el swap de los elementos usando memcpy
	void* aux = calloc(1, size);
	//bandera para saber si seguir iterando
	int swaps;
    //declaro el entero i para iterar sobre el arreglo
	int i;
	//bucle do while, itera mientras haya al menos un intercambio durante la iteracion
	do{
		//inicialmente no hay intercambios
		swaps = 0;
		//bucle for para iterar sobre el arreglo
		for(i = 0; i < num-1; i++){
			// apuntador a void del elemento actual sobre el que itero
			void* current_el = array + size*i;
			// apuntador a void del elemento siguiente sobre el que itero
			void* next_el = array + size*(i + 1);
			//si  el elemento siguiente al que apunta el indice actual es mayor, intercambio los elementos
			if ((*compar)(current_el, next_el) > 0){
				// hago swap de los valores
				// a la variable auxiliar le asigno la informacion del elemento actual
				memcpy(aux, current_el, size);
				// al elemento actual le asigno la informacion del elemento siguiente
            	memcpy(current_el, next_el, size);
            	// al elemento siguiente le asigno el valor de la variable auxiliar 
            	//(que contiene el valor original del elemento actual)
            	memcpy(next_el, aux, size);
            	//como si intercambie, la bandera es verdadera
				swaps = 1;
			} 
		}
	}while(swaps);
	//libero la memoria que ocupaba el auxiliar
	free(aux);
}