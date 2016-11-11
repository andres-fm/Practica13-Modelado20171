#include <stdio.h> 
#include <time.h> 
#include <stdlib.h>
/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){
	//inicializo el generador num aleatorios
	srand(time(NULL));
	int *array = (int*)malloc(sizeof(int) * num);
	int i;
	//lleno el arreglo con numeros aleatorios
	for(i = 0; i < num; i++){
	   	//La función rand regresa un numero aleatorio (hago modulo 100 para que este entre 0 y 99)
		array[i] = rand() % (max-min+1) + min;
	}
	return array;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){
	//inicializo el generador num aleatorios
	srand(time(NULL));
	double *array = (double*)malloc(sizeof(double) * num);
	int i;
	//lleno el arreglo con numeros aleatorios
	for(i = 0; i < num; i++){
	   	double random_number = (double)rand()/RAND_MAX*max + min; //numero entre min y max+min
	   	//si el generado fue mayor que max tomo max, en otro caso tomo el generado
		array[i] = ((random_number > max) ? max : random_number); 
	}
	return array;
}