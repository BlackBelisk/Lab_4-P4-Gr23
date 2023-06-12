#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataEjercicio.h"



DataEjercicio::DataEjercicio(string d): desc(d){
}

DataTraducir::DataTraducir(string d, string f, string sol): DataEjercicio(d), fraseTrad(f), solucion(sol){
}

DataCompletar::DataCompletar(string d, string f, vector<string> sol): DataEjercicio(d), fraseComp(f), solucion(sol){
}

string DataEjercicio::getDesc()const{
    return desc;
}

string DataCompletar::getFrase()const{
    return fraseComp;
}

vector<string> DataCompletar::getSol()const{
    return solucion;
}

string DataTraducir::getFrase()const{
    return fraseTrad;
}

string DataTraducir::getSol()const{
    return solucion;
}

string DataCompletar::solToString(){
   string s = "";
   for(int i = 0; i < solucion.size(); i++){
      s += solucion[i] + " ";
   }
   return s;
}

string DataTraducir::toString(){
	return "Descripcion: " + getDesc() + "\n" + "Frase: " + fraseTrad + "\n" + "Solucion: " + solucion + "\n";
}

string DataCompletar::toString(){
	return "Descripcion: " + getDesc() + "\n" + "Frase: " + fraseComp + "\n" + "Solucion: " + solToString() + "\n";
}