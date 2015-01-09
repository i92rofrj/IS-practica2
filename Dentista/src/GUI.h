/*
 * GUI.h
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#ifndef GUI_H_
#define GUI_H_

class GUI {
public:
	GUI();
	virtual ~GUI();

	bool imprimirAgenda();
	bool copiaSeguridad();
	int mostrarMenu();
	void seleccionOpcion(int opcion);
	void error (const char * p , const char * p2="");

};

#endif /* GUI_H_ */
