#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>
#include "dataIdioma.h"
using namespace std;

class Curso;
class IObserver;

class Idioma{
    private:
        string nombre; //resulta que ademas de las relaciones con otras clases solo tiene ese atributo

        set<IObserver*> suscriptores;
    public:
        Idioma(string); //constructor
        Idioma(DataIdioma);
        ~Idioma(); //destructor

        void setNombre(string);//adivina que hace esto
        string getNombre();
        DataIdioma getDataIdioma();

        //y estas son las funciones que estaban en el DCD
        void agregarUsuarioSuscripto(IObserver*);
        void removerObservador(IObserver*);

        //Entrada: Nombre del curso del cual se eliminara la notificación
        void eliminarNotif(string);

        //Entrada: Nombre del curso del que se notifica la creación
        void Notificar(string nomCurso);
};

#include "curso.h"
#include "IObserver.h"
#endif