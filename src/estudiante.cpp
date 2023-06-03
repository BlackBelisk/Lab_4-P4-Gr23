#include <iostream>
#include <string>
#include <list>
#include "../include/estudiante.h"
using namespace std;

Estudiante::Estudiante(string nick, string contra, string descripcion, string nombre, string pais, Fecha fecNac):Usuario(nick, contra, descripcion, nombre), pais(pais), fecNac(fecNac){};

Estudiante::Estudiante(DataUsuario dataU, DataEstudiante dataE):Usuario(dataU.getNick(), dataU.getContra(),dataU.getDescripcion(),dataU.getNombre()), pais(dataE.getPais()), fecNac(dataE.getFechaNac()){}

Estudiante::Estudiante(DataEstudiante dataE):Usuario(dataE.getNick(), dataE.getContra(),dataE.getDescripcion(),dataE.getNombre()), pais(dataE.getPais()), fecNac(dataE.getFechaNac()){}

DataEstudiante Estudiante::getDataEstudiante(){return DataEstudiante(this->nick, "", this->descripcion, this->nombre, this->pais, this->fecNac);}

void Estudiante::removerInscripcion(Inscripcion* ins){
    this->inscripciones.erase(ins->getCurso()->getNombre());
}

Inscripcion* Estudiante::encontrarInscripcion(string Curso){this->inscripciones.find(Curso);}