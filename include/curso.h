#ifndef _CLASSCURSO_H_
#define _CLASSCURSO_H_

#include <iostream>
#include <string>
#include <set>
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
            vector<Leccion*> lecciones;
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
            string leccionesToString();
            string inscriptosToString();
            string enumToString();

            bool getHab();
            set<Curso*> getPrevias();
            vector<Leccion*> getLecciones();
            Profesor* getProfesor();
            Idioma* getIdioma();
            string getNombre();
            string getDesc();
            dif getDif();
            

            void setProfesor(Profesor* p);
            void setIdioma(Idioma* idi);
            void setHabilitado(bool);

            friend std::ostream& operator<<(std::ostream& os, Curso*& c);
};

#include "profesor.h"
#include "estudiante.h"
#include "idioma.h"
#include "inscripcion.h"
#include "leccion.h"
#endif