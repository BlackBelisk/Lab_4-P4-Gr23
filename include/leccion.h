#ifndef _CLASSEJERCICIO_H_
#define _CLASSEJERCICIO_H_

#include <iostream>
#include <set>

using namespace std;
class Ejercicio;

class Leccion{
    private:
            string tema;
            string objetivo;
            set<Ejercicio*> ejs;
    public:
            Leccion(string, string);
            void agregarEjercicio(Ejercicio*);
            void eliminarEjercicios();
            int obtenerCantEjerciciosLeccion();
            ~Leccion();
};

#include "ejercicio.h"
#endif