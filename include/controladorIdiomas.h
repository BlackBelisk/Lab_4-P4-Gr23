#ifndef _CLASSCONTROLADORIDIOMAS_H_
#define _CLASSCONTROLADORIDIOMAS_H_

#include <iostream>
#include <map>
#include <list>
#include <string>
#include "IControladorIdiomas.h"
#include <idioma.h>
#include "dataIdioma.h"

using namespace std;

class ControladorIdiomas: public IControladorIdiomas{
    private:
        static ControladorIdiomas * instancia;
        ControladorIdiomas();

        map<string, Idioma*> idiomas;
        DataIdioma idiomaIngresado;
        void setDataIdiomaIngresado(DataIdioma);
        DataIdioma getDataIdiomaIngresado();
    public:
        static ControladorIdiomas* getInstance();
        bool existeIdioma(string);
        list<DataIdioma> listarIdiomas();
        Idioma* encontrarIdioma(string);
        DataIdioma obtenerDataIdioma(string);
        void ingresarIdioma(DataIdioma);
        void confirmarAltaIdioma();
        void nuevoIdioma(DataIdioma);
        bool estaSuscritoA(IObserver*, Idioma*);
        list<DataIdioma> suscripcionesDisponiblesPara(IObserver*);
        void ingresarSuscripcionDeUsuarioA(DataIdioma, DataUsuario);
        void eliminarSuscriptor(DataIdioma, DataUsuario);
};

#endif