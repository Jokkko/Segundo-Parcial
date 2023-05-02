
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

/// \fn int parser_LenguajeFromText(FILE*, LinkedList*)
/// \brief funcion que se encarga de parsear los valores del archivo para poder asignarlos
///
/// \param pFile puntero al archivo
/// \param pArrayListLenguaje linked list
/// \return
int parser_LenguajeFromText(FILE* pFile , LinkedList* pArrayListLenguaje);


#endif /* PARSER_H_ */
