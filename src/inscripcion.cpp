#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/inscripcion.h"

using namespace std;

Inscripcion::~Inscripcion(){
    
}

Inscripcion::Inscripcion(Estudiante* e, Curso* c, Fecha f){
    estud = e;
    curso = c;
    lecActual = *c->getLecciones().begin();
    fechaIns = f;
    aprobado = false;
}

DataInscripcion Inscripcion::insToData(){
    list<DataEjercicio> es;
    for(auto it = ejsCompletados.begin(); it != ejsCompletados.end(); ++it){
        DataEjercicio de = (*it)->ejToData();
        es.insert(es.end(),de);            
    }
    DataInscripcion di(estud->getNombre(), curso->getNombre(), lecActual->lToData(), es, fechaIns, aprobado);
    return di;
}

void Inscripcion::agregarCompletado(Ejercicio* e){
    ejsCompletados.insert(e);
}

int Inscripcion::obtenerProgreso(){
    int cantEjRes = ejsCompletados.size();
    int cec = curso->obtenerCantEjerciciosCurso();
    return cantEjRes/cec*100;
}

void Inscripcion::removerInscripcion(){
    estud->removerInscripcion(this);
}

string Inscripcion::toString(){
    return "Nombre: " + estud->getNombre() + "\n" + "Fecha de inscripción: " + fechaIns.toString() + "\n";
}


 Estudiante* Inscripcion::getEstudiante(){
    return estud;
 }

 Curso* Inscripcion::getCurso(){
    return curso;
 }