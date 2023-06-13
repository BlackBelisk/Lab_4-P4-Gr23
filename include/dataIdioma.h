#ifndef _CLASSDATAIDIOMA_H_
#define _CLASSDATAIDIOMA_H_

#include <iostream>
#include <string>
using namespace std;

class DataIdioma{
    private:
        string nombre;
    public: 
        DataIdioma() = default;
        DataIdioma(string);
        string getNombre() const;
};

#endif