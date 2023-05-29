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

    public:
            Inscripcion(Estudiante*, Curso*);
            Estudiante* getEstudiante();
            Curso* getCurso();
            void agregarCompletado(Ejercicio*);
            int obtenerProgreso();
            ~Inscripcion();


};

#include "estudiante.h"
#include "curso.h"
#include "leccion.h"
#include "ejercicio.h"
#endif