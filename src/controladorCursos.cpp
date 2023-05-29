#include <stdio.h>
#include <iostream>
#include <set>
#include "../include/controladorCursos.h"
#include "../include/curso.h"
#include "curso.cpp"
using namespace std;

void ControladorCursos::crearCurso(string nomCurso, string descCurso, dif difCurso){
    Curso* curso = new Curso(nomCurso, descCurso, difCurso);
}