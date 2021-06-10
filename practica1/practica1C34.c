#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct punt{
	char *cad;
	struct punt *sig;
}punt;

typedef struct list{
	punt *inicio;
}list;

list *Gen_list(void){

	list *P;
	P = (list *) malloc(sizeof(list));
	P -> inicio = NULL;
	return P;
}

void insertarEnLista(list *P, char *cad){

	if(P->inicio == NULL){
		P->inicio = (punt *)malloc(sizeof(punt));
		P->inicio->cad = cad;
		P->inicio->sig = NULL;
		return;
	}
}

int main(int argc, char *argv[]){

	int g=argc;
	int vec[g];
	if(g<3){

		printf("No hay suficientes parametros de entrada.\n");
	}

	FILE *ptr;
	FILE *ptr2;

	ptr = fopen(argv[1],"r");
	//si nuesro archivo de entrada esta vacio nos mandara un error
	if(ptr==NULL){
		printf("Error en la apertura del archivo");
		return 0;
	}

	//const char *cadena[sizeof(ptr,ptr2)];
	list *P;
	P = Gen_list();
	list *Gen_list(void);
	void insertarEnLista(list *P, char *cadena);
	char aux[100];
	char palabraAlf[50][50];
	int ia,ja,ka;
	int l=0;
	//visualizamos los datos de nuestro archivo de entrada
	while(feof(ptr)==0){
		fscanf(ptr, "%s", palabraAlf[l]);
		insertarEnLista(P, palabraAlf[l]);
		printf("\n %s Ingresado correctamente", palabraAlf[l]);
		l++;
	}
	//abrimos el segundo archivo donde se colocaran los datos 
	ptr2 =fopen(argv[2],"w");
	//ordenamiento de cadena
	for(ia=0; ia<l; ia++){
        ka=ia;
        strcpy(aux, palabraAlf[ia]);
        for(ja=ia+1; ja<l; ja++){
            if(strcmp(palabraAlf[ja], aux)<0){
                ka=ja;
                strcpy(aux, palabraAlf[ja]);
            }
        }
        strcpy(palabraAlf[ka],palabraAlf[ia]);
        strcpy(palabraAlf[ia],aux);
    }
	//ingreso de cadena ordenada a nuevo archivo
	for(ia=1; ia<l; ia++){
        fprintf(ptr2,"%s\n",palabraAlf[ia]);
    }	
	/*while(feof(ptr)==0){
		fscanf(ptr, "%s\n", cadena);
		printf("%s\n", cadena);
		ordenar(cadena,nump);
		fprintf(ptr2, "%s\n", cadena);
	}*/

	fclose(ptr);
	printf("\nEl archivo se leyo correctamente.");
	//manejo de error en caso de no guardar datos en archivo
	if((ptr2=fopen(argv[2],"w"))==NULL){
		printf("Error al crear el archivo\n");
		return 0;
	}

	fclose(ptr2);
	printf("\nEl archivo ha sido creado con exito!\n");
	return 0;
	}
