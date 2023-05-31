#ifndef _CLASSESTUDIANTE_H_
#define _CLASSESTUDIANTE_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

#include "usuario.h"
#include "inscripcion.h"
#include "fecha.h"
using namespace std;

class Estudiante : public Usuario{
    private:
    string Pais;
    Fecha fecNac; //Acá va fecha
    map<string, Inscripcion> inscripciones;
    public:
    
    void removerInscripcion(Inscripcion);
    Inscripcion encontrarInscripcion(Curso);

    vector<Curso> obtenerCursosEstudiante();
    vector<int> obtenerProgresos();
};

#endif