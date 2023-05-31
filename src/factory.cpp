#include <stdio.h>
#include <iostream>
#include <memory>
#include "../include/factory.h"


using namespace std;

unique_ptr<IControladorCursos> Factory::getIControladorCursos(){
    return make_unique<ControladorCursos>();
}

unique_ptr<IControladorEstadisticas> Factory::getIControladorEstadisticas(){
    return make_unique<ControladorEstadisticas>();
}

unique_ptr<IControladorIdiomas> Factory::getIControladorIdiomas(){
    return make_unique<ControladorIdiomas>();
}

unique_ptr<IControladorUsuarios> Factory::getIControladorUsuarios(){
     return make_unique<ControladorUsuarios>();
}