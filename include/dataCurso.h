#ifndef _CLASSDATACURSO_H_
#define _CLASSDATACURSO_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "dataUsuario.h"
#include "dataIdioma.h"
using namespace std;
class Curso;

class DataCurso{
    public:
            string nomCurso;
            string descripcion;
            dif dificultad;
            bool habilitado;  
            DataIdioma* idioma;
            DataProfesor* profe;
            vector<DataLeccion*> lecciones;
            set<DataInscripcion*> inscriptos;
            set<DataCurso*> previas;
            
            DataCurso(Curso*);
};
#include "curso.h"
#endif