#include <iostream>
#include <string>
#include "dataNotificacion.h"
using namespace std;

DataNotificacion::DataNotificacion(string curso, string idioma){
    this->nomCurso = curso;
    this->nomIdioma = idioma;
}

string DataNotificacion::getnomCurso(){
    return this->nomCurso;
}

string DataNotificacion::getnomIdioma(){
    return this->nomIdioma;
}