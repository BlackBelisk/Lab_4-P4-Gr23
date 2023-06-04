#ifndef _CLASSDATAIDIOMA_H_
#define _CLASSDATAIDIOMA_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "idioma.h"
using namespace std;

class DataIdioma{
    private:
        string nombre;
    public: 
        DataIdioma(string);
        string getNombre();
};

#endif