#include "scheduler.h"
#include <pthread.h>

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

//funciones para Pthreads
void *reproducirr_musica(void *args){ 
	printf("Reproduciendo musica\n");	
	return 0;
	}
void *abrirr_youtube(void *args){ 
	printf("Abriendo Youtube\n");
	return 0;
	}
void *escribirr_texto_en_word(void *args){ 
	printf("Escribiendo un texto en word\n");
	return 0;
	}
void *descargarr_archivo(void *args){ 
	printf("Descargando un archivo\n");
	return 0;
	}
void *subiviedoo_archivo(void *args){ 
	printf("Subiendo un archivo\n");
	return 0;
	}
void *compilandoo_programa(void *args){ 
	printf("Compilando un archivo\n");
	return 0;
	}
void *ejecutandoo_programa(void *args){ 
	printf("Ejecutando el programa\n");
	return 0;
	}
void *usandoo_terminal(void *args){ 
	printf("Usando la terminal\n");
	return 0;
	}


int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}


void reproducir_musica(void){
	//hilos con Pthread
	pthread_t proc_music;//<--iniciamos
	pthread_create(&proc_music, NULL, (void *)reproducirr_musica, NULL);//<--creamos
	pthread_join(proc_music, NULL);//<--ejecutamos
}

void abrir_youtube(void){

	//hilos con Pthread
	pthread_t hilo_youtube;//<--iniciamos
	pthread_create(&hilo_youtube, NULL, (void *)abrirr_youtube, NULL);//<--creamos
	pthread_join(hilo_youtube, NULL);//<--ejecutamos
}

void escribir_texto_word(void){

	//hilos con Pthread
	pthread_t hilo_escribir;//<--iniciamos
	pthread_create(&hilo_escribir, NULL, (void *)escribirr_texto_en_word, NULL);//<--creamos
	pthread_join(hilo_escribir, NULL);//<--ejecutamos
}

void descargar_archivo(void){

	//hilos con Pthread
	pthread_t hilo_descarga;//<--iniciamos
	pthread_create(&hilo_descarga, NULL, (void *)descargarr_archivo, NULL);//<--creamos
	pthread_join(hilo_descarga, NULL);//<--ejecutamos
}

void subiendo_archivo(void){

	//hilos con Pthread
	pthread_t hilo_archivo;//<--iniciamos
	pthread_create(&hilo_archivo, NULL, (void *)subiviedoo_archivo, NULL);//<--creamos
	pthread_join(hilo_archivo, NULL);//<--ejecutamos
}

void compilando_programa(void){

	//hilos con Pthread
	pthread_t hilo_compilar;//<--iniciamos
	pthread_create(&hilo_compilar, NULL, (void *)compilandoo_programa, NULL);//<--creamos
	pthread_join(hilo_compilar, NULL);//<--ejecutamos
}

void ejecutando_programa(void){

	//hilos con Pthread
	pthread_t hilo_programa;//<--iniciamos
	pthread_create(&hilo_programa, NULL, (void *)ejecutandoo_programa, NULL);//<--creamos
	pthread_join(hilo_programa, NULL);//<--ejecutamos
}

void usando_terminal(void){

	//hilos con Pthread
	pthread_t hilo_terminal;//<--iniciamos
	pthread_create(&hilo_terminal, NULL, (void *)usandoo_terminal, NULL);//<--creamos
	pthread_join(hilo_terminal, NULL);//<--ejecutamos
}
