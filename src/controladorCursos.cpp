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

vector<string> ControladorCursos::getRespuestaEjercicioCompletar(){
    return resComp;
}

Ejercicio* ControladorCursos::getEjercicioSeleccionado(){
    return ejSel;
}


ControladorCursos& ControladorCursos::getInstance(){
    static ControladorCursos instance;
    return instance;
}

void ControladorCursos::crearCurso(string nomCurso, string descCurso, dif difCurso){
    curso = new Curso(nomCurso, descCurso, difCurso);
    cursos.insert(curso);
}

set<Curso*> ControladorCursos::cursosNoAprobadosEstudiante(){
    Estudiante* e = getEstudianteSeleccionado();
    set<Curso*> cursosNA;
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

set<Curso*> ControladorCursos::listarCursosHab(){
    set<Curso*> cursosHab;
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
/*
 bool ControladorCursos::comprobarCompletarPalabra(){
    Ejercicio* ej = getEjercicioSeleccionado();
    vector<string> res = getRespuestaEjercicioCompletar();
    vector<string> sol = ej->getSolucionComp();
    return res == sol;
 }
 */

//Pre: Un curso se puede habilitar solo si tiene al menos una lección y un ejercicio, y no tiene lecciones sin ejercicios.
void ControladorCursos::habilitarCurso(Curso* c){
    c->setHabilitado(true);
}

void ControladorCursos::eliminarCurso(Curso* c){
    cursos.erase(c);
    Profesor* prof = c->getProfesor();
    Idioma* idi = c->getIdioma();
    c->eliminarContenido();
    c->eliminarInscripciones();
    c->eliminarNotificaciones();
    prof->removerCurso(c);
    idi->removerCurso(c);
    delete c;
}

void ControladorCursos::consultarCurso(){
    Curso* c = getCurso();
    cout << c << endl;
}

set<Curso*> ControladorCursos::listarCursosDisponibles(string nick){
    set<Curso*> disponibles;
    ControladorUsuarios& cu = ControladorUsuarios::getInstance();
    Estudiante* e = cu.encontrarEstudiante(nick);
    set<Inscripcion> aprobados;
    //Necesito recorrer sobre las inscripciones del estudiante
    
    return disponibles;
}