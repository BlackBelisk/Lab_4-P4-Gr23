#ifndef _CLASSPROFESOR_H_
#define _CLASSPROFESOR_H_

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;
#include "usuario.h"
#include "idioma.h"
#include "dataUsuario.h"

class Profesor : public Usuario{
    private:
        string instituto;
        set<Idioma*> especializaciones;
        set<Curso*> cursosPropuestos;
    public:
        //Creador directo de Profesor
        Profesor(string nick, string contra, string desc, string nombre, string instituto, set<Idioma*> idiomas);
        
        //Creador indirecto de Profesor por medio de Datatypes, los idiomas son setteados luego
        Profesor(DataUsuario, DataProfesor);

        //Creador indirecto de Profesor por medio de Datatypes, los idiomas son setteados luego
        Profesor(DataProfesor);

        string getInstituto();

        DataProfesor getDataProfesor();
    
        void agregarIdioma(Idioma*);

        void agregarCursoAProfesor(Curso*);
        void removerCurso(Curso*);
    
        vector<int> obtenerPromediosProfesor();

        vector<Idioma*> obtenerIdiomasProfesor();


};

#endif