#ifndef _CLASSEJERCICIO_H_
#define _CLASSEJERCICIO_H_

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Ejercicio{
    private:
            string descripcion;
};

class TipoTrad: public Ejercicio{
    private:
            string fraseTrad;
            string solTrad;
};

class TipoComp: public Ejercicio{
    private:
            string fraseComp;
            set<string> solComp;
};

#endif