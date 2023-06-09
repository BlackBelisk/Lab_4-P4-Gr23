#include <iostream>
#include <string>
#include <list>
#include "../include/IControladorEstadisticas.h"
#include "../include/controladorEstadisticas.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorCursos.h"
using namespace std;

ControladorEstadisticas* ControladorEstadisticas::instancia = nullptr;

ControladorEstadisticas* ControladorEstadisticas::getInstance(){
    if(instancia == nullptr){instancia = new ControladorEstadisticas();}
    return instancia;
}

void ControladorEstadisticas::seleccionarEstadisticaDeseada(eleccion estad){
    if (estad == EstadEstudiante)
    {
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        list<DataEstudiante> estudiantes = cu->obtenerEstudiantes();
        cout << "Estudiantes: " << endl;
        int p = 1;
        for (auto  it = estudiantes.begin(); it != estudiantes.end(); it++)
        {
            cout << p << ". " << it->getNick() << endl;
        }
        // int estud;
        // do
        // {
        //    cout << "Seleccione el estudiante ingresando el número ";
        //     cin >> estud;
        //     if (estud < 1 || estud > estudiantes.size())
        //     {
        //         cout << "Número de estudiante invalido. Intente nuevamente." <<endl;
        //     }
            
        // } while (estud < 1 || estud > estudiantes.size());
        // auto iter = estudiantes.begin();
        // advance(iter,estud-1);

    }
    else if (estad == EstadProfesor)
    {
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        list<DataProfesor> profesores = cu->obtenerProfesores();
        cout << "Profesores: " << endl;
        int p = 1;
        for (auto  it = profesores.begin(); it != profesores.end(); it++)
        {
            cout << p << ". " << it->getNick() << endl;
        }
    }
    else if (estad == EstadCurso)
    {
        ControladorCursos* cu = ControladorCursos::getInstance();
    }
    
}
