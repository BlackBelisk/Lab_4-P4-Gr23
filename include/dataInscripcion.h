#ifndef _CLASSDATAINSCRIPCION_H_
#define _CLASSDATAINSCRIPCION_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "inscripcion.h"
#include "dataLeccion.h"
#include "dataEjercicio.h"

using namespace std;

class DataEstudiante;
class DataCurso;
class DataInscripcion{
    public:
            string estud;
            string curso;
            DataLeccion lecActual;
            list<DataEjercicio> ejsCompletados;
            Fecha fechaIns;
            bool aprobado;

            DataInscripcion(string, string, DataLeccion, list<DataEjercicio>, Fecha, bool);
            string toString();
};

#include "dataCurso.h"
#include "dataUsuario.h"
#endif