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
    private:
            string nomCurso;
            string descripcion;
            dif dificultad;
            bool habilitado;  
            DataIdioma idioma;
            DataProfesor profe;
            vector<DataLeccion> lecciones;
            list<DataInscripcion> inscriptos;
            list<DataCurso> previas;
            int cantEjercicios;
    public:
            string getNomCurso()const;
            string getDesc()const;
            dif getDif()const;
            bool getHab()const;
            DataIdioma getIdi()const;
            DataProfesor getProfe()const;
            vector<DataLeccion> getLecciones()const;
            list<DataInscripcion> getIns()const;
            list<DataCurso> getPrevias()const;
            int getCantEjercicios()const;

            string enumToString();
            string leccionesToString();
            string inscriptosToString();
            friend std::ostream& operator<<(std::ostream& os, DataCurso& c);
            DataCurso(string, string, dif, bool, DataIdioma, DataProfesor, vector<DataLeccion>, list<DataInscripcion>, list<DataCurso>, int);
};

#endif