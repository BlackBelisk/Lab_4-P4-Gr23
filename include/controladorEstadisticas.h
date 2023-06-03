#ifndef _CLASSCONTROLADORESTADISTICAS_H_
#define _CLASSCONTROLADORESTADISTICAS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "IControladorEstadisticas.h"
using namespace std;

class ControladorEstadisticas: public IControladorEstadisticas{
    private:
        ControladorEstadisticas();
    public:
        static ControladorEstadisticas& getInstance();
        void seleccionarEstadisticaDeseada(eleccion estad);
        
};

#endif