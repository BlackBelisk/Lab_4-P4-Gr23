#ifndef _CLASSCURSO_H_
#define _CLASSCURSO_H_

#include <iostream>
#include <set>

using namespace std;

enum dif {Principiante, Intermedio, Avanzado};
class Profesor;
class Idioma;
class Inscripcion;
class Leccion;

/*
class Lecciones{
        public:
                Leccion* lec;
                Lecciones* sigLec;
                Lecciones();
                Lecciones(Leccion lec);
};
*/

class Curso{
    public:
            string nomCurso;
            string descripcion;
            dif dificultad;
            Idioma* idioma;
            Profesor* profe;
            set<Leccion*> lecciones;
            set<Inscripcion*> inscriptos;

            
    private:
            Inscripcion* encontrarIns(Estudiante*);
            bool noAprobadoCurso(Estudiante*);
            void nuevaLeccion(string, string);
            void eliminarContenido();
            void eliminarInscripciones();
            void eliminarNotificaciones();
            int obtenerCantEjerciciosCurso();
            int obtenerPromedioCurso();
};

#include "profesor.h"
#include "idioma.h"
#include "inscripcion.h"
#include "leccion.h"
#endif