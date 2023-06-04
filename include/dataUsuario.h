#ifndef _CLASSDATAUSUARIO_H_
#define _CLASSDATAUSUARIO_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "Usuario.h"
#include "estudiante.h"
#include "profesor.h"
#include "fecha.h"
#include "dataIdioma.h"

using namespace std;
//Me falta implementar la sobrecarga para la impresión
class DataUsuario{
    protected:
        string nick;
        string contra;
        string descripcion;
        string nombre;
    public:
        DataUsuario() = default;
        DataUsuario(string, string, string);
        DataUsuario(string, string, string, string);
        string getNick();
        string getContra(); //:XD:
        string getDescripcion();
        string getNombre();
};

class DataEstudiante : public DataUsuario{
    protected:
        string pais;
        Fecha fecNac;
    public:
        DataEstudiante(string, string, string, string, string, Fecha);
        DataEstudiante(string, Fecha);
        string getPais();
        Fecha getFechaNac();
};

class DataProfesor : public DataUsuario{
    protected:
        string instituto;
        list<DataIdioma> idiomas;
    public:
        DataProfesor(string, string, string, string, string, list<DataIdioma>);
        DataProfesor(string);
        DataProfesor(string, list<DataIdioma>);
        string getInstituto();
        list<DataIdioma> getIdiomas();
};

#endif