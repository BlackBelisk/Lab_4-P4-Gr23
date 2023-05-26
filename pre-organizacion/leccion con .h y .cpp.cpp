// .h para leccion

#ifndef LECCION_H
#define LECCION_H

#include <string>
#include <vector>
using namespace std;

class Leccion {
private:
  string tema;
  string objetivo;
  vector<DataEjercicio> ejercicios;// supongo que hacerlo asi es una opcion.

public:
  Leccion(string tema, string objetivo);

  void setTema(string nuevoTema);
  void setObjetivo(string nuevoObjetivo);
  void agregarEjercicio(DataEjercicio ejercicio);
  int obtenerCantEjerciciosLeccion();
  void eliminarEjercicios();

};

#endif 

// implementacion de Leccion

#include "Leccion.h"
#include <iostream>

Leccion::Leccion(string tema, string objetivo) {
  this->tema = tema;
  this->objetivo = objetivo;
}

void Leccion::setTema(string nuevoTema) {
  tema = nuevoTema;
}

void Leccion::setObjetivo(string nuevoObjetivo) {
  objetivo = nuevoObjetivo;
}

void Leccion::agregarEjercicio(DataEjercicio ejercicio) {
  ejercicios.push_back(ejercicio);
}

int Leccion::obtenerCantEjerciciosLeccion(){
  return ejercicios.size();
}

void Leccion::eliminarEjercicios() {
  ejercicios.clear();
}

