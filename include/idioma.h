#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>

using namespace std;

class Curso;

class Idioma{
    private:
        string nombre; //resulta que ademas de las relaciones con otras clases solo tiene ese atributo
        //falta: relacion con profesores y con cursos
        //y no se que cosa nazi vamos a terminar haciendo con las suscripciones
    public:
        Idioma(string); //constructor, mientras no agreguemos las otras clases solo acepta 1 parametro

        ~Idioma(); //destructor

        void setNombre(string);//adivina que hace esto
        string getNombre();

        //faltarian los setters y getters de los pseudoatributos que no tenemos hechos

        //y estas son las funciones que estaban en el DCD
        void agregarUsuarioSuscripto(); //este y el de abajo aceptan un parametro de tipo IObserver, todavia no lo tenemos
        void removerObservador();
        void eliminarNotif(string);
        void removerCurso(Curso);
        void notificarCursoNuevo(Curso);
        void eliminarNotificaciones();
};

#endif