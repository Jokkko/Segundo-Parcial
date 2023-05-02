/*
 * output.h
 *
 *  Created on: 12 nov. 2022
 *      Author: vazzr
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

/// \fn int MostrarOpcion(char*)
/// \brief funcion que se encarga de mostrar una opcion
///
/// \param opcion opcion a mostrar
/// \return devuelve 1 si se puede mostrar
int MostrarOpcion(char *opcion);

/// \fn int MostrarMenu7Opc(char*, char*, char*, char*, char*, char*, char*, char*)
/// \brief crea un menu de 7 opciones
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param opcion4
/// \param opcion5
/// \param opcion6
/// \param opcion7
/// \param menu nombre del menu
/// \return devuelve 1 si se puede mostrar
int MostrarMenu7Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *menu);



#endif /* OUTPUT_H_ */
