#ifndef _CLASSUSUARIO_H_
#define _CLASSUSUARIO_H_

#include <iostream>
#include <string>
#include <map>
#include <list>
#include "IObserver.h"
#include "idioma.h"
#include "notificacion.h"
#include "dataUsuario.h"
using namespace std;

class Usuario: public IObserver{
    private:
    //Atributos basicos de la clase Usuario
    string nick;
    string contra;
    string descripcion;
    string nombre;
    //Links

    //La key es el nombre del idioma
    map<string ,Idioma*> suscripciones;

    //La key es el nombre del curso
    map<string,Notificacion*> notificaciones;

    public:
    //Creador abstracto, unicamente para simplificar la creación de un Estudiante y Profesor
    Usuario() = default;
    Usuario(string, string, string, string);
    virtual ~Usuario(){};

    //Gets
    string getNick() const;
    string getDescripcion() const;
    string getNombre() const;
    DataUsuario getDataUsuario();
    //Sets
    void setNick(string);
    void setContra(string);
    void setDescripcion(string);
    void setNombre(string);

    //Suscripciones
    void agregarSuscripcion(Idioma*);
    list<DataIdioma> obtenerSuscripciones(); 
    void removerSuscripcionAIdioma(Idioma*);
    bool estaSuscritoA(Idioma*);

    void Notificar(Notificacion*);
    list<DataNotificacion> obtenerNotificaciones();
    void eliminarNotificacion(string);
    void eliminarNotificaciones();
    
    bool operator==(const Usuario &user);
};

#endif