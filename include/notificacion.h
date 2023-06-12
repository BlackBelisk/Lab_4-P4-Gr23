#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>
#include "dataNotificacion.h"
using namespace std;

class Notificacion{
private:
    string CursoNuevo;
    string idioma;
public:
    Notificacion(string, string);
    ~Notificacion();
    string getCursoNuevo() const;
    string getIdioma() const;
    DataNotificacion getDataNotificacion();
};

#endif