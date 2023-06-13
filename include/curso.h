#ifndef _CLASSCURSO_H_
#define _CLASSCURSO_H_

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>

using namespace std;

enum dif {Principiante, Intermedio, Avanzado};
class Profesor;
class Estudiante;
class Idioma;
class Inscripcion;
class Leccion;
class DataCurso;
class DataLeccion;
class DataInscripcion;
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
            Curso(DataCurso);
            Inscripcion* encontrarIns(Estudiante*);
            bool noAprobadoCurso(Estudiante*);
            void nuevaLeccion(string, string);
            void eliminarContenido();
            void eliminarInscripciones();
            void eliminarNotificaciones();
            int obtenerCantEjerciciosCurso();
            float obtenerPromedioCurso();
            string leccionesToString();
            string inscriptosToString();
            string enumToString();
            vector<DataLeccion> lecToData();
            list<DataInscripcion> insToData();
            list<DataCurso> preToData();
            DataCurso cursoToData();
            Leccion* siguienteLec(Leccion*);
            void agregarInscripto(Inscripcion*);
            

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
#include "dataCurso.h"
#include "dataLeccion.h"
#include "dataInscripcion.h"
#endif