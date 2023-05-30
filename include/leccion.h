#ifndef _CLASSLECCION_H_
#define _CLASSLECCION_H_

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Ejercicio;

class Leccion{
    private:
            string tema;
            string objetivo;
            unordered_set<Ejercicio*> ejs;
    public:
            Leccion(string, string);
            void agregarEjercicio(Ejercicio*);
            void eliminarEjercicios();
            int obtenerCantEjerciciosLeccion();
            ~Leccion();
};

#include "ejercicio.h"
#endif