
#ifndef AGENDA_H_
#define AGENDA_H_
#include <string>
#include <list>
#include "Contacto.h"


class Agenda {
public:
	Agenda();
	virtual ~Agenda();

	bool anadirContacto(Contacto contacto);
	bool modificarContacto(std::string DNI, Contacto contacto);
	bool eliminarContacto(std::string DNI);

	std::string mostrarResultados(std::list<Contacto> listaC);
	std::list<Contacto> buscar(std::string datoAbuscar);
	Contacto rellenarDatos (Contacto &contacto);

	void muestraPacientes (std::list<Contacto> listaC);

	const std::string& getRutaBbdd() const {return rutaBBDD_;}

	const std::string& getRutaAux() const {return rutaAux_;}

	void setRutaAux(const std::string& rutaAux) {	rutaAux_ = rutaAux; }

	void setRutaBbdd(const std::string& rutaBbdd) {	rutaBBDD_ = rutaBbdd; }

private:
	std::string rutaBBDD_;
	std::string rutaAux_;

};

#endif /* AGENDA_H_ */
