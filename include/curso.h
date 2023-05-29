#ifndef _CLASSCURSO_H_
#define _CLASSCURSO_H_

#include <iostream>
#include <set>

using namespace std;

enum dif {Principiante, Intermedio, Avanzado};
class Usuario;
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
            set<Leccion*> lecciones;

            
    private:
            Inscripcion encontrarIns();
            bool noAprobadoCurso();
            void nuevaLeccion();
            void eliminarContenido();
            void eliminarInscripciones();
            void eliminarNotificaciones();
            int obtenerCantEjerciciosCurso();
            int obtenerPromedioCurso();
};

#include "usuario.h"
#include "idioma.h"
#include "inscripcion.h"
#include "leccion.h"
#endif