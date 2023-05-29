#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/curso.h"

using namespace std;

Curso::Curso(string nombreCurso, string desc, dif Dif){
    nomCurso = nombreCurso;
    descripcion = desc;
    dificultad = Dif;
    habilitado = false;
}

Inscripcion* Curso::encontrarIns(Estudiante* e){
    set<Inscripcion*>::iterator it = inscriptos.begin();
    Inscripcion* ins = nullptr;
    while(it != inscriptos.end()){
        if((*it)->getEstudiante() == e){
            ins = *it;
            break;
        }
        ++it;
    }
    return ins;
}

 bool Curso::noAprobadoCurso(Estudiante* e){
    Inscripcion* ins = encontrarIns(e);
    int p = ins->obtenerProgreso();
    return p == 100;
 }

 void Curso::nuevaLeccion(string nomTema, string objLeccion){
    Leccion* L = new Leccion(nomTema, descripcion);
    lecciones.insert(L);
 }

 void Curso::eliminarContenido(){
    for(auto it = lecciones.begin(); it != lecciones.end(); ++it){
        delete *it;
    }
    lecciones.clear();
 }

 void Curso::eliminarInscripciones(){
    for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
        delete *it;
    }
    inscriptos.clear();
 }

 void Curso::eliminarNotificaciones(){
    idioma->eliminarNotif(nomCurso);
 }

 int Curso::obtenerCantEjerciciosCurso(){
    int cec = 0;
    for(auto it = lecciones.begin(); it != lecciones.end(); ++it){
        cec += (*it)->obtenerCantEjerciciosLeccion(); 
    }
    return cec;
 }

 int Curso::obtenerPromedioCurso(){
    int cantIns = inscriptos.size();
    int progT = 0;
    for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
        progT += (*it)->obtenerProgreso();
    }
    return progT/cantIns*100;
 }


 bool Curso::getHab(){
    return habilitado;
 }

 set<Curso*> Curso::getPrevias(){
    return previas;
 }

 set<Leccion*> Curso::getLecciones(){
    return lecciones;
 }

 void Curso::setProfesor(Profesor* p){
    profe = p;
 }

 void Curso::setIdioma(Idioma* idi){
    idioma = idi;
 }