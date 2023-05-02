/*
 * input.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int esFloat(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if ((cadena[i] < '0' || cadena[i] > '9') && cadena[i]!='.') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esFloat(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s \n", mensajeError);
		if (reintentos == 0) {
			retorno=-1;
		}

	}
	return retorno;
}

int utn_getPositivo(int *pResultado, char *mensaje, char *mensajeError,int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt > 0) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s %d", mensajeError, reintentos);
		if (reintentos == 0) {
			printf("\nSaliendo...\n");
		}

	}
	return retorno;
}

int utn_getChar(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos > -1) {
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);
			fflush(stdin);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

int getString(char *string,int SIZE,char *mensaje)
{
	int retorno;
	char buffer[1024];
	int largoBuffer;

	retorno = 0;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",buffer);

	largoBuffer = (int)strlen(buffer);

	if(SIZE > largoBuffer)
	{
		strcpy(string,buffer);
		retorno = 1;
	}


	return retorno;
}


int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s \n", mensajeError);
		if (reintentos == 0) {
			retorno=-1;
		}

	}
	return retorno;
}


int getNombre(char *string,int SIZE,char *mensaje){
	int retorno;
	int largo;

	getString(string,SIZE,mensaje);

	largo= (int)strlen(string);

	for(int i=0;i<largo;i++){

		if( (string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122) || (string[0] !=32 && string[i]==32)){
			retorno=0;
		}else{
			retorno=-1;
			break;
		}
	}


	return retorno;
}

int getShort(short *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getShort(short *pResultado, char *mensaje, char *mensajeError,
		short minimo, short maximo, int reintentos) {
	short buffershort;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getShort(&buffershort) == 0) {
			if (buffershort >= minimo && buffershort <= maximo) {
				*pResultado = buffershort;
				retorno = 0;
				break;
			}
		}
		printf("%s \n", mensajeError);
		if (reintentos == 0) {
			retorno=-1;
		}

	}
	return retorno;
}
