#ifndef _CLASSESTUDIANTE_H_
#define _CLASSESTUDIANTE_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

#include "usuario.h"
#include "inscripcion.h"
#include "fecha.h"
#include "dataUsuario.h"
using namespace std;

class Estudiante : public Usuario{
    private:
    string pais;
    Fecha fecNac; //Acá va fecha
    map<string, Inscripcion*> inscripciones;

    public:
        Estudiante(string, string, string, string, string, Fecha);
        Estudiante(DataUsuario, DataEstudiante);
        Estudiante(DataEstudiante);

        //Tenemos que imprimir la información sobre las inscripciones de los estudiantes en algún punto?
        DataEstudiante getDataEstudiante();
        //Remueve la inscripción ins del conjunto de inscripciones del Estudiante
        void removerInscripcion(Inscripcion* ins);

        //Devuelve la inscripción asociada al curso con nombre nomCurso 
        Inscripcion* encontrarInscripcion(string nomCurso);

        map<string, Inscripcion*> getInscripciones();

        //Devuelve un set de cursos a los cuales el estudiante se encuentra inscripto
        set<Curso*> obtenerCursosEstudiante();

        vector<int> obtenerProgresos();
};

#endif