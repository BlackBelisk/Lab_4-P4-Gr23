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
        //falta: relacion con profesores y con cursos
        //y no se que cosa nazi vamos a terminar haciendo con las suscripciones
        set<IObserver*> suscriptores;
    public:
        Idioma(string); //constructor, mientras no agreguemos las otras clases solo acepta 1 parametro
        Idioma(DataIdioma);
        ~Idioma(); //destructor

        void setNombre(string);//adivina que hace esto
        string getNombre();
        DataIdioma getDataIdioma();
        //faltarian los setters y getters de los pseudoatributos que no tenemos hechos

        //y estas son las funciones que estaban en el DCD
        void agregarUsuarioSuscripto(IObserver*);
        void removerObservador(IObserver*);

        //Entrada: Nombre del curso del cual se eliminara la notificación
        void eliminarNotif(string);

        void removerCurso(Curso*);

        //Entrada: Nombre del curso del que se notifica la creación
        void Notificar(string nomCurso);//Esto podría recibir directamente el string del nombre del curso
        void eliminarNotificaciones();
};

#include "curso.h"
#include "IObserver.h"
#endif