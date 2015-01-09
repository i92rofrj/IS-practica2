#include "GUI.h"
#include "Agenda.h"
#include "Contacto.h"
#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <sstream>

GUI::GUI() {


}

GUI::~GUI() {
	// TODO Auto-generated destructor stub
}


bool GUI::copiaSeguridad(){
	return 1;
}

bool GUI::imprimirAgenda(){

	return 1;
}

int GUI::mostrarMenu(){

	int opcion = 0;
	system("clear");
	std::cout << "Bienvenido a DentAgenda " << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << "Seleccion una opcion" << std::endl;
	std::cout << "1. Añadir paciente" << std::endl;
	std::cout << "2. Modificiar paciente" << std::endl;
	std::cout << "3. Buscar paciente" << std::endl;
	std::cout << "4. Imprimir agenda" << std::endl;
	std::cout << "5. Copia de seguridad" << std::endl;
	std::cout << "6. Borrar paciente" << std::endl;
	std::cout << "7. Salir" << std::endl;
	std::cin >> opcion;

	return opcion;

}

void GUI::seleccionOpcion(int opcion){
	Agenda a;
	Contacto c;
	std::list<Contacto> listaC;
	std::string apellido;
	std::string elDNI;
	char c2;



	switch (opcion) {
		case 1:
			system("clear");
			std::cout << "Rellene los datos del paciente" << std::endl;
				c = a.rellenarDatos(c);
				a.anadirContacto(c);
				std::cout << "Paciente añadido, pulse una tecla para continuar";
				getchar();

			break;

		case 2:
			system("clear");
			std::cout << "Escriba algun dato del paciente a buscar: ";
			std::cin >> apellido;
			listaC=a.buscar(apellido);
			elDNI = a.mostrarResultados(listaC);
			listaC.clear();
			listaC=a.buscar(elDNI);

			system("clear");
			a.muestraPacientes(listaC);
			std::cout<<std::endl<<"Modifique los datos del paciente: "<<std::endl;
			c = a.rellenarDatos(c);
			a.modificarContacto(elDNI,c);
			listaC.clear();
			break;

		case 3:
			system("clear");
			std::cout<<"Escriba algun dato del paciente a buscar: ";
			std::cin>>apellido;
			listaC=a.buscar(apellido);
			if(!listaC.empty()){
				elDNI=a.mostrarResultados(listaC);
				listaC.clear();
				listaC=a.buscar(elDNI);
				system("clear");
				a.muestraPacientes(listaC);
				getchar();
				getchar();
			}else{
				std::cout<<"No se ha encontrado ningun resultado";
				getchar();
				getchar();
			}
			break;

		case 4:
		{
			system("clear");
			std::cout << "******************AGENDA******************" << std::endl;
			std::ifstream Imp(a.getRutaBbdd().c_str());
		    if(!Imp){ std::cout << "No se puede abrir el fichero\n"; exit(-1);}


		        while(Imp.get(c2)){

		            std::cout<<c2;

		        }

		    Imp.close();
		    getchar();
		    getchar();
		}
			break;

		case 5:
		{

			system("clear");
			std::cout << "******************COPIA DE SEGURIDAD GENERADA******************" << std::endl;
		    time_t ahora;
		    struct tm *hora;
		    time(&ahora);

		    std::string horas, minutos, segundos, dia, mes, anyo, nombreFichero;

		    std::ifstream origen(a.getRutaBbdd().c_str());    // Abre flujo de archivo de entrada
		    if(!origen){ std::cout << "No se puede abrir el fichero\n"; exit(-1);}


		    hora = localtime(&ahora);

		    struct tm *fecha;
		    time(&ahora);
		    fecha = localtime(&ahora);

				horas=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_hour)))->str();
				minutos=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_min)))->str();
				segundos=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_sec)))->str();
				dia=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_mday)))->str();
				mes=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_mon+1)))->str();
				anyo=static_cast<std::ostringstream*>(&(std::ostringstream() << (fecha->tm_year+1900)))->str();

		    nombreFichero=horas+":"+minutos+":"+segundos+"_"+dia+"_"+mes+"_"+anyo+".txt";


		    std::ofstream destino(nombreFichero.c_str()); // Abre flujo de archivo de salida
		    if(!destino){ std::cout << "No se puede abrir el fichero\n"; exit(-1);}


		    while(origen.get(c2)) destino.put(c2);    //Copia caracteres de origen en destino


		    if( !origen.eof() || !destino){ std::cout << "Ha habido un error\n"; exit(-1);}

		    origen.close();
		    destino.close();
		    getchar();
		    getchar();
		}
			break;


		case 6:
					system("clear");
					std::cout<<"Escriba algun dato del paciente a eliminar: ";
					std::cin>>apellido;
					listaC=a.buscar(apellido);
					if(!listaC.empty()){
						elDNI=a.mostrarResultados(listaC);

						system("clear");
						a.eliminarContacto(elDNI);
						std::cout<<"Paciente eliminado";
						getchar();
						getchar();
					}else{
						std::cout<<"No se ha encontrado ningun resultado";
						getchar();
						getchar();
					}
					break;

		case 7:
			std::cout << "Adios" << std::endl;
			break;

		default:
			std::cout << "Opcion incorrecta" << std::endl;
			break;
	}
}


