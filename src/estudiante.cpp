#include <iostream>
#include <string>
#include <list>
#include <map>
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

void Estudiante::agregarInscripcion(Inscripcion* ins){
    this->enCurso.insert(make_pair(ins->getCurso()->getNombre(), ins));
}

void Estudiante::marcarAprobado(Inscripcion* inscripcion){
    if (this->enCurso.find(inscripcion->getCurso()->getNombre()) != this->enCurso.end())
    {
        this->enCurso.erase(inscripcion->getCurso()->getNombre());
        this->aprobados.insert(make_pair(inscripcion->getCurso()->getNombre(), inscripcion));
    }
}

void Estudiante::removerInscripcion(Inscripcion* ins){
    this->enCurso.erase(ins->getCurso()->getNombre());
    this->aprobados.erase(ins->getCurso()->getNombre());
}

Inscripcion* Estudiante::encontrarInscripcion(string Curso){
    if (this->enCurso.find(Curso) != this->enCurso.end())
    {
        return this->enCurso.find(Curso)->second;
    }
    else if (this->aprobados.find(Curso) != this->aprobados.end())
    {
        return this->aprobados.find(Curso)->second;
    }
    return nullptr;
}

map<string, Inscripcion*> Estudiante::getenCurso(){return this->enCurso;}

map<string, Inscripcion*> Estudiante::getAprobados(){return this->aprobados;}

list<DataInscripcion> Estudiante::obtenerDataInscripciones(){
    list<DataInscripcion> misInscripciones;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misInscripciones.insert(misInscripciones.end(), it->second->insToData());
    }

    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misInscripciones.insert(misInscripciones.end(), it->second->insToData());
    }
    return misInscripciones;   
}

list<DataInscripcion> Estudiante::obtenerDataInscripcionesenCurso(){
     list<DataInscripcion> misInscripciones;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misInscripciones.insert(misInscripciones.end(), it->second->insToData());
    }
    return misInscripciones;
}

list<DataInscripcion> Estudiante::obtenerDataInscripcionesAprobados(){
     list<DataInscripcion> misInscripciones;
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misInscripciones.insert(misInscripciones.end(), it->second->insToData());
    }
    return misInscripciones;
}

set<Curso*> Estudiante::obtenerCursosEstudiante(){
    set<Curso*> misCursos;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misCursos.insert(it->second->getCurso());
    }
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misCursos.insert(it->second->getCurso());
    }
    return misCursos;
}

set<Curso*> Estudiante::obtenerCursosAprobados(){
    set<Curso*> misCursos;
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misCursos.insert(it->second->getCurso());
    }
    return misCursos;
}

set<Curso*> Estudiante::obtenerCursosEnCurso(){
    set<Curso*> misCursos;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misCursos.insert(it->second->getCurso());
    }
    return misCursos;
}

list<DataCurso> Estudiante::obtenerDataCursosEstudiante(){
    list<DataCurso> misCursos;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misCursos.insert(misCursos.end(),it->second->getCurso()->cursoToData());
    }
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misCursos.insert(misCursos.end(),it->second->getCurso()->cursoToData());
    }
    return misCursos;
}

list<DataCurso> Estudiante::obtenerDataCursosEnCurso(){
    list<DataCurso> misCursos;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        misCursos.insert(misCursos.end(),it->second->getCurso()->cursoToData());
    }
    return misCursos;
}

list<DataCurso> Estudiante::obtenerDataCursosAprobados(){
    list<DataCurso> misCursos;
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        misCursos.insert(misCursos.end(),it->second->getCurso()->cursoToData());
    }
    return misCursos;
}

map<string, Inscripcion*> Estudiante::getInscripciones(){
    map<string, Inscripcion*> inscripciones;
    for (auto it = this->enCurso.begin(); it != this->enCurso.end(); it++)
    {
        inscripciones.insert(make_pair(it->second->getCurso()->getNombre(),it->second));
    }
    for (auto it = this->aprobados.begin(); it != this->aprobados.end(); it++)
    {
        inscripciones.insert(make_pair(it->second->getCurso()->getNombre(),it->second));
    }
    return inscripciones;
}