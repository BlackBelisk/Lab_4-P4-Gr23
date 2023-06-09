#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataCurso.h"


DataCurso::DataCurso(string n, string d, dif Dif, bool b, DataIdioma i, DataProfesor p, vector<DataLeccion> ls, list<DataInscripcion> is, list<DataCurso> ps){
    nomCurso = n;
    descripcion = d;
    dificultad = Dif;
    habilitado = b;
    idioma = i;
    profe = p;
    lecciones = ls;
    inscriptos = is;
    previas = ps;
}


//Luego lo termino, me duele la cabeza
std::ostream& operator<<(std::ostream& os, DataCurso& c) {
   string s;
   if (c.habilitado == true){
      s = "Sí";
   }else{
      s = "No";
   }

    os << "Nombre: " << c.nomCurso << endl 
    << "Descripción: " << c.descripcion << endl 
    << "Dificultad: " << c->enumToString() << endl
    << "Idioma: " << c->getIdioma()->getNombre() << endl
    << "Profesor: " << c->getProfesor()->getNombre() << endl
    << "Habilitado: " << s << endl
    << "Lecciones: " << c->leccionesToString() << endl //Si esto funciona me jubilo
    << "Inscriptos: " << c->inscriptosToString() << endl; //Aquí también
    return os;
  }