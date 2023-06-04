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
