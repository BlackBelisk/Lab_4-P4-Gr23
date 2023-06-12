#include <stdio.h>
#include <iostream>
#include <set>
#include <list>
#include "../include/dataLeccion.h"


DataLeccion::DataLeccion(string t, string o, list<DataEjercicio> e){
    tema = t;
    objetivo = o;
    ejs = e;
}

string DataLeccion::getTema()const{
    return tema;
}

string DataLeccion::getObjetivo()const{
    return objetivo;
}

list<DataEjercicio> DataLeccion::getEjs()const{
    return ejs;
}

string DataLeccion::ejsToString(){
   string s = "";
   for(auto it = ejs.begin(); it != ejs.end(); ++it){
      s += (*it).toString() + "\n";
   }
   return s;
}

string DataLeccion::toString(){
    return "Tema: " + tema + "\n" + "Objetivo: " + objetivo + "\n" + "Ejercicios: " + ejsToString() + "\n";
}