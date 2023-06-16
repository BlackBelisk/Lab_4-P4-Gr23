#ifndef _CLASSCONTROLADORUSUARIOS_H_
#define _CLASSCONTROLADORUSUARIOS_H_

#include <iostream>
#include <set>
#include <list>
#include <string>
#include <map>
#include "IControladorUsuarios.h"
#include "usuario.h"
#include "estudiante.h"
#include "profesor.h"
#include "dataUsuario.h"

using namespace std;

class ControladorUsuarios: public IControladorUsuarios{
    private:
        static ControladorUsuarios * instancia;
        ControladorUsuarios() = default;

        map<string, Usuario*> usuarios;
        map<string, Profesor*> profesores;
        map<string, Estudiante*> estudiantes;
        list<DataIdioma> especializacionesProfesor;

        DataUsuario usuarioIngresado;
        DataEstudiante estudianteIngresado;
        DataProfesor profesorIngresado;
        
        void setDataUsuarioIngresado(DataUsuario);
        DataUsuario getDataUsuarioIngresado();
        DataEstudiante getDataEstudianteIngresado();
        DataProfesor getDataProfesorIngresado();
    public:
        static ControladorUsuarios* getInstance();

        bool existeUsuario(string);
        bool esEstudiante(string);
        bool esProfesor(string);

        void ingresarUsuario(DataUsuario);
        
        void ingresarDatosEstudiante(string, Fecha);
        void ingresarInstituto(string);
        void agregarEspecializacion(DataIdioma);

        void confirmarAltaUsuario(int);
        void confirmarAltaEstudiante();
        void confirmarAltaProfesor();

        void nuevoEstudiante(DataEstudiante);
        void nuevoProfesor(DataProfesor);

        list<DataUsuario> obtenerUsuarios();
        list<DataEstudiante> obtenerEstudiantes();
        list<DataProfesor> obtenerProfesores();

        Usuario* encontrarUsuario(string);
        Profesor* encontrarProfesor(string);
        Estudiante* encontrarEstudiante(string);

        DataUsuario obtenerDataUsuario(string);
        DataProfesor obtenerDataProfesor(string);
        DataEstudiante obtenerDataEstudiante(string);

        list<DataNotificacion> consultarNotificaciones(DataUsuario);
        void limpiarNotificaciones(DataUsuario);
        list<DataIdioma> obtenerSuscripciones(DataUsuario);
        list<DataIdioma> suscripcionesDisponibles(DataUsuario);
        void agregarSuscripcionAusuario(DataUsuario, DataIdioma);
        void eliminarSuscripcionDeUsuario(DataUsuario, DataIdioma);
        void nuke();
};
    
#endif