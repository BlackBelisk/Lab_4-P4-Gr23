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

string DataUsuario::getNick(){this->nick;};

string DataUsuario::getContra(){this->contra;}

string DataUsuario::getDescripcion(){this->descripcion;};

string DataUsuario::getNombre(){this->nombre;};

DataEstudiante::DataEstudiante(string nick, string contra, string descripcion, string nombre, string pais, Fecha fecNac):DataUsuario(nick, contra, descripcion, nombre), pais(pais),fecNac(fecNac){};

DataEstudiante::DataEstudiante(string pais, Fecha fecNac):pais(pais), fecNac(fecNac){}

DataProfesor::DataProfesor(string nick, string contra, string descripcion, string nombre, string insti, list<DataIdioma> idiomas):DataUsuario(nick, contra, descripcion, nombre), instituto(insti),idiomas(idiomas){};

DataProfesor::DataProfesor(string insti): instituto(insti){};

DataProfesor::DataProfesor(string insti, list<DataIdioma> idiomas): instituto(insti), idiomas(idiomas){};    