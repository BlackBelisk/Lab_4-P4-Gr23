#ifndef _CLASSLECCION_H_
#define _CLASSLECCION_H_

#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;
class Ejercicio;
class DataEjercicio;
class DataLeccion;

class Leccion{
    private:
            string tema;
            string objetivo;
            set<Ejercicio*> ejs;
            static int IDCount;
            int ID;
    public:
            Leccion(string, string);
            Leccion(DataLeccion);
            void agregarEjercicio(Ejercicio*);
            void eliminarEjercicios();
            int obtenerCantEjerciciosLeccion();
            string toString();
            string ejsToString();
            list<DataEjercicio> ejsToData();  
            DataLeccion lToData();  

            set<Ejercicio*> getEjs() const;
            Ejercicio* obtenerEj(string) ;
            string getObj() const;
            int getID() const;

            ~Leccion();
};

#include "ejercicio.h"
#include "dataEjercicio.h"
#include "dataLeccion.h"
#endif