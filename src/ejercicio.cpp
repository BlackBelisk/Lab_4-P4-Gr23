#include "../include/ejercicio.h"

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
using namespace std;

// .cpp para Ejercicio con sus subClases

//Metodos de Ejercicios

Ejercicio::Ejercicio(string descr) {
	this->descripcion = descr;
}

Ejercicio::~Ejercicio(){}

string Ejercicio::getDescripcion() {
	return this->descripcion;
}

void Ejercicio::setDescripcion(string descr) {
	this->descripcion = descr;
}



//Metodos de Traduccion

Traduccion::Traduccion(string descr, string frase, string sol):Ejercicio(descr){
	this->solucion = sol;
	this->fraseTrad = frase;
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
bool Traduccion::esEjercicioCorrecto(string respuesta) {
	return (this->solucion == respuesta);
}



//Metodos de CompletarPalabra

//Constructor y Destructor
CompletarPalabra::CompletarPalabra(string descr, string frase, vector<string> vectorSol):Ejercicio(descr){
	this->solucion = vectorSol;
	this->fraseAComp = frase;
}

CompletarPalabra::~CompletarPalabra(){}

//Gets y Sets

void CompletarPalabra::setSolucionComp(vector<string> vectorSol) {
	this->solucion = vectorSol;
}
void CompletarPalabra::setFraseAComp(string frase) {
	this->fraseAComp = frase;
} 
vector<string> CompletarPalabra::getSolucionComp() {
	return this->solucion;
}
string CompletarPalabra::getFraseAComp() {
	return this->fraseAComp;
}


//PreCondicion: Solucion y Respuesta tienen la misma cantidad de elementos
bool CompletarPalabra::esEjercicioCorrecto(vector<string> respuesta) {
    bool result = true;
    int i = 0;
    while(i < solucion.size() && result){
      result = solucion[i]==respuesta[i];
      i++;
    }
    return result;
        	
}


string CompletarPalabra::solToString(){
   string s = "";
   for(int i = 0; i < solucion.size(); i++){
      s += solucion[i] + " ";
   }
   return s;
}

string Traduccion::toString(){
	return "Descripcion: " + descripcion + "\n" + "Frase: " + fraseTrad + "\n" + "Solucion: " + solucion + "\n";
}

string CompletarPalabra::toString(){
	return "Descripcion: " + descripcion + "\n" + "Frase: " + fraseAComp + "\n" + "Solucion: " + solToString() + "\n";
}

DataEjercicio Traduccion::ejToData(){
	DataTraducir e(descripcion, fraseTrad, solucion);
	return e;
}

DataEjercicio CompletarPalabra::ejToData(){
	DataCompletar e(descripcion, fraseAComp, solucion);
	return e;
}
