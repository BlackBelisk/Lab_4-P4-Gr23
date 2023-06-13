#include <iostream>
#include <string>
#include <list>
#include <set>
#include "../include/profesor.h"
#include "../include/idioma.h"
#include "../include/dataUsuario.h"
#include "../include/dataIdioma.h"

Profesor::Profesor(string nick, string contra, string desc, string nombre, string instituto, set<Idioma*> idiomas){
    this->setNick(nick);
    this->setContra(contra);
    this->setDescripcion(desc);
    this->setNombre(nombre);
    this->instituto = instituto;
    this->especializaciones = idiomas;
}

Profesor::Profesor(DataUsuario du, DataProfesor dp){
    this->setNick(du.getNick());
    this->setContra(du.getContra());
    this->setDescripcion(du.getDescripcion());
    this->setNombre(dp.getNombre());
    this->instituto = (dp.getInstituto());
}

Profesor::Profesor(DataProfesor dp){
    this->setNick(dp.getNick());
    this->setContra(dp.getContra());
    this->setDescripcion(dp.getDescripcion());
    this->setNombre(dp.getNombre());
    this->instituto = (dp.getInstituto());
}

string Profesor::getInstituto(){return this->instituto;}

set<Curso*> Profesor::getCursosProp(){ return this->cursosPropuestos;}

void Profesor::agregarIdioma(Idioma* idi){
    this->especializaciones.insert(idi);
}

void Profesor::agregarCursoAProfesor(Curso* c){
    this->cursosPropuestos.insert(c);
}

void Profesor::removerCurso(Curso* c){
    this->cursosPropuestos.erase(c);
}

set<Idioma*> Profesor::getEspecializaciones(){
    return this->especializaciones;
};

list <DataIdioma> Profesor::obtenerIdiomas(){
    list<DataIdioma> idiomas;
    for (auto it = this->especializaciones.begin(); it != this->especializaciones.end(); it++)
    {
        idiomas.insert(idiomas.end(),(*it)->getDataIdioma());
    }
    return idiomas;
}

DataProfesor Profesor::getDataProfesor(){return DataProfesor(this->getNick(),"",this->getDescripcion(),this->getNombre(),this->instituto,this->obtenerIdiomas());}