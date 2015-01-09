/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i12sacat
 */

#include "Agenda.h"
#include "Contacto.h"
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <list>


Agenda::Agenda() {

	setRutaBbdd("../pacientes.txt");
	setRutaAux("../pacientesb.txt");

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}


Contacto Agenda::rellenarDatos(Contacto &contacto){
	std::string cadena;
	int numero = 0;
	std::string fav;

	getchar();
	std::cout << "Nombre: ";
	std::getline (std::cin,cadena);
	contacto.setNombre(cadena);


	std::cout << "Apellido: ";
	std::getline (std::cin,cadena);
	contacto.setApellido(cadena);


	std::cout << "DNI: ";
	std::getline (std::cin,cadena);
	contacto.setDni(cadena);
	

	std::cout << "Telefono: ";
	std::getline (std::cin,cadena);
	contacto.setTelefono(cadena);

	
	std::cout << "Favorito (1 sí 0 no):  ";

	std::cin >> fav;
	 if(fav=="0"){contacto.setFavorito(false);}else{contacto.setFavorito(true);}


	    /* No hemos encontrado la solucion para acceder a la lista de Conctacto.h
	     * y poder entrar en las listas de redes sociales o direcciones para
	     * ir haciendo push_back para meter varias redes sociales o direcciones.
	     */
	getchar();
	std::cout << "Calle: ";
	std::getline (std::cin,cadena);
	contacto.setCalle(cadena);

	std::cout << "Numero: ";
	std::cin >> cadena;

	numero = atoi(cadena.c_str());
	contacto.setNumero(numero);

	getchar();
	std::cout << "Nombre red social: ";
	std::getline (std::cin,cadena);
	contacto.setNombreRed(cadena);

	std::cout << "Usuario: ";
	std::getline (std::cin,cadena);
	contacto.setUsuario(cadena);


	return contacto;
}

void Agenda::muestraPacientes(std::list<Contacto> listaC){

	std::list<Contacto>::iterator i;
	i=listaC.begin();
	std::string favorito;
		
	if(i->isFavorito()==1){
		favorito="Si";
	}else{
		favorito="No";
	}
    std::cout << ""<<i->getNombre()<<" ";
    std::cout << ""<<i->getApellido()<<"| ";
    std::cout << "DNI: "<<i->getDni()<<"| ";
    std::cout << "Telefono: "<<i->getTelefono()<<"| ";
    std::cout << "Favorito: "<<favorito<<"| ";
    std::cout << "Calle: "<<i->getCalle()<<", ";
    std::cout << i->getNumero()<<"| ";
    std::cout << "Red social: "<<i->getNombreRed()<<", ";
    std::cout << i->getUsuario()<<" ";
    std::cout << std::endl;
}

bool Agenda::anadirContacto(Contacto c){

	std::ofstream salida(getRutaBbdd().c_str(),std::ios::app);
	salida<<c.getDni()<<";"<<c.getNombre()<<";"<<c.getApellido()<<";"<<c.getTelefono()<<";"<<c.isFavorito()<<";"<<c.getFrecuencia()<<";"<<c.getCalle()<<";"<<c.getNumero()<<";"<<c.getNombreRed()<<";"<<c.getUsuario()<<"\n";
    salida.close();

    return 0;
	
}

