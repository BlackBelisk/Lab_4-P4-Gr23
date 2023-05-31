#ifndef _CLASSICONTROLADORUSUARIOS_H_
#define _CLASSICONTROLADORUSUARIOS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "fecha.h"
#include "idioma.h"
#include "usuario.h"
#include "profesor.h"
#include "estudiante.h"
#include "notificacion.h"
using namespace std;

class IControladorUsuarios{
    private:
    public:
    virtual void ingresarUsuario(string, string, string, string) = 0;
    virtual void ingresarDatosEstudiante(string, Fecha) = 0;
    virtual void ingresarInstituto(string) = 0;
    virtual void agregarEspecializacion(Idioma) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void confirmarAltaEstudiante() = 0;
    virtual void nuevoEstudiante(string, string, string, string, Fecha, string) = 0;
    virtual void confirmarAltaProfesor() = 0;
    virtual void nuevoProfesor(string, string, string, string, string, vector<Idioma>) = 0;

    virtual map<string, Profesor*> obtenerProfesores() = 0;
    virtual map<string, Estudiante*> obtenerEstudiantes() = 0;

    virtual Profesor getDataProfesor(string) = 0;
    virtual Usuario encontrarUsuario(string) = 0;
    virtual void elegirIdiomaProfesor(Idioma) = 0;

    virtual Notificacion consultarNotificaciones(string);
};

#endif