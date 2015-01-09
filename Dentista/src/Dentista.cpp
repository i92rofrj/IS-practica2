
#include <iostream>
#include <list>
#include <iostream>
#include "Contacto.h"
#include "Agenda.h"
#include "GUI.h"

int main(void){
	GUI g;
	int opcion = 0;

	do{
	opcion = g.mostrarMenu();
	g.seleccionOpcion(opcion);
	}
	while(opcion!=7);
}


