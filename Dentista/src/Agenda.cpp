/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#include "Agenda.h"
#include "Contacto.h"
#include <string>
#include <fstream>
#include <iostream>



Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

bool Agenda::anadirContacto (Contacto c){

	std::ofstream salida("pacientes.txt",std::ios::app);


	salida 	<< c.getDni() << ";"
			<< c.getNombre() << ";"
			<< c.getApellido() <<  ";"
			<< c.getTelefono() << ";"
			<< c.isFavorito() << ";"
			<< c.getFrecuencia() << ";"
			<< c.getCalle() << ","
			<<	c.getNumero() << "\n";


	salida.close();

	return 1;

}

bool Agenda::modificarContacto(std::string DNI, Contacto c){
	//modificar linea en .txt si lo encuentra
	return 1;
}

bool Agenda::eliminarContacto(std::string DNI){
	//Eliminar linea en .txt
	return 1;
}
