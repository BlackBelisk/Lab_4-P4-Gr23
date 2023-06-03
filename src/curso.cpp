#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/curso.h"

using namespace std;

Curso::Curso(string nombreCurso, string desc, dif Dif){
    nomCurso = nombreCurso;
    descripcion = desc;
    dificultad = Dif;
    habilitado = false;
    profe = nullptr;
    idioma = nullptr;
}

Inscripcion* Curso::encontrarIns(Estudiante* e){
    set<Inscripcion*>::iterator it = inscriptos.begin();
    Inscripcion* ins = nullptr;
    while(it != inscriptos.end()){
        if((*it)->getEstudiante() == e){
            ins = *it;
            break;
        }
        ++it;
    }
    return ins;
}

 bool Curso::noAprobadoCurso(Estudiante* e){
    Inscripcion* ins = encontrarIns(e);
    int p = ins->obtenerProgreso();
    return p == 100;
 }

 void Curso::nuevaLeccion(string nomTema, string objLeccion){
    Leccion* L = new Leccion(nomTema, descripcion);
    lecciones.push_back(L);
 }

 void Curso::eliminarContenido(){
    for(auto it = lecciones.begin(); it != lecciones.end(); ++it){
        (*it)->eliminarEjercicios();
        delete *it;
    }
    lecciones.clear();
 }

 void Curso::eliminarInscripciones(){
    for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
      (*it)->removerInscripcion();
      delete *it;
    }
    inscriptos.clear();
 }

 void Curso::eliminarNotificaciones(){
    idioma->eliminarNotif(nomCurso);
 }

 int Curso::obtenerCantEjerciciosCurso(){
    int cec = 0;
    for(auto it = lecciones.begin(); it != lecciones.end(); ++it){
        cec += (*it)->obtenerCantEjerciciosLeccion(); 
    }
    return cec;
 }

 int Curso::obtenerPromedioCurso(){
    int cantIns = inscriptos.size();
    int progT = 0;
    for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
        progT += (*it)->obtenerProgreso();
    }
    return progT/cantIns*100;
 }

 string Curso::leccionesToString(){
   string s = "";
   for(int i = 0; i < lecciones.size(); i++){
      s += lecciones[i]->toString() + "\n";
   }
   return s;
 }

 string Curso::inscriptosToString(){
   string s = "";
   for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
      s += (*it)->toString() + "\n";
   }
   return s;
 }
 
 string Curso::enumToString(){
   dif c = dificultad;
    switch (c)
    {
    case Principiante:
        return "Principiante";
    case Intermedio:
        return "Intermedio";
    case Avanzado:
        return "Avanzado";
    default: return "\0";
    }
 }

 std::ostream& operator<<(std::ostream& os, Curso*& c) {
   string s;
   if (c->getHab() == true){
      s = "Sí";
   }else{
      s = "No";
   }

    os << "Nombre: " << c->getNombre() << endl 
    << "Descripción: " << c->getDesc() << endl 
    << "Dificultad: " << c->enumToString() << endl
    << "Idioma: " << c->getIdioma()->getNombre() << endl
    << "Profesor: " << c->getProfesor()->getNombre() << endl
    << "Habilitado: " << s << endl
    << "Lecciones: " << c->leccionesToString() << endl //Si esto funciona me jubilo
    << "Inscriptos: " << c->inscriptosToString() << endl; //Aquí también
    return os;
  }


 bool Curso::getHab(){
    return habilitado;
 }

 set<Curso*> Curso::getPrevias(){
    return previas;
 }

 vector<Leccion*> Curso::getLecciones(){
    return lecciones;
 }

 Profesor* Curso::getProfesor(){
   return profe;
 }

 Idioma* Curso::getIdioma(){
   return idioma;
 }

 void Curso::setProfesor(Profesor* p){
    profe = p;
 }

 void Curso::setIdioma(Idioma* idi){
    idioma = idi;
 }

 void Curso::setHabilitado(bool t){
   habilitado = t;
 }