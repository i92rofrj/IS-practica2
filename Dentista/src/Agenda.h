/*
 * Agenda.h
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#ifndef AGENDA_H_
#define AGENDA_H_
#include <string>
#include <list>



class Agenda {
public:
	Agenda();
	virtual ~Agenda();

	bool anadirContacto(Contacto contacto);
	bool modificarContacto(std::string DNI, Contacto contacto);
	bool eliminarContacto(std::string DNI);
	std::list<Contacto> buscarApellido(std::string apellido);


};




#endif /* AGENDA_H_ */
