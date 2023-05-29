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

Leccion::~Leccion(){
    eliminarEjercicios();
}