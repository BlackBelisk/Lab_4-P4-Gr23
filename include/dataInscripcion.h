#ifndef _CLASSDATAINSCRIPCION_H_
#define _CLASSDATAINSCRIPCION_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "inscripcion.h"
using namespace std;

class DataEstudiante;
class DataCurso;
class DataLeccion;
class DataEjercicio;

class DataInscripcion{
    public:
            string estud;
            string curso;
            DataLeccion lecActual;
            list<DataEjercicio> ejsCompletados;
            Fecha fechaIns;
            bool aprobado;

            DataInscripcion(string, string, DataLeccion, list<DataEjercicio>, Fecha, bool);
};

#include "dataCurso.h"
#include "dataEjercicio.h"
#include "dataLeccion.h"
#include "dataUsuario.h"
#endif