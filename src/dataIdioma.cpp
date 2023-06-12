#include <iostream>
#include <string>
#include "../include/dataIdioma.h"
using namespace std;

DataIdioma::DataIdioma(string nombre):nombre(nombre){};

string DataIdioma::getNombre(){return this->nombre;}