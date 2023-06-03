#ifndef _CLASSLECCION_H_
#define _CLASSLECCION_H_

#include <iostream>
#include <string>
#include <set>

using namespace std;
class Ejercicio;
class DataEjercicio;

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
            string toString();
            string ejsToString();
            list<DataEjercicio> ejsToData();    

            ~Leccion();
};

#include "ejercicio.h"
#include "dataEjercicio.h"
#endif