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
#include "dataUsuario.h"
#include "profesor.h"
#include "estudiante.h"
#include "notificacion.h"
using namespace std;

class IControladorUsuarios{
    private:
    public:
    virtual void ingresarUsuario(DataUsuario) = 0;
    virtual void ingresarDatosEstudiante(string, Fecha) = 0;
    virtual void ingresarInstituto(string) = 0;
    virtual void agregarEspecializacion(Idioma) = 0;

    virtual void confirmarAltaUsuario() = 0;
    virtual void confirmarAltaEstudiante() = 0;
    virtual void confirmarAltaProfesor() = 0;

    virtual void nuevoEstudiante(DataUsuario, Fecha, string) = 0;
    virtual void nuevoProfesor(string, string, string, string, string, set<Idioma*>) = 0;

    virtual set<Usuario*> obtenerUsuarios() = 0;
    virtual set<Estudiante*> obtenerEstudiantes() = 0;
    virtual set<Profesor*> obtenerProfesores() = 0;

    virtual Usuario* encontrarUsuario(string) = 0;
    virtual Profesor* encontrarProfesor(string) = 0;
    virtual Estudiante* encontrarEstudiante(string) = 0;

    virtual void elegirIdiomaProfesor(Idioma*) = 0;

    virtual Notificacion consultarNotificaciones(string) = 0;
};

#endif