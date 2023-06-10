#ifndef _CLASSFACTORY_H_
#define _CLASSFACTORY_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "IControladorCursos.h"
#include "controladorCursos.h"
#include "IControladorUsuarios.h"
#include "controladorUsuarios.h"
#include "IControladorEstadisticas.h"
#include "controladorEstadisticas.h"
#include "IControladorIdiomas.h"
#include "controladorIdiomas.h"
using namespace std;

class Factory{
    private:
        static Factory * instancia;
        Factory();
    public:
        static Factory* getInstance();
        IControladorCursos* getIControladorCursos();
        IControladorEstadisticas* getIControladorEstadisticas();
        IControladorIdiomas* getIControladorIdiomas();
        IControladorUsuarios* getIControladorUsuarios();
};

#endif