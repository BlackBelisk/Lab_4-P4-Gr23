#ifndef _CLASSCONTROLADORESTADISTICAS_H_
#define _CLASSCONTROLADORESTADISTICAS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "IControladorEstadisticas.h"
#include "curso.h"
#include "profesor.h"
#include "estudiante.h"

#include "dataUsuario.h"
#include "dataEstadistica.h"
#include "dataCurso.h"
using namespace std;

class ControladorEstadisticas: public IControladorEstadisticas{
    private:
        static ControladorEstadisticas * instancia;
        ControladorEstadisticas() = default;
    public:
        static ControladorEstadisticas* getInstance();

        void seleccionarEstadisticaDeseada(eleccion estad);
        DataEstadisticaEstudiante listarEstadisticaEstudiante(DataEstudiante estud);
        DataEstadisticaProfesor listarEstadisticaProfesor(DataProfesor profe);
        DataEstadisticaCurso listarEstadisticaCurso(DataCurso curso);
};

#endif