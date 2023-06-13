#ifndef _CLASSICONTROLADORIDIOMAS_H_
#define _CLASSICONTROLADORIDIOMAS_H_

#include <iostream>
#include <set>
#include <list>
#include <string>
#include "idioma.h"
#include "dataIdioma.h"
#include "dataUsuario.h"

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
    virtual void ingresarSuscripcionDeUsuarioA(DataIdioma, DataUsuario) = 0;
    virtual void eliminarSuscriptor(DataIdioma, DataUsuario) = 0;
    virtual ~IControladorIdiomas(){};
};

#endif