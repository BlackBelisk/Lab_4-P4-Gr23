#ifndef _CLASSCONTROLADORESTADISTICAS_H_
#define _CLASSCONTROLADORESTADISTICAS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "IControladorEstadisticas.h"
#include "estudiante.h"
#include "dataUsuario.h"
#include "dataEstadistica.h"
using namespace std;

class ControladorEstadisticas: public IControladorEstadisticas{
    private:
        static ControladorEstadisticas * instancia;
        Estudiante * estudSeleccionado;

        ControladorEstadisticas();
    public:
        static ControladorEstadisticas* getInstance();

        void seleccionarEstadisticaDeseada(eleccion estad);
        DataEstadisticaEstudiante listarEstadisticaEstudiante(DataEstudiante estud);
        DataEstadisticaProfesor listarEstadisticaProfesor(DataProfesor profe);
        DataEstadisticaCurso listarEstadisticaCurso(DataCurso curso);

};

#endif