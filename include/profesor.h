#ifndef _CLASSPROFESOR_H_
#define _CLASSPROFESOR_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;
#include "usuario.h"
#include "idioma.h"

class Profesor : public Usuario{
    private:
    string instituto;
    vector<Idioma*> especializaciones;
    vector<Curso*> cursosPropuestos;
    public:

    void agregarIdioma(Idioma*);

    void agregarCursoAProfesor(Curso*);
    void removerCurso(Curso*);
    
    vector<int> obtenerPromediosProfesor();


    vector<Idioma*> obtenerIdiomasProfesor();


};

#endif