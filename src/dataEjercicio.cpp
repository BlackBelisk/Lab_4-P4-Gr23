#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataEjercicio.h"



DataEjercicio::DataEjercicio(string d, string f, string s): desc(d), fraseTrad(f), solTrad(s){
    tipo = 0;
}

DataEjercicio::DataEjercicio(string d, string f, vector<string> sol): desc(d), fraseComp(f), solComp(sol){
    tipo = 1;
}

string DataEjercicio::getDesc()const{
    return desc;
}

string DataEjercicio::getFraseC()const{
    return fraseComp;
}

vector<string> DataEjercicio::getSolC()const{
    return solComp;
}

string DataEjercicio::getFraseT()const{
    return fraseTrad;
}

string DataEjercicio::getSolT()const{
    return solTrad;
}

string DataEjercicio::solToString(){
   string s = "";
   for(int i = 0; i < solComp.size(); i++){
      s += solComp[i] + ", ";
   }
   return s;
}

string DataEjercicio::toString(){
    if(tipo == 0){
	    return "Descripcion: " + desc + "\n" + "Frase: " + fraseTrad + "\n" + "Solucion: " + solTrad + "\n";
    }else{
        return "Descripcion: " + desc + "\n" + "Frase: " + fraseComp + "\n" + "Solucion: " + solToString() + "\n";
    }
}

string DataEjercicio::mostrarEj(){
     if(tipo == 0){
	    return "Descripcion: " + desc + "\n" + "Traduzca la frase: " + fraseTrad + "\n";
    }else{
        return "Descripcion: " + desc + "\n" + "Complete la frase: " + fraseComp + "\n";
    }
}