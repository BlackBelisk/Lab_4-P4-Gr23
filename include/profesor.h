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
        //Creador directo de Profesor. El profesor creado NO es agregado a la lista de usuarios ni de profesores
        Profesor(string nick, string contra, string desc, string nombre, string instituto, set<Idioma*> idiomas);
        
        //Creador indirecto de Profesor por medio de Datatypes, los idiomas son setteados luego
        Profesor(DataUsuario, DataProfesor);

        //Creador indirecto de Profesor por medio de Datatypes, los idiomas son setteados luego
        Profesor(DataProfesor);

        //Devuelve el instituto de profesor
        string getInstituto();

        set<Curso*> getCursosProp();

        //Devuelve un set<Idioma*> en los que se especializa un profesor
        set<Idioma*> getEspecializaciones();

        //Devuelve una list<DataIdioma> con los idiomas en los que se especializa un profesor
        list<DataIdioma> obtenerIdiomas();

        //Devuelve el DataProfesor asociado a la información de profesor
        DataProfesor getDataProfesor();
    
        //Agrega el Idioma idi a las especializaciones de profesor
        void agregarIdioma(Idioma* idi);

        //Agrega el curso c a los cursos del profesor
        void agregarCursoAProfesor(Curso* c);

        //Remueve el curso c de los cursos del profesors
        void removerCurso(Curso* c);
};

#endif