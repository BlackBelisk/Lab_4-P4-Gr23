#ifndef _CLASSCONTROLADORUSUARIOS_H_
#define _CLASSCONTROLADORUSUARIOS_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <IControladorUsuarios.h>
#include "usuario.h"
#include "estudiante.h"
#include "profesor.h"
#include "dataUsuario.h"

using namespace std;

class ControladorUsuarios: public IControladorUsuarios{
    private:
        map<string, Usuario*> usuarios;
        map<string, Profesor*> profesores;
        map<string, Estudiante*> estudiantes;
        set<Idioma*> especializacionesProfesor;

        DataUsuario usuarioIngresado;
    public:
        static ControladorUsuarios& getInstance();

        void ingresarUsuario(DataUsuario);
        void setDataUsuarioIngresado(DataUsuario);
        DataUsuario getDataUsuarioIngresado();

        void ingresarDatosEstudiante(string, Fecha);
        void ingresarInstituto(string);
        void agregarEspecializacion(Idioma);

        void confirmarAltaUsuario();
        void confirmarAltaEstudiante();
        void confirmarAltaProfesor();

        void nuevoEstudiante(DataUsuario, Fecha, string);
        void nuevoProfesor(DataUsuario, string, set<Idioma*>);

        set<DataUsuario> obtenerUsuarios();
        set<DataEstudiante> obtenerEstudiantes();
        set<DataProfesor> obtenerProfesores();

        Usuario* encontrarUsuario(string);
        Profesor* encontrarProfesor(string);
        Estudiante* encontrarEstudiante(string);

        void elegirIdiomaProfesor(Idioma*);

        Notificacion consultarNotificaciones(string);

};
    
#endif