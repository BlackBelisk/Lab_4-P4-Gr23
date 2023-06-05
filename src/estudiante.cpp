#include <iostream>
#include <string>
#include <list>
#include "../include/estudiante.h"
using namespace std;

Estudiante::Estudiante(string nick, string contra, string descripcion, string nombre, string pais, Fecha fecNac){
    this->setNick(nick);
    this->setContra(contra);
    this->setDescripcion(descripcion);
    this->setNombre(nombre);
    this->pais = pais;
    this->fecNac = fecNac;
};

Estudiante::Estudiante(DataUsuario dataU, DataEstudiante dataE){
    this->setNick(dataU.getNick());
    this->setContra(dataU.getContra());
    this->setDescripcion(dataU.getDescripcion());
    this->setNombre(dataU.getNombre());
    this->pais = dataE.getPais();
    this->fecNac = dataE.getFechaNac();
}

Estudiante::Estudiante(DataEstudiante dataE){
    this->setNick(dataE.getNick());
    this->setContra(dataE.getContra());
    this->setDescripcion(dataE.getDescripcion());
    this->setNombre(dataE.getNombre());
    this->pais = dataE.getPais();
    this->fecNac = dataE.getFechaNac();
}

DataEstudiante Estudiante::getDataEstudiante(){return DataEstudiante(this->getNick(), "", this->getDescripcion(), this->getNombre(), this->pais, this->fecNac);}

void Estudiante::removerInscripcion(Inscripcion* ins){
    this->inscripciones.erase(ins->getCurso()->getNombre());
}

Inscripcion* Estudiante::encontrarInscripcion(string Curso){this->inscripciones.find(Curso)->second;}