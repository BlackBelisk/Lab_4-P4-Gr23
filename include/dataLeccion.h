#ifndef _CLASSDATALECCION_H_
#define _CLASSDATALECCION_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "leccion.h"

using namespace std;

class DataEjercicio;
class DataLeccion{
    private:
            string tema;
            string objetivo;
            list<DataEjercicio> ejs;
            int ID;
    public:
            DataLeccion() = default;
            DataLeccion(string, string, list<DataEjercicio>, int);
            string getTema()const;
            string getObjetivo()const;
            list<DataEjercicio> getEjs()const;
            int getID()const;

            string toString();
            string ejsToString();
};

#include "dataEjercicio.h"
#endif