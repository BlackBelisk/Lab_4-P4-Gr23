#include <stdio.h>
#include <iostream>
#include "../include/leccion.h"

using namespace std;

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