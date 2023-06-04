#ifndef _CLASSUSUARIO_H_
#define _CLASSUSUARIO_H_

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "IObserver.h"
#include "idioma.h"
#include "inscripcion.h"
#include "notificacion.h"
using namespace std;
class Idioma;

class Usuario: public IObserver{
    protected:
    //Atributos basicos de la clase Usuario
    string nick;
    string contra;
    string descripcion;
    string nombre;
    //Links
    
    //La key es el nombre del curso
    map<string, Inscripcion*> inscripciones; 

    //La key es el nombre del idioma
    map<string ,Idioma*> suscripciones;

    //La key es el nombre del curso
    map<string,Notificacion*> notificaciones;

    //Creador abstracto, unicamente para simplificar la creación de un Estudiante y Profesor
    Usuario() = default;
    Usuario(string, string, string, string);
    public:
    virtual ~Usuario();

    //Gets
    virtual string getNick() const;
    virtual string getDescripcion() const;
    virtual string getNombre() const;
    virtual DataUsuario getDataUsuario();
    //Sets
    virtual void setNick(string);
    virtual void setDescripcion(string);
    virtual void setNombre(string);

    //Suscripciones
    virtual void agregarSuscripcion(Idioma*);
    virtual list<DataIdioma> obtenerSuscripciones(); 
    virtual void removerSuscripcionAIdioma(Idioma*);
    virtual bool estaSuscritoA(Idioma*);
    void eliminarNotificacion(string);

    void Notificar(Notificacion*, Idioma*);
    bool operator==(const Usuario &user);
};

#include "idioma.h"
#endif