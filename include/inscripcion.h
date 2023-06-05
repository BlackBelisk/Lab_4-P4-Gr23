#ifndef _CLASSINSCRIPCION_H_
#define _CLASSINSCRIPCION_H_

#include <iostream>
#include <set>

using namespace std;
class Estudiante;
class Curso;
class Leccion;
class Ejercicio;

class Inscripcion{
    private:
            Estudiante* estud;
            Curso* curso;
            Leccion* lecActual;
            set<Ejercicio*> ejsCompletados;
            Fecha fechaIns;
            bool aprobado;

    public:
            Inscripcion(Estudiante*, Curso*, Fecha);
            ~Inscripcion();

            void agregarCompletado(Ejercicio*);
            float obtenerProgreso();
            void removerInscripcion();
            string toString();
            DataInscripcion insToData();

            Estudiante* getEstudiante();
            Curso* getCurso();

};

#include "estudiante.h"
#include "curso.h"
#include "leccion.h"
#include "ejercicio.h"
#endif