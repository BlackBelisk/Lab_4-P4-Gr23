#ifndef _CLASSCONTROLADORCURSOS_H_
#define _CLASSCONTROLADORCURSOS_H_

#include <iostream>
#include <set>

using namespace std;
class IControladorCursos;

class ControladorCursos : public IControladorCursos{
    private:
            set<Curso> cursos;
};

#include "IControladorCursos.h"
#endif