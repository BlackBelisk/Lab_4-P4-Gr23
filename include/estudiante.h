#ifndef _CLASSESTUDIANTE_H_
#define _CLASSESTUDIANTE_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
#include "usuario.h"
#include "inscripcion.h"

class Estudiante : public Usuario{
    private:
    string Pais;
    int fecNac; //Acá va fecha
    vector<Inscripcion> inscripciones;
    public:
    
    void removerInscripcion(Inscripcion);
    Inscripcion encontrarInscripcion(Curso);

    vector<Curso> obtenerCursosEstudiante();
    vector<int> obtenerProgresos();
};

#endif