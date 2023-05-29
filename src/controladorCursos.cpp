#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/controladorCursos.h"


using namespace std;

Estudiante* ControladorCursos::getEstudianteSeleccionado(){
    return estud;
}

Curso* ControladorCursos::getCurso(){
    return curso;
}

Profesor* ControladorCursos::getProfesorElegido(){
    return profe;
}

Idioma* ControladorCursos::getIdiomaElegido(){
    return idi;
}


void ControladorCursos::crearCurso(string nomCurso, string descCurso, dif difCurso){
    curso = new Curso(nomCurso, descCurso, difCurso);
    cursos.insert(curso);
}

unordered_set<Curso*> ControladorCursos::cursosNoAprobadosEstudiante(){
    Estudiante* e = getEstudianteSeleccionado();
    unordered_set<Curso*> cursosNA;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if((*it)->noAprobadoCurso(e)){
            cursosNA.insert(*it);
        }
    }
    return cursosNA;
}

//Falta
void ControladorCursos::elegirProfesor(string nickProfesor){
    
}

unordered_set<Curso*> ControladorCursos::listarCursosHab(){
    unordered_set<Curso*> cursosHab;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if((*it)->getHab()){
            cursosHab.insert(*it);
        }
    }
    return cursosHab;
}

void ControladorCursos::agregarPrevia(Curso* nPrevia){
    Curso* c = getCurso();
    c->getPrevias().insert(nPrevia);
}

void ControladorCursos::agregarLeccionCN(string nomTema, string objLeccion){
    Curso* c = getCurso();
    c->nuevaLeccion(nomTema, objLeccion);
}

//Falta
 void ControladorCursos::agregarEjercicio(string desc, Leccion* lec){

 }

 void ControladorCursos::finalizarAltaCurso(){
    Curso* c = getCurso();
    Profesor* p = getProfesorElegido();
    Idioma* i = getIdiomaElegido();
    c->setProfesor(p);
    c->setIdioma(i);
    //Función agregar curso a profesor
    i->notificarCursoNuevo(c);
    delete curso;
    delete idi;
    delete profe;
 }