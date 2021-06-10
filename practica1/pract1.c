#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{

	char nombre[20];
	int matricula;
}est;


int main(int argc, char *argv[]){

	int n=argc;
	int vec[n];
	if(n<3){

		printf("No hay suficientes parametros de entrada.\n");
	}

	FILE *ptr;
	FILE *ptr2;

	ptr2 =fopen(argv[2],"w");

	ptr = fopen(argv[1],"r");

	if(ptr==NULL){

		perror("Error en la apertura del archivo");
		return 0;
	}

	const char *cadena[sizeof(ptr,ptr2)];
	char aux[sizeof];
	char palabraAlf[20][20];
	int ia,ja,ka;
	int l=0;
	
	while(feof(ptr)==0){
		fscanf(ptr, "%s", palabraAlf[l]);
		l++;
	}
	
	for(ia=0; ia<l-1; ia++)
    {
        ka=ia;
        strcpy(aux, palabraAlf[ia]);
        for(ja=ia+1; ja<l; ja++)
        {
            if(strcmp(palabraAlf[ja], aux)<0)
            {
                ka=ja;
                strcpy(aux, palabraAlf[ja]);
            }
        }
        strcpy(palabraAlf[ka],palabraAlf[ia]);
        strcpy(palabraAlf[ia],aux);
    }
	
	for(ia=0; ia<l; ia++)
    {
        //printf(" %s",nombrealfabetico[ia]);
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

	if((ptr2=fopen(argv[2],"w"))==NULL){
		printf("Error al crear el archivo\n");
		return 0;
	}

	fclose(ptr2);
	printf("\nEl archivo ha sido creado con exito!\n");
	return 0;
	}