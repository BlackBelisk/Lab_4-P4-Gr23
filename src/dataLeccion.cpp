#include <stdio.h>
#include <iostream>
#include <set>
#include <list>
#include "../include/dataLeccion.h"


DataLeccion::DataLeccion(string t, string o, list<DataEjercicio> e){
    tema = t;
    objetivo = o;
    ejs = e;
}