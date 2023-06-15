#include <stdio.h>
#include <iostream>
#include <list>
#include "../include/dataInscripcion.h"


DataInscripcion::DataInscripcion(string n, string e, string c, DataLeccion l, list<DataEjercicio> es, Fecha f, bool a){
    nickEstud = n;
    estud = e;
    curso = c;
    lecActual = l;
    ejsCompletados = es;
    fechaIns = f;
    aprobado = a;
}

string DataInscripcion::toString(){
    return "Nombre: " + estud + "\n" + "Fecha de inscripción: " + fechaIns.toString() + "\n";
}

string DataInscripcion::getNickEstud()const{
    return nickEstud;
}

string DataInscripcion::getEstudiante()const{
    return estud;
}
string DataInscripcion::getCurso()const{
    return curso;
}
DataLeccion DataInscripcion::getLecActual()const{
    return lecActual;
}
list<DataEjercicio> DataInscripcion::getEjsCompletados(){
    return ejsCompletados;
}
Fecha DataInscripcion::getFechaIns()const{
    return fechaIns;
}
bool DataInscripcion::getAprobado()const{
    return aprobado;
}

