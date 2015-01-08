//============================================================================
// Name        : Dentista.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Contacto.h"
#include "Agenda.h"
using namespace std;

int main() {
/**
 * Para subir los cambios
 * Git add nombreFichero
 * Git commit -m "Comentario de cambio"
 * Git push
 *
 * Para traerte los cambios
 * Git pull
 */
	Contacto c;
	c.setNombre("Tomas");
	c.setApellido("Martin");
	c.setDni("56789248J");
	c.setTelefono("666777888");
	c.setFavorito(0);
	c.setFrecuencia(10);

	c.setCalle("Avenida Aeropuerto");
	c.setNumero(7);

	c.setCalle("La victoria");
	c.setNumero(77);


	Agenda a;
	a.anadirContacto(c);
	cout << "Exito" << endl;
}
