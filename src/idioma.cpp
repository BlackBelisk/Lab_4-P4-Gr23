#include <string>
#include "../include/idioma.h"

Idioma::Idioma(string nom){
    nombre = nom; 
} //y se queda asi hasta que tengamos el resto de atributos

Idioma::~Idioma(){
    //por ahora no hay nada pero seguramente haga falta borrar los vectores o sets o loquesea que usemos para las relaciones
}

void Idioma::setNombre(string nom){
    nombre = nom;
}

string Idioma::getNombre(){
    return nombre;
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

