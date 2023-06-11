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
            DataIdioma idioma;
            DataProfesor profe;
            vector<DataLeccion> lecciones;
            list<DataInscripcion> inscriptos;
            list<DataCurso> previas;
            
            //Luis necesita
            string getNomCurso();
            friend std::ostream& operator<<(std::ostream& os, DataCurso& c);
            DataCurso(string, string, dif, bool, DataIdioma, DataProfesor, vector<DataLeccion>, list<DataInscripcion>, list<DataCurso>);
};

#endif