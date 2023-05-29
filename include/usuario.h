#ifndef _CLASSUSUARIO_H_
#define _CLASSUSUARIO_H_

#include <iostream>
#include <string>
#include <set>
#include "IObserver.h"
using namespace std;
class Idioma;

class Usuario: IObserver{
    protected:
    //Atributos basicos de la clase Usuario

    string nick;
    string contra;
    string descripcion;
    string nombre;

    //Creador abstracto, unicamente para simplificar la creación de un Estudiante y Profesor
    Usuario(string, string, string, string);
    public:
    virtual ~Usuario();

    //Gets
    virtual string getNick();
    virtual string getDescripcion();
    virtual string getNombre();

    //Sets
    virtual void setNick(string);
    virtual void setContra(string);
    virtual void setDescripcion(string);
    virtual void setNombre(string);

    virtual set<Idioma> obtenerSuscripciones();
    
    bool operator==(const Usuario &user);
};

#include "idioma.h"
#endif