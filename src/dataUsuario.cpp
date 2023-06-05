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

string DataUsuario::getNick(){return this->nick;};

string DataUsuario::getContra(){return this->contra;}

string DataUsuario::getDescripcion(){return this->descripcion;};

string DataUsuario::getNombre(){return this->nombre;};

DataEstudiante::DataEstudiante(string nick, string contra, string descripcion, string nombre, string pais, Fecha fecNac):DataUsuario(nick, contra, descripcion, nombre), pais(pais),fecNac(fecNac){};

DataEstudiante::DataEstudiante(string pais, Fecha fecNac):pais(pais), fecNac(fecNac){}

string DataEstudiante::getPais(){return this->pais;}

Fecha DataEstudiante::getFechaNac(){return this->fecNac;}

DataProfesor::DataProfesor(string nick, string contra, string descripcion, string nombre, string insti, list<DataIdioma> idiomas):DataUsuario(nick, contra, descripcion, nombre), instituto(insti),idiomas(idiomas){};

DataProfesor::DataProfesor(string insti): instituto(insti){};

DataProfesor::DataProfesor(string insti, list<DataIdioma> idiomas): instituto(insti), idiomas(idiomas){};   

string DataProfesor::getInstituto(){return this->instituto;}

list<DataIdioma> DataProfesor::getIdiomas(){return this->idiomas;}

std::ostream & operator<<(std::ostream& os, const DataUsuario& du){
    os << "Nickname: " << du.nick << endl 
       << "Descripcion: " << du.descripcion << endl
       <<  "Nombre: " << du.nombre << endl;
    return os;
}

std::ostream & operator<<(std::ostream& os, const DataEstudiante& de){
    os << "Nickname: " << de.nick << endl 
       << "Descripcion: " << de.descripcion << endl
       << "Nombre: " << de.nombre << endl
       << "Pais: " << de.pais << endl
       << "Fecha de Nacimiento: " << de.fecNac <<endl;
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
    os << "Nickname: " << dp.nick << endl 
       << "Descripcion: " << dp.descripcion << endl
       << "Nombre: " << dp.nombre << endl
       << "Instituto: " << dp.instituto <<endl
       << "Idiomas: " << listaAString(dp.idiomas) << endl;
    return os;
}