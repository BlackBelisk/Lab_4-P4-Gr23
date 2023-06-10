#include <stdio.h>
#include <iostream>
#include "../include/factory.h"

using namespace std;
Factory * Factory::instancia = nullptr;

Factory::Factory(){}

Factory* Factory::getInstance(){
    if(instancia == nullptr){instancia = new Factory();}
    return instancia;
}

IControladorCursos* Factory::getIControladorCursos(){
    return ControladorCursos::getInstance();
}

IControladorEstadisticas* Factory::getIControladorEstadisticas(){
    return ControladorEstadisticas::getInstance();
}

IControladorIdiomas* Factory::getIControladorIdiomas(){
    return ControladorIdiomas::getInstance();
}

IControladorUsuarios* Factory::getIControladorUsuarios(){
    return ControladorUsuarios::getInstance();
}