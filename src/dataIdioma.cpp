#include <iostream>
#include <string>
#include "../include/dataIdioma.h"
using namespace std;

DataIdioma::DataIdioma(string nombre):nombre(nombre){};

string DataIdioma::getNombre() const{return this->nombre;}

bool DataIdioma::operator==(const DataIdioma& idi){
    return this->getNombre() == idi.getNombre();
}

bool DataIdioma::operator!=(const DataIdioma& idi){
    return this->getNombre() != idi.getNombre();
}