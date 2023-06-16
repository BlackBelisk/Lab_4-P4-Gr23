#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/curso.h"
#include "../include/leccion.h"

using namespace std;

Curso::Curso(string nombreCurso, string desc, dif Dif){
   nomCurso = nombreCurso;
   descripcion = desc;
   dificultad = Dif;
   habilitado = false;
   profe = nullptr;
   idioma = nullptr;
   esPrevia = 0;
}

Curso::Curso(DataCurso DataC){
   nomCurso = DataC.getNomCurso();
   descripcion = DataC.getDesc();
   dificultad = DataC.getDif();
   habilitado = DataC.getHab();
   esPrevia = 0;
}

vector<DataLeccion> Curso::lecToData(){
   vector<DataLeccion> lecs;
   for(int i = 0; i < lecciones.size(); i++){
      DataLeccion l = lecciones[i]->lToData();
      lecs.push_back(l);
   }
   return lecs;
}

list<DataInscripcion> Curso::insToData(){
   list<DataInscripcion> in;
    for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
        DataInscripcion di = (*it)->insToData();
        in.insert(in.end(), di);            
    }
   return in;
}

list<DataCurso> Curso::preToData(){
   list<DataCurso> pre;
    for(auto it = previas.begin(); it != previas.end(); ++it){
        DataCurso dc = (*it)->cursoToData();
        pre.insert(pre.end(), dc);            
    }
   return pre;
}

DataCurso Curso::cursoToData(){
   DataCurso dc(nomCurso, descripcion, dificultad, habilitado, idioma->getDataIdioma(), profe->getDataProfesor(), lecToData(), insToData(), preToData(), this->obtenerCantEjerciciosCurso(), esPrevia);
   return dc;
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
    Leccion* L = new Leccion(nomTema, objLeccion);
    lecciones.push_back(L);
 }

 void Curso::nuevaLeccion(DataLeccion l){
   Leccion* L = new Leccion(l);
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

 void Curso::liberarPrevias(){
   if(previas.size() != 0){
        for(auto it = previas.begin(); it != previas.end(); ++it){
            (*it)->setEsPrevia(-1);
    }
   }
 }

 int Curso::obtenerCantEjerciciosCurso(){
    int cec = 0;
    for(int i = 0; i < lecciones.size(); i++){
        cec += lecciones[i]->obtenerCantEjerciciosLeccion(); 
    }
    return cec;
 }

 float Curso::obtenerPromedioCurso(){
    float cantIns = inscriptos.size();
    if(cantIns != 0){
      float progT = 0;
      for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
          progT += (*it)->obtenerProgreso();
      }
      return progT/cantIns;
    }
    return 0;
 }

 Leccion* Curso::siguienteLec(Leccion* l){
   int p = 0;
   for (int i = 0; i < lecciones.size(); i++) {
        if (lecciones[i] == l) {
            p = i;
            break;  
        }
    }
    if(p != lecciones.size() - 1){
      return lecciones[p+1];
    }else{
      return nullptr;
    }
 }

 void Curso::agregarInscripto(Inscripcion* i){
   inscriptos.insert(i);
 }

 void Curso::agregarPrevia(Curso* c){
   previas.insert(c);
   c->setEsPrevia(1);
 }

 Leccion* Curso::encontrarLeccion(DataLeccion l){
   Leccion* res;
   for(int i = 0; i < lecciones.size(); i++){
      if(lecciones[i]->getID() == l.getID()){
         res = lecciones[i];
         break;
      }
   }
   return res;
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

 void Curso::setEsPrevia(int i){
   esPrevia += i;
 }

 string Curso::getNombre(){
   return nomCurso;
 }
string Curso::getDesc(){
   return descripcion;
}
dif Curso::getDif(){
   return dificultad;
}

int Curso::getEsPrevia(){
   return esPrevia;
}