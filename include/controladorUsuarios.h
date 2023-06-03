#ifndef _CLASSCONTROLADORUSUARIOS_H_
#define _CLASSCONTROLADORUSUARIOS_H_

#include <iostream>
#include <set>
#include <vector>
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
        static ControladorUsuarios& getInstance();

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

        void elegirIdiomaProfesor(Idioma*);

        Notificacion consultarNotificaciones(string);

};
    
#endif