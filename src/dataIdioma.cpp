#include <iostream>
#include <string>
#include "../include/dataIdioma.h"
using namespace std;

DataIdioma::DataIdioma(string nombre){
    this->nombre = nombre;
};

string DataIdioma::getNombre() const{return this->nombre;}