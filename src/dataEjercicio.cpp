#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataEjercicio.h"



DataEjercicio::DataEjercicio(string d, string f, string s): desc(d){
}

DataTraducir::DataTraducir(string d, string f, string sol): DataEjercicio(d, f, sol), fraseTrad(f), solucion(sol){
}

DataCompletar::DataCompletar(string d, string f, vector<string> sol): DataEjercicio(d, f, sol), fraseComp(f), solucion(sol){
}