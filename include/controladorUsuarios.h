#ifndef _CLASSCONTROLADORUSUARIOS_H_
#define _CLASSCONTROLADORUSUARIOS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <IControladorUsuarios.h>
using namespace std;

class ControladorUsuarios: public IControladorUsuarios{
    public:
        Estudiante* encontrarEstudiante(string) override;

        static ControladorUsuarios& getInstance();
    private:
};
    
#endif