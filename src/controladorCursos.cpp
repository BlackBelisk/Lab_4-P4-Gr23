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
    Curso* curso = new Curso(nomCurso, descCurso, difCurso);
    cursos.insert(make_pair(nomCurso, curso));
}

list<DataCurso> ControladorCursos::cursosNoAprobadosEstudiante(){
    Estudiante* e = getEstudianteSeleccionado();
    list<DataCurso> cursosNA;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if((*it).second->noAprobadoCurso(e)){
            cursosNA.insert(cursosNA.end(), (*it).second->cursoToData());
        }
    }
    return cursosNA;
}

//Falta
void ControladorCursos::elegirProfesor(string nickProfesor){
    
}

list<DataCurso> ControladorCursos::listarCursosHab(){
    list<DataCurso> cursosHab;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if((*it).second->getHab()){
            DataCurso dc = (*it).second->cursoToData();
            cursosHab.insert(cursosHab.end(), dc);
        }
    }
    return cursosHab;
}

void ControladorCursos::agregarPrevia(string nPrevia){
    Curso* c = getCurso();
    c->getPrevias().insert(cursos[nPrevia]);
}

void ControladorCursos::agregarLeccionCN(string nomTema, string objLeccion){
    Curso* c = getCurso();
    c->nuevaLeccion(nomTema, objLeccion);
}

//Falta
 void ControladorCursos::agregarEjercicio(string desc, DataLeccion lec){

 }

 void ControladorCursos::finalizarAltaCurso(){
    Curso* c = getCurso();
    Profesor* p = getProfesorElegido();
    Idioma* i = getIdiomaElegido();
    c->setProfesor(p);
    c->setIdioma(i);
    p->agregarCursoAProfesor(c);
    i->Notificar(c->getNombre());
    curso = nullptr;
    idi = nullptr;
    profe = nullptr;
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
void ControladorCursos::habilitarCurso(string c){
    cursos[c]->setHabilitado(true);
}

void ControladorCursos::eliminarCurso(string nc){
    Curso* c = cursos[nc];
    cursos.erase(nc);
    Profesor* prof = c->getProfesor();
    Idioma* id = c->getIdioma();
    c->eliminarContenido();
    c->eliminarInscripciones();
    c->eliminarNotificaciones();
    prof->removerCurso(c);
    id->removerCurso(c);
    delete c;
}

void ControladorCursos::consultarCurso(){
    Curso* c = getCurso();
    cout << c << endl;
    delete c;
}

list<DataCurso> ControladorCursos::listarCursosDisponibles(string nick){
    list<DataCurso> disponibles;
    ControladorUsuarios& cu = ControladorUsuarios::getInstance();
    Estudiante* e = cu.encontrarEstudiante(nick);
    set<Inscripcion> aprobados;
    //Necesito recorrer sobre las inscripciones del estudiante

    return disponibles;
}