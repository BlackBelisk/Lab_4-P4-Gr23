#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataEjercicio.h"



DataTraducir::DataTraducir(string d, string f, string sol){
    desc = d;
    fraseTrad = f;
    solucion = sol;
}

DataCompletar::DataCompletar(string d, string f, vector<string> sol){
    desc = d;
    fraseComp = f;
    solucion = sol;
}