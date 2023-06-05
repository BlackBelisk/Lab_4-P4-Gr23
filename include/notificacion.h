#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>

using namespace std;

class Notificacion{
private:
    string CursoNuevo;
    string idioma;
public:
    Notificacion(string, string);
    ~Notificacion();

    //creo que verdaderamente nunca se van a usar el set y get de esto pero lo hago igual por las dudas
    string getCursoNuevo() const;
    string getIdioma() const;
};

#endif