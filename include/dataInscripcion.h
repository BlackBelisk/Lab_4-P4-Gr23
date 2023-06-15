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
    private:
            string nickEstud;
            string estud;
            string curso;
            DataLeccion lecActual;
            list<DataEjercicio> ejsCompletados;
            Fecha fechaIns;
            bool aprobado;
    public:
            DataInscripcion(string, string, string, DataLeccion, list<DataEjercicio>, Fecha, bool);
            string toString();

            string getNickEstud()const;
            string getEstudiante()const;
            string getCurso()const;
            DataLeccion getLecActual()const;
            list<DataEjercicio> getEjsCompletados();
            Fecha getFechaIns()const;
            bool getAprobado()const;
};

#include "dataCurso.h"
#include "dataUsuario.h"
#endif