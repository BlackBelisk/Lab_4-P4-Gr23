#ifndef _CLASSCHILD_H_
#define _CLASSCHILD_H_

#include <iostream>
#include <set>

using namespace std;

enum dif {Principiante, Intermedio, Avanzado};
class Usuario;
class Idioma;
class Inscripcion;

class Curso{
    public:
            string nomCurso;
            string descripcion;
            dif dificultad;
            
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
#endif