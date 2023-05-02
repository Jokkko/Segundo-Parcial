/*
 ============================================================================
 Name        : Segundo.c
 Author      : Fernandes Joaquin DIV 1K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "output.h"
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Lenguaje.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	char path[100];
	char siglo[100];
	int banderaCase1=0,banderaCase3=0,banderaCase5=0;
	LinkedList* listaLenguajes= ll_newLinkedList();
	LinkedList* listaLenguajesPorSiglo;

	do{
		opcion = MostrarMenu7Opc("1.Leer archivo\n","2.Imprimir datos\n","3.Ordenar lista\n","4.Generar ordenado.csv\n","5.Filtrar por siglo\n","6.Generar filtrado.csv\n","7.Salir\n","\nMenu Principal\n");
		switch(opcion){
		case 1:
			if(banderaCase1==0){
				getString(path,100,"Ingrese la ruta al archivo con la extension incluida: \n");
				banderaCase1 = controller_cargarLenguajesDesdeTexto(path,listaLenguajes);
			}else{
				printf("\nError ya se han cargado los lenguajes\n");
			}
			break;
		case 2:
			if(banderaCase1!=0){
				if(controller_listarLenguajes(listaLenguajes)==-1){
					printf("\nOcurrio un error al listar los lenguajes\n");
				}
			}else{
				printf("\nDebe leer el archivo antes de entrar a esta opcion\n");
			}
			break;
		case 3:
			if(banderaCase1!=0){
				if(ll_sort(listaLenguajes,ordenarPorAutor,1)==-1){
					printf("\nOcurrio un error al ordenar los archivos\n");
				}else{
					banderaCase3=1;
					printf("\nLista ordenada correctamente\n");
				}
			}else{
				printf("\nDebe leer el archivo antes de entrar a esta opcion\n");
			}
			break;
		case 4:
			if(banderaCase1!=0 && banderaCase3==1){
				if(controller_guardarLenguajesModoTexto("ordenado.csv",listaLenguajes)==-1){
					printf("\nOcurrio un error al guardar los lenguajes\n");
				}else{
					printf("\nLenguajes guardados con exito\n");
				}
			}else{
				printf("\nDebe leer el archivo y ordenarlo antes de entrar a esta opcion\n");
			}
			break;
		case 5:
			if(banderaCase1!=0){
				getString(siglo,50,"Ingrese el siglo para filtrar (XIX, XX, XXI): \n");

				if(strcmpi(siglo,"XX")==0){
					listaLenguajesPorSiglo = ll_filter(listaLenguajes,filtrarPorSigloXX);
					if(listaLenguajes!=NULL){
						printf("\nLenguajes filtrados con exito\n");
						banderaCase5=1;
					}
				}else{
					if(strcmpi(siglo,"XIX")==0){
						listaLenguajesPorSiglo = ll_filter(listaLenguajes,filtrarPorSigloXIX);
						if(listaLenguajes!=NULL){
							printf("\nLenguajes filtrados con exito\n");
							banderaCase5=1;
						}
					}else{
						if(strcmpi(siglo,"XXI")==0){
							listaLenguajesPorSiglo = ll_filter(listaLenguajes,filtrarPorSigloXXI);
							if(listaLenguajes!=NULL){
								printf("\nLenguajes filtrados con exito\n");
								banderaCase5=1;
							}
						}
					}
				}
				printf("\nIngrese un siglo valido\n");
			}else{
				printf("\nDebe leer el archivo antes de entrar a esta opcion\n");
			}
			break;
		case 6:
			if(banderaCase1!=0 && banderaCase5==1){
				if(controller_guardarLenguajesModoTexto("filtrado.csv",listaLenguajesPorSiglo)==-1){
					printf("\nOcurrio un error al guardar los lenguajes\n");
				}else{
					printf("\nLenguajes guardados con exito\n");
				}
			}else{
				printf("\nDebe leer el archivo y filtrar 1 vez antes de entrar a esta opcion\n");
			}
			break;
		case 7:
			printf("\nSaliendo...\n");
			ll_deleteLinkedList(listaLenguajesPorSiglo);
			ll_deleteLinkedList(listaLenguajes);
			break;
		}
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
