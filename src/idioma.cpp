#include <string>
#include "../include/idioma.h"

Idioma::Idioma(string nom){
    nombre = nom; 
}

Idioma::Idioma(DataIdioma dataI){
    nombre = dataI.getNombre();
}

Idioma::~Idioma(){
    //ahora no me acuerdo si siquiera hace falta que esto exista pero por las dudas lo dejamos aca
}

void Idioma::setNombre(string nom){
    nombre = nom;
}

string Idioma::getNombre(){
    return nombre;
}

DataIdioma Idioma::getDataIdioma(){
    DataIdioma self = DataIdioma(this->nombre);
    return self;
}

bool Idioma::estaSuscrito(IObserver* obs){
    return this->suscriptores.count(obs) > 0;
}

void Idioma::agregarUsuarioSuscripto(IObserver* sus){
    this->suscriptores.insert(sus);
}

void Idioma::removerObservador(IObserver* sus){
    this->suscriptores.erase(sus);
}

void Idioma::Notificar(string nomCurso){
    for(auto it = this->suscriptores.begin(); it!= this->suscriptores.end();it++){
        Notificacion* n = new Notificacion(nomCurso,this->getNombre());
        (*it)->Notificar(n);
    }
}

void Idioma::eliminarNotif(string nomCurso){
    for(auto it = this->suscriptores.begin(); it != this->suscriptores.end();it++){
        (*it)->eliminarNotificacion(nomCurso);
    }
}

