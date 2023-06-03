#ifndef _CLASSDATACURSO_H_
#define _CLASSDATACURSO_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "curso.h"
#include "dataUsuario.h"
#include "dataIdioma.h"
#include "dataInscripcion.h"
#include "dataLeccion.h"

using namespace std;

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
            
            DataCurso(string, string, dif, DataIdioma*, DataProfesor*, vector<DataLeccion*>, set<DataInscripcion*>, set<DataCurso*>);
};


#endif