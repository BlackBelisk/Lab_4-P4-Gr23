#ifndef _CLASSICONTROLADORIDIOMAS_H_
#define _CLASSICONTROLADORIDIOMAS_H_

#include <iostream>
#include <set>
#include <list>
#include <string>
#include <dataIdioma.h>

using namespace std;

class IControladorIdiomas{
    public:
    virtual bool existeIdioma(string) = 0;
    virtual list<DataIdioma> listarIdiomas() = 0;
    virtual Idioma* encontrarIdioma(string) = 0;
    virtual DataIdioma obtenerDataIdioma(string) = 0;
    virtual void ingresarIdioma(DataIdioma) = 0;
    virtual void confirmarAltaIdioma() = 0;
    virtual void nuevoIdioma(DataIdioma) = 0;

    virtual ~IControladorIdiomas(){};
};

#endif