/*
 * input.h
 *
 *  Created on: 29 sep. 2022
 *      Author: vazzr
 */

#ifndef INPUT_H_
#define INPUT_H_


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado);

/// \fn int getFloat(float*)
/// \brief Verifica si la cadena ingresada es flotante
///
/// \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int getFloat(float *pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int esNumerica(char *cadena);

/// \fn int esFloat(char*)
/// \brief Verifica si la cadena ingresada es flotante
///
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
int esFloat(char *cadena);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud);

/**
 * \fn int utn_getPositivo(int*, char*, char*, int)
 * \brief Pide un numero al usuario y verifica que sea positivo
 *
 * \param pResultado Puntero a el espacio de memoria donde se guardara el numero positivo ingresado
 * \param mensaje Mensaje a mostrar a la hora de pedir el numero
 * \param mensajeError Mensaje a mostrar en caso de error
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 (EXITO) si se obtiene un numero positivo y -1 (ERROR) si no
 */
int utn_getPositivo(int *pResultado, char *mensaje, char *mensajeError,	int reintentos);

/**
 * \fn int utn_getFloat(float*, char*, char*, float, float, int)
 * \brief Pide al usuario un numero flotante y verifica que este entre un maximo y un minimo dados por parametros
 *
 * \param pResultado puntero a la direccion de memoria donde se guardara el flotante obtenido
 * \param mensaje mensaje a mostrar al usuario a la hora de pedir el flotante
 * \param mensajeError mensaje a mostrar en caso de error
 * \param minimo numero minimo del flotante
 * \param maximo numero maximo del flotante
 * \param reintentos cantidad de reintentos
 * \return  Retorna 1 (EXITO) si se obtiene un caracter entre los rangos y -1 (ERROR) si no
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);

/**
 * \fn int utn_getChar(char*, char*, char*, char, char, int)
 * \brief Pide al usuario un caracter y verifica que este entre los valores maximos y minimos dados por parametros
 *
 * \param pResultado puntero a la direccion  de memoria donde se guardara el caracter obtenido
 * \param mensaje Mensaje a mostrar a la hora de pedir el caracter
 * \param mensajeError Mensaje a mostrar en caso de error
 * \param minimo Numero del caracter en codigo ascii minimo
 * \param maximo Numero del caracter en codigo ascii maximo
 * \param reintentos Cantidad de reintentos
 * \return Retorna 1 (EXITO) si se obtiene un caracter entre los rangos y -1 (ERROR) si no
 */
int utn_getChar(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);
/**
 * \fn int getString(char[], int, char[])
 * \brief Pide al usuario una cadena de caracteres
 *
 * \param string Array donde se guardara la cadena
 * \param SIZE Tamanio de la cadena
 * \param mensaje Mensaje a mostrar al usuario
 * \return Retorna 0 en caso de error y 1 si se obtiene la cadena
 */
int getString(char string[],int SIZE,char mensaje[]);


/// \fn int getNombre(char*, int, char*)
/// \brief Pide al usuario que ingrese un nombre
///
/// \param string
/// \param SIZE
/// \param mensaje
/// \return Retorna 0 en caso de error y 1 si se obtiene la cadena
int getNombre(char *string,int SIZE,char *mensaje);



/// \fn int getShort(short*)
/// \brief Verifica si la cadena ingresada es short
///
/// \param pResultado
/// \return devuelve -1 en caso de error o 1 en caso de exito
int getShort(short *pResultado);

/// \fn int utn_getShort(short*, char*, char*, short, short, int)
/// \brief Pide al usuario un numero flotante y verifica que este entre un maximo y un minimo dados por parametros
///
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param reintentos
/// \return  Retorna 1 (EXITO) si se obtiene un caracter entre los rangos y -1 (ERROR) si no
int utn_getShort(short *pResultado, char *mensaje, char *mensajeError,short minimo, short maximo, int reintentos);

#endif /* INPUT_H_ */
