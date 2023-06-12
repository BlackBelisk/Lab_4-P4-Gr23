#include <stdio.h>
#include <iostream>
#include <list>
#include "../include/dataInscripcion.h"


DataInscripcion::DataInscripcion(string e, string c, DataLeccion l, list<DataEjercicio> es, Fecha f, bool a){
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