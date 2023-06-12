#ifndef _CLASSDATALECCION_H_
#define _CLASSDATALECCION_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "leccion.h"

using namespace std;

class DataEjercicio;
class DataLeccion{
    private:
            string tema;
            string objetivo;
            list<DataEjercicio> ejs;
    public:
            DataLeccion() = default;
            DataLeccion(string, string, list<DataEjercicio>);
            string getTema()const;
            string getObjetivo()const;
            list<DataEjercicio> getEjs()const;
};

#include "dataEjercicio.h"
#endif