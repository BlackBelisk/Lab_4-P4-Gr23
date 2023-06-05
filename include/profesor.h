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
        Profesor(string nick, string contra, string desc, string nombre, string instituto, set<Idioma*> idiomas);
        Profesor(DataUsuario, DataProfesor);
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