#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataCurso.h"


DataCurso::DataCurso(string n, string d, dif Dif, bool b, DataIdioma i, DataProfesor p, vector<DataLeccion> ls, list<DataInscripcion> is, list<DataCurso> ps){
    nomCurso = n;
    descripcion = d;
    dificultad = Dif;
    habilitado = b;
    idioma = i;
    profe = p;
    lecciones = ls;
    inscriptos = is;
    previas = ps;
}