#include "../include/notificacion.h"

Notificacion::Notificacion(string curso, string idioma){
    this->CursoNuevo = curso;
    this->idioma = idioma;
}

Notificacion::~Notificacion(){
    //seguramente haya que borrar alguna visibilidad
}

string Notificacion::getCursoNuevo() const{
    return CursoNuevo;
}

string Notificacion::getIdioma() const{
    return idioma;
}