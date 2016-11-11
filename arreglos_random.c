//para poder generar numeros aleatorios
#include "arreglos_random.h"
/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){
	//inicializo el generador de num aleatorios
	srand(time(NULL));
	//regresa un apuntador a la seccion de memoria del tamaño especificado, 
	//hago cast a int pointer y lo asigno a array	
	int *array = (int*)malloc(sizeof(int) * num);
	//declaro una variable para iterar
	int i;
	//lleno el arreglo con numeros aleatorios
	for(i = 0; i < num; i++){
	   	//La función rand regresa un numero aleatorio 
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
	//regresa un apuntador a la seccion de memoria del tamaño especificado,
	//hago cast a double pointer y lo asigno a array
	double *array = (double*)malloc(sizeof(double) * num);
	//declaro una variable para iterar
	int i;
	//lleno el arreglo con numeros aleatorios
	for(i = 0; i < num; i++){
	   	double random_number = (double)rand()/RAND_MAX*max + min; //numero entre min y max+min
	   	//si el generado fue mayor que max tomo max, en otro caso tomo el generado
		array[i] = ((random_number > max) ? max : random_number); 
	}
	return array;
}