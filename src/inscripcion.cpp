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

Inscripcion::Inscripcion(Estudiante* e, Curso* c, Leccion* l, multimap<Leccion*, Ejercicio*> ejs, Fecha f, bool a){
    estud = e;
    curso = c;
    lecActual = l;
    ejsCompletados = ejs;
    fechaIns = f;
    aprobado = a;
}

DataInscripcion Inscripcion::insToData(){
    list<DataEjercicio> es;
    for(auto it = ejsCompletados.begin(); it != ejsCompletados.end(); ++it){
        DataEjercicio de = (*it).second->ejToData();
        es.insert(es.end(),de);            
    }
    Leccion* act = lecActual;
    if(act == nullptr){
        act = curso->getLecciones().back();
    }
    DataInscripcion di(estud->getNick(), estud->getNombre(), curso->getNombre(), act->lToData(), es, fechaIns, aprobado);
    return di;
}

void Inscripcion::agregarCompletado(Leccion* l, Ejercicio* e){
    ejsCompletados.insert(make_pair(l,e));
}

float Inscripcion::obtenerProgreso(){
    if(aprobado){
        return 100;
    }else{
        int cantEjRes = ejsCompletados.size();
        int cec = curso->obtenerCantEjerciciosCurso();
        return cantEjRes/cec*100;
    }
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

 bool Inscripcion::getAprobado(){
    return aprobado;
 }

 Leccion* Inscripcion::getLecActual(){
    return lecActual;
 }

 void Inscripcion::setLecActual(Leccion* l){
    lecActual = l;
 }
 void Inscripcion::setAprobado(){
    aprobado = true;
 }

 multimap<Leccion*, Ejercicio*> Inscripcion::getEjsCompletados(){
    return ejsCompletados;
 }

 set<Ejercicio*> Inscripcion::getEjsCompletadosLecActual(){
    set<Ejercicio*> es;
    auto r = ejsCompletados.equal_range(lecActual);
    for(auto it = r.first; it != r.second; ++it){
        es.insert((*it).second);
    }
    return es;
 }