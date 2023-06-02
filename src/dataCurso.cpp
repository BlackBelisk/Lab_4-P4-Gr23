#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataCurso.h"


DataCurso::DataCurso(Curso* c){
    nomCurso = c->getNombre();
    descripcion = c->getDesc();
    

}