

#ifndef leng_H_INCLUDED
#define leng_H_INCLUDED

typedef struct
{
	int id;
	char nombre[100];
	int anioCreacion;
	char autor[100];
}eLenguaje;

/// \fn eLenguaje leng_new*()
/// \brief reserva espacio en memoria para un elemento del tipo eLenguaje
///
/// \return devuelve NULL si no lo pudo crear, o la direccion de memoria donde se creo
eLenguaje* leng_new();

/// \fn eLenguaje leng_newParametros*(int, char*, int, char*)
/// \brief crea un elemento del tipo eLenguaje con valores inicializados pasados por parametros
///
/// \param id
/// \param nombre
/// \param anioCreacion
/// \param autor
/// \return  devuelve NULL si no lo pudo crear, o la direccion de memoria donde se creo
eLenguaje* leng_newParametros(int id,char* nombre,int anioCreacion, char *autor);

/// \fn void leng_delete(eLenguaje* this)
/// \brief libera el espacio en memoria que ocupe un elemento de tipo eLenguaje
///
/// \param this elemento a liberar
/// \return
void leng_delete(eLenguaje* this);

/// \fn int leng_setId(eLenguaje* this,int id)
/// \brief funcion que se encarga de establecer el id de un elemento del tipo eLenguaje
///
/// \param this elemento eLenguaje
/// \param id valor del id
/// \return -1 en caso de error 1 en caso de exito
int leng_setId(eLenguaje* this,int id);

/// \fn int leng_getId(eLenguaje*, int*)
/// \brief funcion que se encarga de obtener el id de un elemento del tipo eLenguaje
///
/// \param this  elemento eLenguaje
/// \param id puntero a donde se guardara la id
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_getId(eLenguaje* this,int* id);


/// \fn int leng_setNombre(eLenguaje* this,char* nombre)
/// \brief funcion que se encarga de establecer el nombre de un elemento del tipo eLenguaje
///
/// \param this elemento eLenguaje
/// \param nombre  valor del nombre
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_setNombre(eLenguaje* this,char* nombre);

/// \fn int leng_getNombre(eLenguaje* this,char* nombre)
/// \brief funcion que se encarga de obtener el nombre de un elemento del tipo eLenguaje
///
/// \param this elemento eLenguaje
/// \param nombre puntero donde se guardara el nombre
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_getNombre(eLenguaje* this,char* nombre);

/// \fn int leng_setAnioCreacion(eLenguaje* this,int anioCreacion)
/// \brief  funcion que se encarga de establecer el anio de Creacion de un elemento del tipo eLenguaje
///
/// \param this  elemento eLenguaje
/// \param anioCreacion  valor a cargar
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_setAnioCreacion(eLenguaje* this,int anioCreacion);

/// \fn int leng_getAnioCreacion(eLenguaje* this,int* anioCreacion)
/// \brief   funcion que se encarga de obtener el anio de Creacion de un elemento del tipo eLenguaje
///
/// \param this  elemento eLenguaje
/// \param anioCreacion   puntero donde se guardara el anio de Creacion
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_getAnioCreacion(eLenguaje* this,int* anioCreacion);

/// \fn int leng_setAutor(eLenguaje* this,char* autor)
/// \brief   funcion que se encarga de establecer el autor de un elemento del tipo eLenguaje
///
/// \param this elemento eLenguaje
/// \param autor valor a cargar
/// \return devuelve -1 en caso de error y 1 en caso de exito
///
int leng_setAutor(eLenguaje* this,char* autor);

/// \fn int leng_getAutor(eLenguaje* this,char* autor)
/// \brief  funcion que se encarga de obtener el autor de un elemento del tipo eLenguaje
///
/// \param this   elemento eLenguaje
/// \param autor   puntero donde se guardara el autor
/// \return devuelve -1 en caso de error y 1 en caso de exito
int leng_getAutor(eLenguaje* this,char* autor);

/// \fn int ordenarPorAutor(void*, void*)
/// \brief funcion que se encarga de ordenar segun autores
///
/// \param lenguaje1 lenguaje a comparar
/// \param lenguaje2 lenguaje a comparar
/// \return devuelve 1 si el lenguaje 1 es mas pesado en ASCII que el segundo
int ordenarPorAutor(void* lenguaje1 ,void* lenguaje2 );

/// \fn int filtrarPorSigloXX(void*)
/// \brief funcion que se encarga de filtrar los lenguajes creados durante el siglo XX
///
/// \param lenguaje
/// \return devuelve 1 si el lenguaje fue creado en ese siglo
int filtrarPorSigloXX(void* lenguaje);

/// \fn int filtrarPorSigloXIX(void*)
/// \brief funcion que se encarga de filtrar los lenguajes creados durante el siglo XIX
///
/// \param lenguaje
/// \return devuelve 1 si el lenguaje fue creado en ese siglo
int filtrarPorSigloXIX(void* lenguaje);

/// \fn int filtrarPorSigloXXI(void*)
/// \brief funcion que se encarga de filtrar los lenguajes creados durante el siglo XXI
///
/// \param lenguaje
/// \return devuelve 1 si el lenguaje fue creado en ese siglo
int filtrarPorSigloXXI(void* lenguaje);

#endif //
