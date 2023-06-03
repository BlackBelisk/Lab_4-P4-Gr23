#include <iostream>
#include <string>
#include <list>
#include "../include/usuario.h"
using namespace std;

Usuario::Usuario(string nick, string contra, string descripcion, string nombre):nick(nick), contra(contra), descripcion(descripcion), nombre(nombre){}

string Usuario::getNick(){return this->nick;}

string Usuario::getDescripcion(){return this->descripcion;}

string Usuario::getNombre(){return this->nombre;}

DataUsuario Usuario::getDataUsuario(){return DataUsuario(this->nick, this->descripcion, this->nombre);}

void Usuario::setNick(string nuevoNick){this->nick = nuevoNick;}

void Usuario::setDescripcion(string nuevaDesc){this->descripcion = nuevaDesc;}

void Usuario::setNombre(string nuevoNombre){this->nombre = nuevoNombre;}

void Usuario::agregarSuscripcion(Idioma* idi){
    this->suscripciones.insert(make_pair(idi->getNombre(),idi));
}

list<DataIdioma> Usuario::obtenerSuscripciones(){
    list<DataIdioma> sus;
    for (auto it = this->suscripciones.begin(); it != this->suscripciones.end(); it++)
    {
        sus.insert(sus.end(),it->second->getDataIdioma());
    }
    return sus;
};

void Usuario::removerSuscripcionAIdioma(Idioma* idi){
    this->suscripciones.erase(idi->getNombre());
}

bool Usuario::estaSuscritoA(Idioma* idi){
    return (this->suscripciones.count(idi->getNombre()) == 1);
}
