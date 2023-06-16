#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <list>
#include <algorithm>
#include "../include/controladorCursos.h"
#include "../include/utils.h"
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
    Curso* c = new Curso(nomCurso, descCurso, difCurso);
    cursos.insert(make_pair(nomCurso, c));
    curso = c;
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
}

//Esto en un while mientras se quiera agregar más
void ControladorCursos::agregarLeccionCN(string nomTema, string objLeccion){
    Curso* c = getCurso();
    c->nuevaLeccion(nomTema, objLeccion);
    lec = c->getLecciones().back();
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
    c->setProfesor(profe);
    c->setIdioma(idi);
    profe->agregarCursoAProfesor(c);
    curso = nullptr;
    idi = nullptr;
    profe = nullptr;
    lec = nullptr;
 }

// 
//Fin de alta de curso
//


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

bool ControladorCursos::esCursoHabilitable(string c){
    Curso* cur = cursos[c];
    bool pasa = true;
    vector<Leccion*> ls = cur->getLecciones();
    int cantLecs = ls.size();
    if(cantLecs != 0){
        for(int i = 0; i < ls.size(); i++){
            if(ls[i]->obtenerCantEjerciciosLeccion() == 0){
                pasa = false;
                break;
            }
        }
    }else{
        pasa = false;
    }
    return pasa;
}

//Pre: Un curso se puede habilitar solo si tiene al menos una lección y un ejercicio, y no tiene lecciones sin ejercicios.
//Pre: C es el nombre de un curso de los listados previamente
void ControladorCursos::habilitarCurso(string c){
    Curso* cu = encontrarCurso(c);
    cu->setHabilitado(true);
    Idioma* i = cu->getIdioma();
    i->Notificar(c);
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
    c->liberarPrevias();
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
    cursos.insert(make_pair(c->getNombre(), c));
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    profe = cu->encontrarProfesor(dataC.getProfe().getNick());
    c->setProfesor(profe);
    c->setIdioma(ci->encontrarIdioma(dataC.getIdi().getNombre()));
    if(dataC.getPrevias().size() != 0){
        list<DataCurso> pres = dataC.getPrevias();
        for(auto it = pres.begin(); it != pres.end(); ++it){
            c->agregarPrevia(encontrarCurso((*it).getNomCurso()));
        }
    }
    if(dataC.getLecciones().size() != 0){
        for(int i = 0; i < dataC.getLecciones().size(); i++){
            DataLeccion l = dataC.getLecciones()[i];
            c->nuevaLeccion(l);
        }
    }
    list<DataInscripcion> dataIns = dataC.getIns();
    if(dataIns.size() != 0){
        for(auto it = dataIns.begin(); it != dataIns.end(); ++it){
            multimap<Leccion*, Ejercicio*> ejs;
            bool fin = false;
            int largo = c->getLecciones().size();
            for(int i = 0; i < largo; i++){
                if(fin){
                    break;
                }
                set<Ejercicio*> ejsLA = c->getLecciones()[i]->getEjs();
                if(ejsLA.size() != 0){
                    for(auto itt = ejsLA.begin(); itt != ejsLA.end(); ++itt){
                        if(c->getLecciones()[i]->getID() != (*it).getLecActual().getID()){
                            ejs.insert(make_pair(c->getLecciones()[i], (*itt)));
                        }else{
                            list<DataEjercicio> complete = (*it).getEjsCompletados();
                            auto iterador = find(complete.begin(), complete.end(), (*itt)->ejToData());
                            if(iterador != complete.end()){
                                ejs.insert(make_pair(c->getLecciones()[i], (*itt)));
                            }
                            fin = true;
                        }
                    }     
                }
            }
            if(!(*it).getAprobado()){
                lec = c->encontrarLeccion((*it).getLecActual());
            }

            Inscripcion* i = new Inscripcion(cu->encontrarEstudiante((*it).getNickEstud()), c, lec, ejs, (*it).getFechaIns(), (*it).getAprobado());
            c->agregarInscripto(i);
            cu->encontrarEstudiante(i->getEstudiante()->getNick())->agregarInscripcion(i);
            lec = nullptr;
        }
    }
    profe->agregarCursoAProfesor(c);
    profe = nullptr;
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

 void ControladorCursos::seleccionarInscripcion(){
    ins = curso->encontrarIns(estud);
}

 list<DataEjercicio> ControladorCursos::listarEjerciciosNoAprobados(){
    list<DataEjercicio> le;
    Estudiante* e = getEstudianteSeleccionado();
    Curso* c = getCurso();
    Inscripcion* i = e->encontrarInscripcion(c->getNombre());
    Leccion* l = i->getLecActual();
    set<Ejercicio*> es = l->getEjs(); 
    for(auto it = es.begin(); it != es.end(); ++it){
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

 string ControladorCursos::enunciarEjercicio(){
    return ejSel->getDescripcion();
 }

 bool ControladorCursos::getTipoEjercicio(){
    bool b;
    if(CompletarPalabra* cp = dynamic_cast<CompletarPalabra*>(ejSel)){
        b = true;
    }else if (Traduccion* t = dynamic_cast<Traduccion*>(ejSel)){
        b = false;
    }
    return b;
 }

//Un getline entre funciones y una función auxiliar que lo convierta a vector en caso de tipo completar
//Estructura: crear variable string s;
//Utilizar función getline(cin, s);
//Utilizar función convertirAVector();
//En el hardcodeo solamente pasar a la función un string con la frase directamente

//cambie esto porque si no era medio dificil determinar que tipo de ejercicio es sin que reviente algo, en vez de estar separado viene todo incluido en enunciar ejercicio()

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

bool ControladorCursos::comprobarSolucionEjercicio(){
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
    return solucionado;
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
    cursos[nomCurso]->nuevaLeccion(nomTema, obj);
    lec = cursos[nomCurso]->getLecciones().back();
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
    for(int i = 0; i < curso->getLecciones().size(); i++){
        if(l.getID() == (curso->getLecciones()[i])->getID()){
            lec = curso->getLecciones()[i];
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
    if(ins.size() != 0){
        for(auto it = ins.begin(); it != ins.end(); ++it){
            inscripto.insert((*it).second->getCurso());
        }
        for(auto it = cursos.begin(); it != cursos.end(); ++it){
            bool pasa = false;
            DataCurso dc = (*it).second->cursoToData();
            if(dc.getHab() && inscripto.count((*it).second) == 0){
                pasa = true;
                set<Curso*> pres = (*it).second->getPrevias();
                if(pres.size() != 0){
                    if(aps.size() != 0){
                        for(auto itt = pres.begin(); itt != pres.end(); ++itt){
                            if(aps.count((*itt)->getNombre()) == 0){
                                pasa = false;
                                break;
                            }
                        }
                    }else{
                        pasa = false;
                    }
                    
                }
            }
            if(pasa){
                disponibles.insert(disponibles.end(), dc);
            }
        }
    }else{
        for(auto it = cursos.begin(); it != cursos.end(); ++it){
            if((*it).second->getHab() && (*it).second->getPrevias().size() == 0){
                disponibles.insert(disponibles.end(), (*it).second->cursoToData());
            }
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

//
//A mimir
//

void ControladorCursos::aMimir(){
    if(cursos.size() != 0){
        for(auto it = cursos.begin(); it != cursos.end(); ++it){
            delete it->second;
        }
        cursos.clear();
    }
}

//
//A mimir
//