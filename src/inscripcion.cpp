#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/inscripcion.h"

using namespace std;

Inscripcion::~Inscripcion(){
    
}

Inscripcion::Inscripcion(Estudiante* e, Curso* c){
    estud = e;
    curso = c;
    lecActual = *c->getLecciones().begin();
}

void Inscripcion::agregarCompletado(Ejercicio* e){
    ejsCompletados.insert(e);
}

int Inscripcion::obtenerProgreso(){
    int cantEjRes = ejsCompletados.size();
    int cec = curso->obtenerCantEjerciciosCurso();
    return cantEjRes/cec*100;
}

 Estudiante* Inscripcion::getEstudiante(){
    return estud;
 }

 Curso* Inscripcion::getCurso(){
    return curso;
 }