bool Agenda::modificarContacto(std::string DNI, Contacto c){
	FILE *fich, *fich2;
	int aModificar=0;
	char cadena [2000];
	char *separa;
	std::string datos;
	fich=fopen (getRutaBbdd().c_str() , "r");
	fich2=fopen (getRutaAux().c_str() , "w");

	while (fgets (cadena , 2000 , fich) != NULL) {
		
		separa = strtok(cadena,";");
		datos="";
			while (separa!=NULL ){
						
					if((!strstr(separa,DNI.c_str()))){
						datos+=";";
						datos+=separa;
					}else{
						separa = strtok(cadena,";"); 
						aModificar=1;
					}

				separa=strtok(NULL, ";");

			}
			datos.erase(0,1);
			if(aModificar==1){
				datos+=c.getDni();
				datos+=";";
				datos+=c.getNombre();
				datos+=";";
				datos+=c.getApellido();
				datos+=";";
				datos+=c.getTelefono();
				datos+=";";
				datos+=static_cast<std::ostringstream*>(&(std::ostringstream() << c.isFavorito()))->str();
				datos+=";";
				datos+=static_cast<std::ostringstream*>(&(std::ostringstream() << c.getFrecuencia()))->str();	
				datos+=";";
    			datos+=c.getCalle();
				datos+=";";
				datos+=static_cast<std::ostringstream*>(&(std::ostringstream() << c.getNumero()))->str();
				datos+=";";	
    			datos+=c.getNombreRed();
				datos+=";";
    			datos+=c.getUsuario();
				datos+="\n";		



		
			}

			fputs(datos.c_str(),fich2);
			aModificar=0;
	}

	fclose (fich);
	fclose (fich2);
	remove(getRutaBbdd().c_str());
	rename(getRutaAux().c_str(),getRutaBbdd().c_str());



	return 0;

}

bool Agenda::eliminarContacto(std::string DNI){

	FILE *fich, *fich2;
	char cadena [2000];
	char *separa;
	std::string datos;
	fich=fopen (getRutaBbdd().c_str(), "r");
	fich2=fopen (getRutaAux().c_str() , "w");

	while (fgets (cadena , 2000 , fich) != NULL) {
		
		separa = strtok(cadena,";");
		datos="";
			while (separa!=NULL ){
						
					if((!strstr(separa,DNI.c_str()))){
						datos+=";";
						datos+=separa;
					}else{
						separa = strtok(cadena,";"); 
					}

				separa=strtok(NULL, ";");

			}
			datos.erase(0,1);
			fputs(datos.c_str(),fich2);
	}

	fclose (fich);
	fclose (fich2);
	remove(getRutaBbdd().c_str());
	rename(getRutaAux().c_str(),getRutaBbdd().c_str());

 	return 0;
}


std::list<Contacto> Agenda::buscar(std::string datoAbuscar){
	std::list<Contacto> listaC;
    Contacto c;
	FILE *fich;
	int anadir=0, contador=0, valor;
	char cadena [2000];
	char *separa;
	std::string datos[10];
	fich=fopen (getRutaBbdd().c_str() , "r");

	while (fgets (cadena , 2000 , fich) != NULL) {
		
		separa = strtok(cadena,";");
			while (separa!=NULL ){
						
					if((!strstr(separa,datoAbuscar.c_str()))){
						datos[contador++]=separa;
					}else{
						datos[contador++]=separa;
						anadir=1;
					}
				separa=strtok(NULL, ";");

			}

			if(anadir==1){
			    c.setDni(datos[0]);
			    c.setNombre(datos[1]);
			    c.setApellido(datos[2]);
			    c.setTelefono(datos[3]);
				valor = atoi(datos[4].c_str());
			    c.setFavorito(valor);
				valor = atoi(datos[5].c_str());
			    c.setFrecuencia(valor);
			    c.setCalle(datos[6]);
				valor = atoi(datos[7].c_str());
			    c.setNumero(valor);
			    c.setNombreRed(datos[8]);
			    c.setUsuario(datos[9]);
				listaC.push_back(c);
			}



			anadir=0;
			contador=0;
	}

	fclose (fich);

	return listaC;

}


std::string Agenda::mostrarResultados(std::list<Contacto> listaC){

	std::list<Contacto>::iterator i;
	int opcion,contador=1;
	std::string DNI;

	for (i=listaC.begin(); i!=listaC.end(); i++){
		std::cout<<"\t"<<contador++<<" -> "<<i->getNombre()<<" ";
		std::cout<<""<<i->getApellido()<<" ";
		std::cout<<"con DNI: "<<i->getDni()<<std::endl;
	}
	
	if(contador==1){
		std::cout<<"No se ha encontrado ningun paciente";
		return 0;
	}

	do{
	std::cout<<std::endl<<"Seleccione un paciente de la lista: ";
		std::cin>>opcion;
	}while(opcion<1 || opcion>=contador);
	
	contador=0;
	for (i=listaC.begin(); i!=listaC.end() && contador++<opcion; i++){
		DNI=i->getDni();
	}
	return DNI;
}








