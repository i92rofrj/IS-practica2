/*
 * Contacto.h
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_
#include <string>

class Contacto {

	struct direccion{
		std::string calle;
		int numero;
	};

	struct redesSociales{
		std::string nombre;
		std::string usuario;
	};

public:
	Contacto();
	virtual ~Contacto();


private:
	std::string nombre_;
	std::string apellido_;
	std::string DNI_;
	std::string telefono_;
	bool favorito_;
	int frecuencia_;


};

#endif /* CONTACTO_H_ */
