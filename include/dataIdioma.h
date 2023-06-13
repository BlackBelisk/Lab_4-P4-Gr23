#ifndef _CLASSDATAIDIOMA_H_
#define _CLASSDATAIDIOMA_H_

#include <iostream>
#include <string>
#include "idioma.h"
using namespace std;

class DataIdioma{
    private:
        string nombre;
    public: 
        DataIdioma() = default;
        DataIdioma(string);
        string getNombre() const;
        bool operator==(const DataIdioma&);
        bool operator!=(const DataIdioma&);
};

#endif