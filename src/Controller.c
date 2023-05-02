#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
#include "LinkedList.h"
#include "input.h"
#include "Lenguaje.h"
#include "parser.h"
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarLenguajesDesdeTexto(char* path , LinkedList* pArrayListLenguaje){
	FILE* archivo;
	int retorno=-1;

	if(path !=NULL && pArrayListLenguaje != NULL){
		retorno =1;
		archivo = fopen(path,"r");
		if(archivo != NULL){
			parser_LenguajeFromText(archivo,pArrayListLenguaje);
			fclose(archivo);
		}else{
			printf("\nNo se encontro la ruta al archivo.\n");
			retorno =0;
		}
	}

    return retorno;
}

int controller_listarLenguajes(LinkedList* pArrayListLenguaje){
	eLenguaje* pLenguaje;
	int largoll;
	int id;
	char nombre[1000];
	int anioCreacion;
	char autor[1000];
	int retorno =-1;
	if(pArrayListLenguaje!=NULL){
		retorno =1;
		largoll = ll_len(pArrayListLenguaje);
		printf(" ______________________________________________________________________________________\n"
			   "|%-5s|%-30s|%-10s|%-30s|\n"
			   "|=====|==============================|==============================|===============|\n",
			     "ID","Nombre","Anio de Creacion","Autor");
		for(int i=0;i<largoll;i++){
			pLenguaje=(eLenguaje*)ll_get(pArrayListLenguaje,i);
			 leng_getId(pLenguaje,&id);
			 leng_getNombre(pLenguaje,nombre);
			 leng_getAnioCreacion(pLenguaje,&anioCreacion);
			 leng_getAutor(pLenguaje,autor);
			 if( anioCreacion >= 2000){
				printf("|%-5d|%-30s|%-10d|%-30s| SIGLO XXI\n",id,nombre,anioCreacion,autor);
			 }else{
				 if(anioCreacion >= 1900){
					printf("|%-5d|%-30s|%-10d|%-30s| SIGLO XX\n",id,nombre,anioCreacion,autor);
				 }else{
					 if(anioCreacion >= 1800){
						 printf("|%-5d|%-30s|%-10d|%-30s| SIGLO XIX\n",id,nombre,anioCreacion,autor);
					 }else{
						 printf("|%-5d|%-30s|%-10d|%-30s|\n",id,nombre,anioCreacion,autor);
					 }
				 }
			 }

		}
		printf("|_____|______________________________|______________________________|______________|\n");
	}

    return retorno;
}

int controller_guardarLenguajesModoTexto(char* path , LinkedList* pArrayListLenguaje){
	FILE *archivo;
	int largoll;
	eLenguaje* pLenguaje;
	int id;
	char nombre[1000];
	int anioCreacion;
	char autor[1000];
	int retorno=-1;

	if(path !=NULL && pArrayListLenguaje != NULL){
		retorno=1;
		archivo = fopen(path,"w");
		largoll = ll_len(pArrayListLenguaje);
		if(archivo!=NULL){
			fprintf(archivo,"id,nombre,anioCreacion,autor\n");
			for(int i=0;i<largoll;i++){
				pLenguaje = ll_get(pArrayListLenguaje,i);
				leng_getId(pLenguaje,&id);
				leng_getNombre(pLenguaje,nombre);
				leng_getAnioCreacion(pLenguaje,&anioCreacion);
				leng_getAutor(pLenguaje,autor);

				fprintf(archivo,"%d,%s,%d,%s\n",id,nombre,anioCreacion,autor);

			}
			fclose(archivo);
		}
	}
    return retorno;
}
