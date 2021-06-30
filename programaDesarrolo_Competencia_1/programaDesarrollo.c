#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

int main(){

	//Declaración de variables necesarias.
	int proc=3; //Numero de procesos.
	bool tareasPend; //Regresa true o false dependiendo de si hay tareas por ejecutar.
	int id[proc]; //Identificador del proceso. Ej Proceso 0
	int Total_Tareas[proc]; //Numero total de tareas de cada proceso.
	int i; //Variable para hacer iteraciones.

	//Ciclo for que asigna los identificadores y el numero de tareas por proceso.
	for(i = 0; i < proc;i++){

		id[i] = i;
		Total_Tareas[i] = rand() % 10; //Valor aleatorio asignado del 0 al 10;

	}

	//Ciclo for para verificar que haya o no tareas pendientes. Devuelve true o false en cada caso.
	for(i = 0; i < proc; i++){

		if(Total_Tareas[i] > 0){

			//tareasPend = 1;
			tareasPend = true;
			//Bucle que ejecuta las tareas de cada proceso mientras haya tareas pendientes.
			while(tareasPend){

				tareasPend = false;

				//Ciclo que imprime el numero de tareas restantes de cada proceso.
				for(i=0; i< proc;i++){

					if(Total_Tareas[i] > 0){
						printf("El proceso %i tiene un total de %i tareas suspendidas de ejecucion\n", id[i], Total_Tareas[i]);
						delay(2);
						tareasPend = true;

					}

					Total_Tareas[i] -= 1; //Ejecucion de las tareas de un proceso. En cada iteracion se ejecuta una sola tarea de cada proceso.

					if(Total_Tareas[i] <=0){

						printf("Proceso %i completado.\n", id[i]);
					}
				}
			}
		} else{

			printf("\nSin procesos por ejecutar.\n");
			tareasPend = false;
		}
	}


	printf("\nFin de programa\n");
	return 0;
}
