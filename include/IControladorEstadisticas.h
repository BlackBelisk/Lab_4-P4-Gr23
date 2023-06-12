#ifndef _CLASSICONTROLADORESTADISTICAS_H_
#define _CLASSICONTROLADORESTADISTICAS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "dataEstadistica.h"

using namespace std;

class IControladorEstadisticas{
    public:
        virtual DataEstadisticaEstudiante listarEstadisticaEstudiante(DataEstudiante) = 0;
        virtual DataEstadisticaProfesor listarEstadisticaProfesor(DataProfesor) = 0;
        virtual DataEstadisticaCurso listarEstadisticaCurso(DataCurso) = 0;
        virtual ~IControladorEstadisticas(){};
};

#endif