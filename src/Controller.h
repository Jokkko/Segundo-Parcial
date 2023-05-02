

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/// \fn int controller_cargarLenguajesDesdeTexto(char*, LinkedList*)
/// \brief carga los lenguajes desde un archivo .csv
///
/// \param path ruta al archivo
/// \param pArrayListLenguaje linkedlist donde se cargaran los datos
/// \return 0 si no se encuentra la ruta, -1 en caso de error y 1 en caso de exito
int controller_cargarLenguajesDesdeTexto(char* path , LinkedList* pArrayListLenguaje);


/// \fn int controller_listarLenguajes(LinkedList*)
/// \brief lista los lenguajes en una linked list
///
/// \param pArrayListLenguaje linked list donde estan los datos a mostrar
/// \return -1 en caso de error 1 en caso de exito
int controller_listarLenguajes(LinkedList* pArrayListLenguaje);

/// \fn int controller_guardarLenguajesModoTexto(char*, LinkedList*)
/// \brief funcion que se encarga de guardar en un archivo los datos de una linked list
///
/// \param path ruta al archivo
/// \param pArrayListLenguaje linkedlist para sacar los datos
/// \return devuelve -1 en caso de error y  1 en caso de exito
int controller_guardarLenguajesModoTexto(char* path , LinkedList* pArrayListLenguaje);

#endif
