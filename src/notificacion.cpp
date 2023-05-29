#include "../include/notificacion.h"

Notificacion::Notificacion(string curso){
    CursoNuevo = curso;
}

Notificacion::~Notificacion(){
    //seguramente haya que borrar alguna visibilidad
}

void Notificacion::setCursoNuevo(string curso){
    CursoNuevo = curso;
}

string Notificacion::getCursoNuevo(){
    return CursoNuevo;
}