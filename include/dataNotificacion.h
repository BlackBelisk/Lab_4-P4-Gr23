#ifndef _CLASSDATANOTIFICACION_H_
#define _CLASSDATANOTIFICACION_H_

#include <string>
using namespace std;

class DataNotificacion{
    protected:
        string nomCurso;
        string nomIdioma;
    public:
        DataNotificacion() = default;
        DataNotificacion(string, string);
        string getnomCurso();
        string getnomIdioma();      
};

#endif