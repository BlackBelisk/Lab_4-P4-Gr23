#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataEjercicio.h"



DataEjercicio::DataEjercicio(string d): desc(d){
}

DataTraducir::DataTraducir(string d, string f, string sol): DataEjercicio(d), fraseTrad(f), solucion(sol){
}

DataCompletar::DataCompletar(string d, string f, vector<string> sol): DataEjercicio(d), fraseComp(f), solucion(sol){
}