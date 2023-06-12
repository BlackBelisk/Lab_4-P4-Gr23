#include <string>
#include "../include/notificacion.h"
using namespace std;

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

DataNotificacion Notificacion::getDataNotificacion(){
    DataNotificacion info = DataNotificacion(this->getCursoNuevo(),this->getIdioma());
    return info;
}