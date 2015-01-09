/*
 * Contacto.h
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_
#include <string>
#include <list>

class Contacto {

	struct direccion{
		std::string calle;
		int numero;
	} direcciones;

	struct rrSS{
		std::string nombreRed;
		std::string usuario;
	} redesSociales;

public:
	Contacto();
	virtual ~Contacto();

	const std::string& getApellido() const { return apellido_;	}

	void setApellido(const std::string& apellido) {	apellido_ = apellido;	}

	const std::string getCalle() const {	return direcciones.calle; }

	void setCalle(const std::string& calle) {	direcciones.calle = calle; }

	const std::string& getDni() const {	return DNI_;	}

	void setDni(const std::string& dni) {	DNI_ = dni;	}

	int isFavorito() const {	return favorito_;	}

	void setFavorito(int favorito) {	favorito_ = favorito;	}

	int getFrecuencia() const {		return frecuencia_;	}

	void setFrecuencia(int frecuencia) {frecuencia_ = frecuencia;	}

	const std::string& getNombreRed() const {	return redesSociales.nombreRed;	}

	void setNombreRed(const std::string& nombre) {		this->redesSociales.nombreRed = nombre;	}

	const std::string& getNombre() const {	return nombre_;	}

	void setNombre(const std::string& nombre) {	nombre_ = nombre;	}

	int getNumero() const {	return direcciones.numero;	}

	void setNumero(int numero) {this->direcciones.numero = numero;	}

	const std::string& getTelefono() const {return telefono_;}

	void setTelefono(const std::string& telefono) {	telefono_ = telefono;	}

	const std::string& getUsuario() const {		return redesSociales.usuario;	}

	void setUsuario(const std::string& usuario) {	this->redesSociales.usuario = usuario;	}


private:
	std::string nombre_;
	std::string apellido_;
	std::string DNI_;
	std::string telefono_;
	int favorito_;
	int frecuencia_;

	//std::list <direccion> direcciones_; No sabemos como acceder a esta lista desde Agenda.cpp
	//std::list <rrSS> rS_;   No sabemos como acceder a esta lista desde Agenda.cpp


};

#endif /* CONTACTO_H_ */
