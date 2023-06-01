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

using namespace std;

class ControladorUsuarios: public IControladorUsuarios{
    private:
        map<string, Usuario*> usuarios;
        map<string, Profesor*> profesores;
        map<string, Estudiante*> estudiantes;
        set<Idioma*> especializacionesProfesor;
    public:
        static ControladorUsuarios& getInstance();

        void ingresarUsuario(string, string, string, string);
        void ingresarDatosEstudiante(string, Fecha);
        void ingresarInstituto(string);
        void agregarEspecializacion(Idioma);

        void confirmarAltaUsuario();
        void confirmarAltaEstudiante();
        void confirmarAltaProfesor();

        void nuevoEstudiante(string, string, string, string, Fecha, string);
        void nuevoProfesor(string, string, string, string, string, set<Idioma*>);

        set<Usuario*> obtenerUsuarios();
        set<Estudiante*> obtenerEstudiantes();
        set<Profesor*> obtenerProfesores();

        Usuario* encontrarUsuario(string);
        Profesor* encontrarProfesor(string);
        Estudiante* encontrarEstudiante(string);

        void elegirIdiomaProfesor(Idioma*);

        Notificacion consultarNotificaciones(string);

};
    
#endif