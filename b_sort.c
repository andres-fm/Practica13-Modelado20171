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
            int (*compar)(const void*, const void*)){


	int swaps;
    //declaro el entero i para iterar sobre el arreglo
	int i;
	//bucle do while, itera mientras haya al menos un intercambio durante la iteracion
	do{
		//inicialmente no hay intercambios
		swaps = 0;
		//bucle for para iterar sobre el arreglo
		for(i = 0; i < num-1; i++){
			//si  el elemento siguiente al que apunta el indice actual es mayor, intercambio los elementos
			if ((*compar)((int*)base + i, (int*)base+i+1) > 0){
				//asigno a un entero auxiliar el valor a intercambiar
				int aux = *((int*)base+i);
				//asigno el valor del elementos siguiente al elemento actual
				*((int*)base + i) = *((int*)base + i + 1);
				//al elemento siguiente le asigno el valor que originalmente tenia el elem actual
				*((int*)base + i + 1) = aux;
				//como si hubo intercambio, la bandera es verdadera
				swaps = 1;
			} 
		}
	}while(swaps);


}