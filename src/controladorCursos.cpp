#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include "../include/controladorCursos.h"

using namespace std;

ControladorCursos* ControladorCursos::instance = nullptr;
ControladorCursos* ControladorCursos::getInstance(){
    if(instance == nullptr){
        instance = new ControladorCursos();
    }
    return instance;
}

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

Curso* ControladorCursos::encontrarCurso(string nomCurso){
    return cursos[nomCurso];
}

//
//Inicio de alta de curso
//

//Función listarProfesores() del controlador de usuarios

void ControladorCursos::elegirProfesor(string nickProfesor){
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    profe = cu->encontrarProfesor(nickProfesor);
}

list<DataIdioma> ControladorCursos::listarIdiomasProfesor(){
    return profe->obtenerIdiomas();
}

//Un cout entre una función y otra

//El DataIdioma pertenece a los idiomas listados previamente
void ControladorCursos::elegirIdiomaProfesor(DataIdioma di){
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    idi = ci->encontrarIdioma(di.getNombre());
}

void ControladorCursos::crearCurso(string nomCurso, string descCurso, dif difCurso){
    Curso* curso = new Curso(nomCurso, descCurso, difCurso);
    cursos.insert(make_pair(nomCurso, curso));
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

//Un cout entre una función y otra

//Esto en un while mientras se quiera agregar más
//nPrevia es el nombre de un curso de los listados previamente
void ControladorCursos::agregarPrevia(string nPrevia){
    Curso* c = getCurso();
    c->getPrevias().insert(cursos[nPrevia]);
    lec = c->getLecciones().back();
}

//Esto en un while mientras se quiera agregar más
void ControladorCursos::agregarLeccionCN(string nomTema, string objLeccion){
    Curso* c = getCurso();
    c->nuevaLeccion(nomTema, objLeccion);

}

//Estos en un while mientras se quiera agregar más
//En caso de traducir
 void ControladorCursos::agregarEjercicio(string desc, string fraseT, string solT){
    Traduccion* t = new Traduccion(desc, fraseT, solT);
    lec->agregarEjercicio(t);
 }
 //En caso de completar
 void ControladorCursos::agregarEjercicio(string desc, string fraseC, vector<string> solC){
    CompletarPalabra* c = new CompletarPalabra(desc, fraseC, solC);
    lec->agregarEjercicio(c);
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
    lec = nullptr;
 }

// 
//Fin de alta de curso
//


/*
 bool ControladorCursos::comprobarCompletarPalabra(){
    Ejercicio* ej = getEjercicioSeleccionado();
    vector<string> res = getRespuestaEjercicioCompletar();
    vector<string> sol = ej->getSolucionComp();
    return res == sol;
 }
 */


//
//Inicio de habilitar curso
//

list<DataCurso> ControladorCursos::listarCursosNA(){
    list<DataCurso> dc;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        if(!(*it).second->getHab()){
            dc.insert(dc.begin(), (*it).second->cursoToData());
        }
    }
    return dc;
}

//Un cout entre una función y otra

//Pre: Un curso se puede habilitar solo si tiene al menos una lección y un ejercicio, y no tiene lecciones sin ejercicios.
//Pre: C es el nombre de un curso de los listados previamente
void ControladorCursos::habilitarCurso(string c){
    cursos[c]->setHabilitado(true);
}

//
//Fin de habilitar curso
//


//
//Inicio de eliminar curso
//

list<DataCurso> ControladorCursos::listarCursos(){
    list<DataCurso> dc;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        dc.insert(dc.begin(), (*it).second->cursoToData());
    }
    return dc;
}

//Un cout entre una función y otra

void ControladorCursos::eliminarCurso(string nc){
    Curso* c = cursos[nc];
    cursos.erase(nc);
    Profesor* prof = c->getProfesor();
    c->eliminarContenido();
    c->eliminarInscripciones();
    c->eliminarNotificaciones();
    prof->removerCurso(c);
    delete c;
}

//
//Fin de eliminar curso
//


//
//Inicio de consultar curso
//

//Función listarCursos() ya definida

//Un cout de la lista obtenida entre una función y otra

//Un cout del dataCurso que se haya elegido el cual tiene sobrecarga del operador <<

//
//Fin de consultar curso
//

void ControladorCursos::nuevoCurso(DataCurso dataC){
    Curso *c = new Curso(dataC);
    cursos.insert(make_pair(c->getNombre(), curso));
}

//
//Inicio de realizar ejercicio
//

void ControladorCursos::seleccionarEstudiante(string nickE){
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    estud = cu->encontrarEstudiante(nickE);
}

list<DataCurso> ControladorCursos::obtenerCursosNoAprobadosEstudiante(){
    Estudiante* e = getEstudianteSeleccionado();
    return e->obtenerDataCursosEnCurso();
}

//Un cout entre una función y otra

