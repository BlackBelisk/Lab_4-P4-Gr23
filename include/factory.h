#ifndef _CLASSFACTORY_H_
#define _CLASSFACTORY_H_

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>

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
            static unique_ptr<IControladorCursos> getIControladorCursos();
            static unique_ptr<IControladorEstadisticas> getIControladorEstadisticas();
            static unique_ptr<IControladorIdiomas> getIControladorIdiomas();
            static unique_ptr<IControladorUsuarios> getIControladorUsuarios();
};

#endif