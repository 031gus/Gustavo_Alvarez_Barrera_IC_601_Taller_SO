//Ejercicico1:

//1.- //----> Definir una variable de tipo entero de nombre "x", crear un puntero hacia un entero de nombre "p"
//2.- //---->definir una variable de nombre "y", crear un puntero hacia un entero de nombre puntero.
//3.- // ----> inicializar la variable "X" con el valor 10
//4.- // --->asignar la direccion en memoria de la variable "x" al puntero "p"
//5.- //--->imprimir el contenido del puntero "p"
//6.- //--->sumar 1 al contenido del puntero "p" y almacenar en le mismo puntero "p"
//7.- //--->imprimir el contenido del puntero "p"
//8.-//---->sumar 1 al contenido del puntero "p" y almacenar en le mismo puntero "p"
//9.-//---->imprimir el contenido del puntero "p"
//10.-//---->inicializar la variable "y" con valor 20
//11.- //--->asignar la direccion en memoria de la variable "y" al puntero puntero
//12.- //--->imprimir el contenidodel puntero "puntero"

#include<stdio.h>

int main(){


	int x;
	int *p;
	int y;
	int *puntero;
		x=10;
		p =&x;
		printf("el valor de p es :%i\n",p);
		p += 1;
		printf("el valor de p es :%i\n",p);
		p += 2;
		printf("el valor de p es :%i\n",p);
		y = 20;
		puntero =&y;
		printf("el valor de puntero es :%i\n",puntero);




}


