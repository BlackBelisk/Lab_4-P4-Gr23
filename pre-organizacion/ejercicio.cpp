#include "../include/ejercicio.h"

#include <string>
#include <iostream>
#include <set>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//Metodos de Ejercicios

Ejercicio::Ejercicio(string descr) {
	this->descripcion = descr;
}

Ejercicio::~Ejercicio(){}

string Ejercicio::getDescripcion() {
	return descripcion;
}

void Ejercicio::setDescripcion(string descr) {
	this->descripcion = descr;
}



//Metodos de Traduccion

Traduccion::Traduccion(string descr, string sol):Ejercicio(descr){
	this->solucion = sol;
}
Traduccion::~Traduccion(){}
string Traduccion::getSolucion(){
	return this->solucion;
}
void Traduccion::setSolucion(string sol){
	this->solucion = sol;
}
string Traduccion::getFraseTrad(){
	return this->fraseTrad;
}
void Traduccion::setFraseTrad(string frase){
	this->fraseTrad = frase;
}
bool Traduccion::esEjercicioCorrecto() {
	return (this->solucion == this->fraseTrad);
}



//Metodos de CompletarPalabra
CompletarPalabra::CompletarPalabra(string descr, set<string> setSol):Ejercicio(descr){
	this->solucion = setSol;
}
CompletarPalabra::~CompletarPalabra(){}
set<string> CompletarPalabra::getSolucion() {
	return this->solucion;
}
void CompletarPalabra::setSolucion(set<string> setSol) {
	this->solucion = setSol;
}
set<string> CompletarPalabra::getFrases() {
	return this->frases;
}
//PreCondicion: la variable setFrases contiene la misma cantidad de elementos que el setSolucion
void CompletarPalabra::setFrases(set<string> setFrases) {
	this->frases = setFrases;
}
//PreCondicion: Solucion y Frases tienen la misma cantidad de elementos
bool CompletarPalabra::esEjercicioCorrecto() {
	return (solucion==frases);
}
