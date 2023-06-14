#include <stdio.h>
#include <iostream>
#include <set>
#include <list>
#include "../include/dataLeccion.h"


DataLeccion::DataLeccion(string t, string o, list<DataEjercicio> e, int i){
    tema = t;
    objetivo = o;
    ejs = e;
    ID = i;
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

int DataLeccion::getID()const{
    return ID;
}

string DataLeccion::ejsToString(){
   string s = "\n";
   if(ejs.size() == 0){
    s = "No tiene";
   }else{
        int i = 1;
        for(auto it = ejs.begin(); it != ejs.end(); ++it){
            s += "Ejercicio " + to_string(i) + ": " + "\n" + (*it).toString() + "\n";
            i++;
        } 
   }
   return s;
}

string DataLeccion::toString(){
    return "Tema: " + tema + "\n" + "Objetivo: " + objetivo + "\n" + "Ejercicios: " + ejsToString() + "\n";
}