//El nombre del curso pertenece a los cursos previamente listados
 void ControladorCursos::seleccionarCurso(string nombre){
    curso = cursos[nombre];
 }

 list<DataEjercicio> ControladorCursos::listarEjerciciosNoAprobados(){
    list<DataEjercicio> le;
    Estudiante* e = getEstudianteSeleccionado();
    Curso* c = getCurso();
    Inscripcion* i = e->encontrarInscripcion(c->getNombre());
    Leccion* l = i->getLecActual();
    for(auto it = l->getEjs().begin(); it != l->getEjs().end(); ++it){
        bool encontrado = false;
        for (const auto& pair : i->getEjsCompletados()) {
            if (pair.second == (*it)) {
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            le.insert(le.begin(), (*it)->ejToData());
        }
    }
    return le;
 }

//Un cout entre una función y otra

 //El DataEjercicio pertenece a los listados previamente
 void ControladorCursos::seleccionarEjercicio(DataEjercicio e){
    ejSel = ins->getLecActual()->obtenerEj(e.getDesc());
 }

 void ControladorCursos::enunciarEjercicio(){
    cout << ejSel->getDescripcion() << endl;
    if(CompletarPalabra* cp = dynamic_cast<CompletarPalabra*>(ejSel)){
        cout << cp->getFraseAComp() << endl;
        cout << "Ingrese las palabras faltantes separadas por un espacio: " << endl;
    }else if (Traduccion* t = dynamic_cast<Traduccion*>(ejSel)){
        cout << t->getFraseTrad() << endl;
        cout << "Ingrese la frase traducida: " << endl;
    }
 }

//Un getline entre funciones y una función auxiliar que lo convierta a vector en caso de tipo completar
//Estructura: crear variable string s;
//Utilizar función getline(cin, s);
//Utilizar función convertirAVector();
//En el hardcodeo solamente pasar a la función un string con la frase directamente

//En caso de traducir
void ControladorCursos::ingresarSolEjercicio(string s){
    resTrad = s;
    tipo = 0;
}
//En caso de completar
void ControladorCursos::ingresarSolEjercicio(vector<string> s){
    resComp = s;
    tipo = 1;
}

void ControladorCursos::comprobarSolucionEjercicio(){
    bool solucionado;
    if(tipo == 0){
        solucionado = comprobarTraducir();
    }else if(tipo == 1){
        solucionado = comprobarCompletarPalabra();
    }
    if(solucionado){
        ins->agregarCompletado(ins->getLecActual(), ejSel);
        if(ins->getEjsCompletadosLecActual().size() == ins->getLecActual()->getEjs().size()){
            ins->setLecActual(ins->getCurso()->siguienteLec(ins->getLecActual()));
            if(ins->getLecActual() == nullptr){
                ins->setAprobado();
                ins->getEstudiante()->marcarAprobado(ins);
            }
        }
    }
    ins = nullptr;
    curso = nullptr;
    ejSel = nullptr;
    estud = nullptr;
}

//En caso traducir
bool ControladorCursos::comprobarTraducir(){
    Traduccion* ej = dynamic_cast<Traduccion*>(getEjercicioSeleccionado());
    return ej->getSolucion() == resTrad;
}
//En caso completar
bool ControladorCursos::comprobarCompletarPalabra(){
    CompletarPalabra* ej = dynamic_cast<CompletarPalabra*>(getEjercicioSeleccionado());
    return ej->getSolucionComp() == resComp;
}

//
//Fin de realizar ejercicio
//



//
//Inicio de agregar lección
//

//Función listarCursosNA()

void ControladorCursos::insLeccion(string nomCurso, string nomTema, string obj){
    Leccion* l = new Leccion(nomTema, obj);
    cursos[nomCurso]->getLecciones().push_back(l);
    lec = l;
}

//Función agregarEjercicio() y un loop mientras se quiera seguir agregando

void ControladorCursos::finalizarAgLec(){
    lec = nullptr;
}

//
//Fin de agregar lección
//



//
//Inicio de agregar ejercicio
//

//Función listarCursosNA()

//Función seleccionarCurso()

vector<DataLeccion> ControladorCursos::listarLecciones(){
    DataCurso c = curso->cursoToData();
    return c.getLecciones();
}

//Un cout entre una función y otra

void ControladorCursos::seleccionarLeccion(DataLeccion l){
    for(auto it = curso->getLecciones().begin(); it != curso->getLecciones().end(); ++it){
        if(l.getObjetivo() == (*it)->getObj()){
            lec = (*it);
            break;
        }
    }
}

//Función agregarEjercicio()

void ControladorCursos::darAltaEjercicio(){
    curso = nullptr;
    lec = nullptr;
}

//
//Fin de agregar ejercicio
//

//
//Inicio de inscribirse a curso
//

//Función listarEstudiantes() de controlador de usuarios

//Función seleccionarEstudiante()

list<DataCurso> ControladorCursos::listarCursosDisponibles(){
    list<DataCurso> disponibles;
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    set<Curso*> inscripto;
    map<string, Inscripcion*> aps = estud->getAprobados();
    map<string, Inscripcion*> ins = estud->getInscripciones();
    for(auto it = ins.begin(); it != ins.end(); ++it){
        inscripto.insert((*it).second->getCurso());
    }
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        bool pasa = false;
        if((*it).second->cursoToData().getHab() && inscripto.count((*it).second) == 0){
            pasa = true;
            for(auto itt = (*it).second->getPrevias().begin(); itt != (*it).second->getPrevias().end(); ++itt){
                if(aps.count((*itt)->getNombre()) == 0){
                    pasa = false;
                    break;
                }
            }
        }
        if(pasa){
            disponibles.insert(disponibles.end(), (*it).second->cursoToData());
        }
    }
    return disponibles;
}

//Un cout que muestre los datos básicos de cada curso, cantidad total de lecciones y de ejercicios

//Función seleccionarCurso()

void ControladorCursos::finalizarInscripcion(){
    Fecha f;
    Inscripcion* i = new Inscripcion(estud, curso, f);
    estud->agregarInscripcion(i);
    curso->agregarInscripto(i);
    curso = nullptr;
    estud = nullptr;
}

//
//Fin de inscribirse a curso
//