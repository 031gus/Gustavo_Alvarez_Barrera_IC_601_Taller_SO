/*Ejercicico1:

1.- //---->crear un array de tipo entero de tamaño 5 de nombre "arrayInt"
2.- //---->inicializar el array "arranyInt" de 0 a 5, con una estructura repetitiva
	//---> es decir: arrayInt[0] = 0, arrayInt[1] = 1, arrayInt[2] = 2...
3.-//---->crear un puntero hacia un entero de nombre "punteroInt" e inicializarlo con "arrayInt"
4.-//---->crear un puntero hacia un entero de nombre "punteroIntDos" e inicializarlo con la direccion del primer elemento (index) del array "arrayInt"
5.-//---->imprimir el contenido del primer contenido del primer elemento del "arrayInt"
6.- //imprimir el contenido del primer elemento del puntero "punteroInt"
7.- //imprimir el primer contenido del elemento del puntero "punteroIntDos"
8.- //imprimir el contenido del quito elemento del array "arrayInt"
9.- //imprimir el contenido del quinto elemento del puntero "punteroInt" con aritmetica de punteroIntDos
10.-// imprimir el contenido del quinto elemento del puntero "punteroIntDos" con aritmetica de punteros 
11.- //imprimir el contenido de todos los elementos del puntero "punteroInt" usar una estructura repetitiva
12.- //imprimir el contenido de todos los elementos del puntero "punteroIntDos" con aritmetica de punteros, usar una estructura repetitiva*/

#include<stdio.h>

int main(){

	int arrayInt[5];
	for (int i =0; i<5;i++){
		arrayInt[i] =i;
		printf("i : %i\n",i );
	}
	int *punteroInt = arrayInt;
	int *punteroIntDos = &arrayInt[0];
	printf("el primer elemento de arrayInt es: %i\n",arrayInt[0] );
	printf("el primer contenido de primer punteroInt es: %i\n",punteroInt );
	printf("el primer elemento del punteroIntDos es: %i\n",punteroIntDos );
	printf("el quinto elemento de arrayInt es: %i\n",arrayInt[4] );
	printf("el quinto elemento del punteroInt es: %i\n",punteroInt+4 );
	printf("el quinto elemento del punteroIntDos%i\n",punteroIntDos+4 );
	for(int i=0;i<5;i++){
		*punteroInt++;
		printf("punteroInt :%i\n",punteroInt );
	}
	for(int i=0;i<5;i++){
		*punteroIntDos++;
		printf("punteroIntDos :%i\n",punteroIntDos );
	}
}