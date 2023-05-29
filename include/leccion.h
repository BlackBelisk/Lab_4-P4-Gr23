#ifndef _CLASSEJERCICIO_H_
#define _CLASSEJERCICIO_H_

#include <iostream>
#include <set>

using namespace std;
class Ejercicio;
/*
class Ejercicios{
    public:
            Ejercicio* ej;
            Ejercicios* sigEj;

};
*/
class Leccion{
    private:
            string tema;
            string objetivo;
            set<Ejercicio*> ejs;
    public:
            void agregarEjercicio(Ejercicio e);
            void eliminarEjercicios();
            int obtenerCantEjerciciosLeccion();
};

#include "ejercicio.h"
#endif