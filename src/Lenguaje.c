#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "input.h"
#include "Lenguaje.h"
//------------------C O N S T R U C T O R E S---------------------------------

eLenguaje* leng_new(){
	eLenguaje* pLenguaje;

	pLenguaje = (eLenguaje*) malloc(sizeof(eLenguaje));
		if(pLenguaje!= NULL){
			leng_setId(pLenguaje,0);
			leng_setNombre(pLenguaje,"0");
			leng_setAnioCreacion(pLenguaje,0);
			leng_setAutor(pLenguaje,"0");
		}

    return pLenguaje;
}

eLenguaje* leng_newParametros(int id,char* nombre,int anioCreacion, char* autor){
	eLenguaje* pLenguaje;
	if(id>0 && nombre!=NULL && anioCreacion >0 && autor != NULL ){
		pLenguaje = leng_new();
		if(pLenguaje!=NULL){
			leng_setId(pLenguaje,id);
			leng_setNombre(pLenguaje,nombre);
			leng_setAnioCreacion(pLenguaje,anioCreacion);
			leng_setAutor(pLenguaje,autor);
		}
	}
	return pLenguaje;
}

//------------------D E S T R U C T O R---------------------------------
void leng_delete(eLenguaje* this){
    if(this != NULL){
        free(this);
    }
}

//------------------S E T T E R S---------------------------------
int leng_setId(eLenguaje* this,int id){
	int retorno=-1;

	if(this!=NULL && id > 0){
		this->id = id;
		retorno =1;
	}
	return retorno;
}

int leng_setNombre(eLenguaje* this,char* nombre){
	int retorno=-1;

	if(this!=NULL && nombre != NULL){
			strcpy(this->nombre,nombre);
			retorno =1;
		}
		return retorno;

}

int leng_setAnioCreacion(eLenguaje* this,int anioCreacion){
	int retorno=-1;

	if(this!=NULL){
		this->anioCreacion = anioCreacion;
			retorno =1;
		}
		return retorno;
}



int leng_setAutor(eLenguaje* this,char* autor){
	int retorno=-1;

	if(this!=NULL){
			strcpy(this->autor,autor);
			retorno =1;
		}
		return retorno;
}

//------------------G E T T E R S---------------------------------
int leng_getId(eLenguaje* this,int* id){
	int retorno= -1;

	if(this !=  NULL && id !=NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int leng_getNombre(eLenguaje* this,char* nombre){
	int retorno= -1;

	if(this !=  NULL && nombre !=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

int leng_getAnioCreacion(eLenguaje* this,int* anioCreacion){
	int retorno= -1;

	if(this !=  NULL && anioCreacion !=NULL)
	{
		*anioCreacion = this->anioCreacion;
		retorno = 0;
	}

	return retorno;
}

int leng_getAutor(eLenguaje* this,char* autor){
	int retorno= -1;

	if(this !=  NULL && autor !=NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}

	return retorno;
}
//------------------O R D E N A M I E N T O---------------------------------

int ordenarPorAutor(void* lenguaje1 ,void* lenguaje2 ){
	int retorno=0;

	eLenguaje* pLenguaje1;
	eLenguaje* pLenguaje2;

	char autor1[1000];
	char autor2[1000];
	pLenguaje1=(eLenguaje*) lenguaje1;
	pLenguaje2=(eLenguaje*) lenguaje2;
	leng_getAutor(pLenguaje1,autor1);
	leng_getAutor(pLenguaje2,autor2);
	if(strcmpi(autor1,autor2)>0){
		retorno =1;
	}
	return retorno;
}

//-------------------Aumento-----------------------------------

int filtrarPorSigloXX(void* lenguaje){

	eLenguaje*pLenguaje;
	int anioCreacion;
	int retorno=0;

	pLenguaje=(eLenguaje*) lenguaje;
	leng_getAnioCreacion(pLenguaje,&anioCreacion);
	if(anioCreacion >= 1900 && anioCreacion <2000 ){
		retorno =1;
	}
	return retorno;
}

int filtrarPorSigloXIX(void* lenguaje){

	eLenguaje*pLenguaje;
	int anioCreacion;
	int retorno=0;

	pLenguaje=(eLenguaje*) lenguaje;
	leng_getAnioCreacion(pLenguaje,&anioCreacion);
	if(anioCreacion >= 1800 && anioCreacion <1900 ){
		retorno =1;
	}
	return retorno;
}

int filtrarPorSigloXXI(void* lenguaje){

	eLenguaje*pLenguaje;
	int anioCreacion;
	int retorno=0;

	pLenguaje=(eLenguaje*) lenguaje;
	leng_getAnioCreacion(pLenguaje,&anioCreacion);
	if(anioCreacion >= 2000 && anioCreacion <3000 ){
		retorno =1;
	}
	return retorno;
}
