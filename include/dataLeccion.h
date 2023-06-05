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
    public:
            string tema;
            string objetivo;
            list<DataEjercicio> ejs;
    DataLeccion();
    DataLeccion(string, string, list<DataEjercicio>);
};

#include "dataEjercicio.h"
#endif