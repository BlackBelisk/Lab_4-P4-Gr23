#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>

using namespace std;

class Notificacion{
private:
    string CursoNuevo;
    string idioma;
    //no estoy muy seguro si aca deberia haber una relacion con un usuario
public:
    Notificacion(string, string);
    ~Notificacion();

    //creo que verdaderamente nunca se van a usar el set y get de esto pero lo hago igual por las dudas
    void setCursoNuevo(string);
    string getCursoNuevo() const;
    string getIdioma() const;
};

#endif