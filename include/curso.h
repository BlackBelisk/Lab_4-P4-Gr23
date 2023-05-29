#ifndef _CLASSCURSO_H_
#define _CLASSCURSO_H_

#include <iostream>
#include <set>

using namespace std;

enum dif {Principiante, Intermedio, Avanzado};
class Profesor;
class Estudiante;
class Idioma;
class Inscripcion;
class Leccion;

class Curso{
    private:
            string nomCurso;
            string descripcion;
            dif dificultad;
            bool habilitado;  
            Idioma* idioma;
            Profesor* profe;
            set<Leccion*> lecciones;
            set<Inscripcion*> inscriptos;
            set<Curso*> previas;
            
    public:
            Curso(string, string, dif);    
            Inscripcion* encontrarIns(Estudiante*);
            bool noAprobadoCurso(Estudiante*);
            void nuevaLeccion(string, string);
            void eliminarContenido();
            void eliminarInscripciones();
            void eliminarNotificaciones();
            int obtenerCantEjerciciosCurso();
            int obtenerPromedioCurso();

            bool getHab();
            set<Curso*> getPrevias();
            set<Leccion*> getLecciones();

            void setProfesor(Profesor* p);
            void setIdioma(Idioma* idi);

};

#include "profesor.h"
#include "estudiante.h"
#include "idioma.h"
#include "inscripcion.h"
#include "leccion.h"
#endif