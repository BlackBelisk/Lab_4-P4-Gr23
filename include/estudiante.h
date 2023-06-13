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

using namespace std;

class DataUsuario;
class DataEstudiante;
class Inscripcion;
class DataInscripcion;
class Curso;

class Estudiante : public Usuario{
    private:
        string pais;
        Fecha fecNac;
        map<string, Inscripcion*> enCurso;
        map<string, Inscripcion*> aprobados;
    public:
        Estudiante(string, string, string, string, string, Fecha);
        Estudiante(DataUsuario, DataEstudiante);
        Estudiante(DataEstudiante);

        //Devuelte la data del estudiante
        DataEstudiante getDataEstudiante();

        //Agrega la inscripcion al map de cursos enCurso del estudiante
        void agregarInscripcion(Inscripcion *);

        //marca como aprobado un curso
        void marcarAprobado(Inscripcion*); //Swap de maps

        //Remueve la inscripción ins del conjunto de inscripciones del Estudiante
        void removerInscripcion(Inscripcion* ins);

        //Devuelve la inscripción asociada al curso con nombre nomCurso 
        Inscripcion* encontrarInscripcion(string nomCurso);

        //Devuelve un map<string nomCurso, Inscripcion*> con las inscripciones de 
        //los cursos en curso del estudiante
        //Key: nomCurso, es el nombre del curso
        map<string, Inscripcion*> getenCurso();

        //Devuelve un map<string nomCurso, Inscripcion*> con las inscripciones de 
        //los cursos aprobados por el estudiante
        //Key: nomCurso, es el nombre del curso
        map<string, Inscripcion*> getAprobados();

        map<string, Inscripcion*> getInscripciones();

        //Devuelve una list<DataInscripcion> con todas las inscripciones del estudiante
        list <DataInscripcion> obtenerDataInscripciones();
        //Devuelve una list<DataInscripcion> con las inscripciones a cursos en curso del estudiante
        list<DataInscripcion> obtenerDataInscripcionesenCurso();
        //Devuelve uba list<DataInscripcion> con las inscripciones de los cursos aprobados por el estudiante
        list<DataInscripcion> obtenerDataInscripcionesAprobados();

        //Devuelve un set con todos los cursos del estudiante
        set<Curso*> obtenerCursosEstudiante();
        //Devuelve un set con los cursos aprobados por el estudiante
        set<Curso*> obtenerCursosAprobados();
        //Devuelve un set con los cursos en curso del estudiante
        set<Curso*> obtenerCursosEnCurso();

        //Devuelve una list<DataCurso> con los datos de todos los cursos del estudiante
        list<DataCurso> obtenerDataCursosEstudiante();
        //Devuelve una list<DataCurso> con los datos de todos los cursos en curso del estudiante
        list<DataCurso> obtenerDataCursosEnCurso();
        //Devuelve una list<DataCurso> con los datos de todos los cursos aprobados por el estudiante
        list<DataCurso> obtenerDataCursosAprobados();
};

#include "dataUsuario.h"
#include "curso.h"
#include "inscripcion.h"
#include "dataInscripcion.h"
#endif