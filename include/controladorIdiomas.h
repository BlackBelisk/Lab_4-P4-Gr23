#ifndef _CLASSCONTROLADORIDIOMAS_H_
#define _CLASSCONTROLADORIDIOMAS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "IControladorIdiomas.h"

using namespace std;

class ControladorIdiomas: public IControladorIdiomas{
    public:
    static ControladorIdiomas& getInstance();
    Idioma* encontrarIdioma(string);
};

#endif