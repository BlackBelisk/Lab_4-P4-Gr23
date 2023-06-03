#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataCurso.h"


DataCurso::DataCurso(string nom, string desc, dif d, DataIdioma* i, DataProfesor* p, vector<DataLeccion*> lec, set<DataInscripcion*> ins, set<DataCurso*> prevs){
    nomCurso = nom;
    descripcion = desc;
    dificultad = d;
    idioma = i;
    profe = p;
    lecciones = lec;
    inscriptos = ins;
    previas = prevs;
}