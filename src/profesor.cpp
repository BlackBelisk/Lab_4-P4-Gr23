#include <iostream>
#include <string>
#include <list>
#include "../include/profesor.h"
#include "../include/dataUsuario.h"

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

void Profesor::agregarIdioma(Idioma* idi){
    this->especializaciones.insert(idi);
}

void Profesor::agregarCursoAProfesor(Curso* c){
    this->cursosPropuestos.insert(c);
}

void Profesor::removerCurso(Curso* c){
    this->cursosPropuestos.erase(c);
}

