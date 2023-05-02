#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL; //Asignamos el valor a null

    this = (LinkedList*)malloc(sizeof(LinkedList)); //Reservamos memoria para la nueva linkedlist
    if(this != NULL){  //Si se pudo reservar
    	this->pFirstNode=NULL; //Asignamos valores iniciales (NULL) al primer nodo
    	this->size =0; //Asignamos el tamanio en 0
    }


    return this; 	//Devolvemos el puntero a la linked list
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1; //Inicializamos el retorno en error

    if(this !=NULL){ // Verificamos que la lista exista
    	returnAux = this->size; //Asignamos al valor del retorno el tamanio de la lista
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* retorno=NULL;  //Asignamos el valor a null
	int largoll; //creamos la variable largoll
	largoll =ll_len(this);  //A la variable largoll le asignamos el valor del tamanio de la linked list

	if((nodeIndex<largoll && nodeIndex>=0) && this !=NULL){ //Verificamos que el nodo recibido no sobrepase el largo de la linked list, ni que sea menor a 0 y verificamos que la lista exista
		retorno = this->pFirstNode;  //Asignamos a retorno el primer nodo
		for(int i=0;i<nodeIndex;i++){ //Recorremos la linked list si el largo es mayor a 0
			retorno=retorno->pNextNode; //Cambiamos el valor de retorno al proximo nodo por cada iteracion del for
		}
	}

    return retorno;	//devolvemos el puntero al nodo
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1; //Inicializamos en error
	Node* aux = NULL; //Inicializamos en NULL
	Node* pNode = NULL;  //Inicializamos en NULL
	int largoll;  //creamos la variable largoll

	largoll = ll_len(this); //A la variable largoll le asignamos el valor del tamanio de la linked list
	if (this !=NULL && nodeIndex<=largoll && nodeIndex>=0 ){ //Verificamos que el nodo recibido no sobrepase por mas de 1 el largo de la linked list, ni que sea menor a 0 y verificamos que la lista exista
		pNode = (Node*) malloc(sizeof(Node)); //reservamos en memoria un espacio para el nuevo nodo a agregar

		if(pNode!=NULL){ //Si el espacio se pudo reservar
			pNode->pElement=pElement; //al elemento del nodo creado, se le asigna el elemento


			if(nodeIndex==0){//si el nodo se va a agregar en el indice 0
				pNode->pNextNode= this->pFirstNode; //Nuestro nodo creado apunta como next node, a nuestro first node
				this->pFirstNode=pNode; //Nuestro first node de la linked list ahora apunta a nuestro nodo creado
			}else{//Si no va a ser en el indice 0
				aux = getNode(this,nodeIndex-1); //Buscamos el nodo anterior al del indice
				if(aux != NULL){ // si encontramos el nodo
					pNode->pNextNode = aux->pNextNode; //Nuestro nodo creado apunta como next node, al next node del aux, ya que si el next node del aux es NULL, ahora el next node de nuestro nodo es NULL
					aux->pNextNode=pNode; //el next node del nodo anterior al del indice, apunta a nuestro nuevo nodo
				}
			}
			returnAux=0; //cambia el valor de retorno a exito
			this->size++; // aumenta el tamanio de la lista
		}
	}
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int largoll; //creamos la variable largoll
    int returnAux = -1;  //Inicializamos en error
    int error; //variable para confirmar el resultado de la funcion
    if(this!=NULL){ //Si la lista existe
    	returnAux=0; //cambia a exito
    	largoll= ll_len(this); //asigna el largo de la lista a largoll
    	error=addNode(this, largoll,pElement); //crea un nodo en la ultima posicion de la linked list con el elemento
    	if(error==-1){//si la funcion falla
    		returnAux=-1;//cambia a error
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode=NULL;
    int largoll;

    if (this !=NULL){ //Si la lista existe
    	largoll = ll_len(this); //asigna el largo de la lista a largoll
    	if(index<largoll && index>=0){ //Si el indice es menor al largo de la lista y mayor o igual a 0
    		pNode = getNode(this,index); //Busca el nodo en la lista con el indice
    		if(pNode!=NULL){//si encontro el nodo
    			returnAux = pNode->pElement; //asigna el puntero al elemento que contenga el nodo buscado
    		}
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int largoll;
    Node* pNode=NULL;

    largoll = ll_len(this);//asigna el largo de la lista a largoll
    if(this != NULL && index >= 0 && index < largoll){ //Si la lista existe y Si el indice es menor al largo de la lista y mayor o igual a 0
    	pNode = getNode(this,index); //Busca el nodo en la lista segun el indice
    	if(pNode!=NULL){ //Si encontro el nodo
    		pNode->pElement=pElement; // reemplazo el elemento que contiene ese nodo con el elemento que acabo de recibir
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int largoll;
    Node* pNode=NULL;
    Node* pAux=NULL;

    largoll = ll_len(this); //asigna el largo de la lista a largoll
    if(this != NULL && index >= 0 && index < largoll){  //Si la lista existe y Si el indice es menor al largo de la lista y mayor o igual a 0
    	pNode = getNode(this,index); //Busca el nodo en la lista segun el indice
    	if(pNode!=NULL){ //Si encontro el nodo
    		if(index==0){ //Si el nodo era el primero de la lista
    			this->pFirstNode=pNode->pNextNode; //mi first node, apunta al que sigue
    		}else{//si no es el primer nodo
    			pAux = getNode(this,index-1); //busco el nodo anterio
    			if(pAux!=NULL){//si se encontro
    				pAux->pNextNode=pNode->pNextNode;//el next node de mi nodo anterior, apunta al next node del nodo a borrar
    			}
    		}
    		free(pNode);//libero el nodo ya que la lista perdio su referencia
    		this->size--;//decremento el tamanio de la lista
    		returnAux=0;
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int largoll;
    largoll = ll_len(this);

    if(this!=NULL && largoll>0){//si la lista existe y el tamanio es mayor a 0
    	for(int i=0;i<largoll;i++){//recorre la lista
    		if(ll_remove(this,i)==0){//va eliminando los elementos por cada iteracion del for
    	    	returnAux=0;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;


    if(this!=NULL){//si la lista existe
    	if(ll_clear(this)==0){ //limpia los elementos de la lista
    		free(this);//libera la memoria de la linkedlist
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largoll;
    Node* pNode=NULL;
    largoll = ll_len(this);

    if(this!=NULL && largoll>0){//verifica que la lista exista y el largo sea mayor a 0
    	for(int i=0;i<largoll;i++){ //recorro la lista
    		pNode=getNode(this,i); //por cada iteracion agarro un nodo
    		if(pNode->pElement==pElement){ //comparo si el elemento recibido y el elemento del nodo son iguales
    			returnAux=i; //devuelvo el indice donde se encuentra el elemento
    			break; //termino el for
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int largoll;
    if(this!=NULL){//verifico que la lista exista
    	largoll=ll_len(this);
    	if(largoll>0){ //Si el largo de la lista es mayor a 0
    		returnAux=0; //devuelvo 0
    	}else{//Sino
    		returnAux=1; //devuelvo 1
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int largoll;
    largoll=ll_len(this);//obtengo el largo de la lista
    if(this != NULL && index >= 0 && index <= largoll){ // verifico que la lista exista, que el indice sea menor o igual al largo de la lista, y que el indice sea mayor o igual a 0
    	if(addNode(this, index, pElement)==0){ //aniado un nodo a la lista en el indice indicado y le agrego el elemento si sale bien
    		returnAux=0;//el retorno cambia a exito
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int largoll;
    void* pElement=NULL;
    largoll=ll_len(this);
    if(this != NULL && index >= 0 && index < largoll){// verifico que la lista exista, que el indice sea menor  al largo de la lista, y que el indice sea mayor o igual a 0
    	pElement = ll_get(this,index); //Consigo el elemento del indicie que me pasaron
		if(ll_remove(this, index)==0)  //remuevo de la lista el nodo
		{
			returnAux = pElement;//devuelvo el puntero al elemento
		}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largoll;
    largoll = ll_len(this);
    if(this!=NULL){//verifico que la lista sea distinta de null
    	returnAux=0;
    	if(largoll>0){//si el largo de la lista es mayor a 0
    		if(ll_indexOf(this,pElement)!=-1){//si la funcion me devuelve un numero distinto a -1 significa que encontro un indice para el elemento
    			returnAux=1;
    		}
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int largoll2;
    void* pElement=NULL;
    largoll2 = ll_len(this2);
    if(this !=NULL && this2 !=NULL){//verifica si las dos listas existen
    	returnAux=1;
    	for(int i=0;i<largoll2;i++){//recorre la segunda lista
    		pElement = ll_get(this2,i);//consigue cada elemento de la segunda lista por cada iteracion del for
    		if(ll_contains(this,pElement)==0){//si no contiene la primera lista un elemento de la segunda
    			returnAux=0;
    			break;//rompe la iteracion
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
	void* pElement=NULL;
	int largoll;

	largoll = ll_len(this);
    if(this != NULL && from >= 0 && to > 0 && from <= largoll && to <= largoll){//verificacion de que la lista exista y los datos sean correctos
    	cloneArray = ll_newLinkedList();//crea una nueva lista
    	if(cloneArray!=NULL){//si se creo la lista
    		for(int i=from;i<to;i++){//itera desde from hasta to
    			pElement=ll_get(this,i);//guardo el elemento de la lista en la posicion de i
    			ll_add(cloneArray,pElement);//lo aniado a la lista nueva
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int largoll;

    if(this !=NULL){//si la lista existe
    	largoll=ll_len(this);//obtengo el largo de la lista
    	cloneArray = ll_subList(this,0,largoll); //clono la lista desde 0 hasta el largo

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int largoll;
    void* pElement1=NULL;
    void* pElement2=NULL;
    if(this!=NULL && (order ==1 || order ==0) && pFunc!=NULL){//verifico que la lista exista, que la funcion tambien y que el orden sea ascendente o descendente
    	largoll=ll_len(this);
    	//arranco el burbujeo
    	for(int i=0;i<largoll-1;i++){
    		for(int j=i+1;j<largoll;j++){
    			//obtengo los dos elementos para la funcion
    			pElement1=ll_get(this,i);
				pElement2=ll_get(this,j);
			//si el elemento1 es mayor al elemento2, y orden ascendente				si el elemento1 es menor al elemento2, y orden descendente
				if((pFunc(pElement1, pElement2) > 0 && order==1) || (pFunc(pElement1, pElement2) < 0 && order==0)){
					//los dejo en la posicion
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement1);
				}
			}
    	}
    	returnAux=0;
    }
    return returnAux;

}

LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void*)){
	LinkedList* listaResultado= NULL;
	int largoll;
	void* pElement=NULL;
	if(this !=NULL && pFunc != NULL){//verifica si la lista y la funcion existen
		listaResultado = ll_newLinkedList();//crea la lista resultado
		if(listaResultado!=NULL){//verifico si se creo la lista
			largoll=ll_len(this);
			for(int i=0;i<largoll;i++){//recorro la primera lista
				pElement = ll_get(this,i);//guardo los elementos de la primera lista
				if(pFunc(pElement)==1){//si pasan por el filtro
					ll_add(listaResultado,pElement);//los agrego a la nueva lista
				}
			}
		}
	}
	return listaResultado;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void*)){
	LinkedList* listaResultado=NULL;
	int largoll;
	void* pElement=NULL;
	if(this !=NULL && pFunc != NULL){//verifico que la lista y la funcion existen
		listaResultado = ll_clone(this);//creo la nueva lista
		largoll=ll_len(listaResultado);
		for(int i=0;i<largoll;i++){//recorro la primera lista
			pElement = ll_get(listaResultado,i);//guardo el elemento de la primera lista
			pElement=pFunc(pElement);//cambio el valor del elemento segun la funcion
			ll_add(listaResultado,pElement);//aniado el elemento a una nueva lista con los elementos cambiados
		}
	}
	return listaResultado;
}
