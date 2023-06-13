#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "../include/Usuario.h"
#include "../include/estudiante.h"
#include "../include/profesor.h"
#include "../include/fecha.h"
#include "../include/dataIdioma.h"
#include "../include/dataUsuario.h"
using namespace std;

DataUsuario::DataUsuario(string nick, string contra, string descripcion, string nombre): nick(nick), contra(contra), descripcion(descripcion), nombre(nombre){}

DataUsuario::DataUsuario(string nick, string descripcion, string nombre) : nick(nick), descripcion(descripcion), nombre(nombre){};

string DataUsuario::getNick()const{return this->nick;};

void DataUsuario::setNick(string nick){this->nick = nick;}

string DataUsuario::getContra()const{return this->contra;}

void DataUsuario::setContra(string contra){this->contra = contra;}

string DataUsuario::getDescripcion()const{return this->descripcion;};

void DataUsuario::setDescripcion(string desc){this->descripcion = desc;}

string DataUsuario::getNombre()const{return this->nombre;};

void DataUsuario::setNombre(string nom){this->nombre = nom;}

DataEstudiante::DataEstudiante(string nick, string contra, string descripcion, string nombre, string pais, Fecha fecNac):DataUsuario(nick, contra, descripcion, nombre), pais(pais),fecNac(fecNac){};

DataEstudiante::DataEstudiante(string pais, Fecha fecNac):pais(pais), fecNac(fecNac){}

string DataEstudiante::getPais()const{return this->pais;}

Fecha DataEstudiante::getFechaNac()const{return this->fecNac;}

DataProfesor::DataProfesor(string nick, string contra, string descripcion, string nombre, string insti, list<DataIdioma> idiomas):DataUsuario(nick, contra, descripcion, nombre), instituto(insti),idiomas(idiomas){};

DataProfesor::DataProfesor(string insti): instituto(insti){};

DataProfesor::DataProfesor(string insti, list<DataIdioma> idiomas): instituto(insti), idiomas(idiomas){};   

string DataProfesor::getInstituto()const{return this->instituto;}

list<DataIdioma> DataProfesor::getIdiomas()const{return this->idiomas;}

std::ostream & operator<<(std::ostream& os, const DataUsuario& du){
    os << "Nickname: " << du.getNick() << endl 
       << "Descripcion: " << du.getDescripcion() << endl
       <<  "Nombre: " << du.getNombre() << endl;
    return os;
}

std::ostream & operator<<(std::ostream& os, const DataEstudiante& de){
    os << "Nickname: " << de.getNick() << endl 
       << "Descripcion: " << de.getDescripcion() << endl
       << "Nombre: " << de.getNombre() << endl
       << "Pais: " << de.getPais() << endl
       << "Fecha de Nacimiento: " << de.getFechaNac() <<endl;
    return os;
}

static string listaAString(list<DataIdioma> idiomas){
    string cadena = "Idiomas: ";
	if (idiomas.empty()) {cadena += "";}
	else if (idiomas.size() == 1){cadena += idiomas.begin()->getNombre() + ".";}
	else {
		auto it = idiomas.begin();
		cadena += it->getNombre();
		it++;
			while (it != idiomas.end()) {
				cadena += ", " + it->getNombre();
				it++;
		}
		cadena += ".";
	}
	return cadena;
}

std::ostream & operator<<(std::ostream& os, const DataProfesor& dp){
    os << "Nickname: " << dp.getNick() << endl 
       << "Descripcion: " << dp.getDescripcion() << endl
       << "Nombre: " << dp.getNombre() << endl
       << "Instituto: " << dp.getInstituto() <<endl
       << listaAString(dp.getIdiomas()) << endl;
    return os;
}