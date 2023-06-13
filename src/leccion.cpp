#include <stdio.h>
#include <iostream>
#include <list>
#include "../include/leccion.h"

using namespace std;


list<DataEjercicio> Leccion::ejsToData(){ 
    list<DataEjercicio> es;
    for(auto it = ejs.begin(); it != ejs.end(); ++it){
        DataEjercicio de = (*it)->ejToData();
        es.insert(es.end(),de);            
    }
    return es;
}

DataLeccion Leccion::lToData(){
    DataLeccion l(tema, objetivo, ejsToData());
    return l;
}

void Leccion::agregarEjercicio(Ejercicio* e){
    ejs.insert(e);
}

void Leccion::eliminarEjercicios(){
    for(auto it = ejs.begin(); it != ejs.end(); ++it){
        delete *it;
    }
    ejs.clear();
}

int Leccion::obtenerCantEjerciciosLeccion(){
    return ejs.size();
}

string Leccion::ejsToString(){
   string s = "";
   for(auto it = ejs.begin(); it != ejs.end(); ++it){
      s += (*it)->toString() + "\n";
   }
   return s;
}

string Leccion::toString(){
    return "Tema: " + tema + "\n" + "Objetivo: " + objetivo + "\n" + "Ejercicios: " + ejsToString() + "\n";
}

Leccion::~Leccion(){
    eliminarEjercicios();
}

Ejercicio* Leccion::obtenerEj(string descEj){
    Ejercicio* e = nullptr;
    for(auto it = ejs.begin(); it != ejs.end(); ++it){
        if((*it)->getDescripcion() == descEj){
            e = (*it);
        }
    }
    return e;
}

set<Ejercicio*> Leccion::getEjs(){
    return ejs;
}

string Leccion::getObj(){
    return objetivo;
}