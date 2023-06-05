#ifndef _CLASSICONTROLADORUSUARIOS_H_
#define _CLASSICONTROLADORUSUARIOS_H_

#include <iostream>
#include <vector>
#include <list>
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
        virtual void agregarEspecializacion(DataIdioma) = 0;

        virtual void confirmarAltaUsuario(int) = 0;
        virtual void confirmarAltaEstudiante() = 0;
        virtual void confirmarAltaProfesor() = 0;

        virtual void nuevoEstudiante(DataEstudiante) = 0;
        virtual void nuevoProfesor(DataProfesor) = 0;

        virtual list<DataUsuario> obtenerUsuarios() = 0;
        virtual list<DataEstudiante> obtenerEstudiantes() = 0;
        virtual list<DataProfesor> obtenerProfesores() = 0;

        virtual Usuario* encontrarUsuario(string) = 0;
        virtual Profesor* encontrarProfesor(string) = 0;
        virtual Estudiante* encontrarEstudiante(string) = 0;

        virtual void elegirIdiomaProfesor(Idioma*) = 0;
        //Me faltan las funciones relacionadas a la suscripciones y consulta de notificaciones
        virtual Notificacion consultarNotificaciones(string) = 0;
        virtual ~IControladorUsuarios(){};
};

#endif