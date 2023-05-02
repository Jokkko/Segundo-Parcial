#include <stdio.h>
#include <stdlib.h>

#include "Lenguaje.h"
#include "LinkedList.h"

int parser_LenguajeFromText(FILE* pFile , LinkedList* pArrayListLenguaje){
	eLenguaje* pLenguaje;
	int retornoFscanf;
	char idAux[50];
	char nombreAux[1000];
	char anioCreacionAux[50];
	char autorAux[1000];
	int id;
	int anioCreacion;

	int retorno=-1;
	if(pFile != NULL && pArrayListLenguaje != NULL){
		retorno=1;
		fscanf(pFile,"%s\n",anioCreacionAux); //lectura fantasma
		while(feof(pFile) == 0){
			retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,anioCreacionAux,autorAux);
			if(retornoFscanf == 4){
				id=atoi(idAux);
				anioCreacion=atoi(anioCreacionAux);
				pLenguaje = leng_newParametros(id,nombreAux,anioCreacion,autorAux);
				ll_add(pArrayListLenguaje,pLenguaje);
			}
		}
		printf("\nLenguajes cargados con exito\n");
	}else{
		printf("\nERROR no se encontro el archivo\n");
	}

    return retorno;
}
