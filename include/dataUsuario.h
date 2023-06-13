#ifndef _CLASSDATAUSUARIO_H_
#define _CLASSDATAUSUARIO_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "usuario.h"
#include "estudiante.h"
#include "profesor.h"
#include "fecha.h"
#include "dataIdioma.h"

using namespace std;
class DataUsuario{
    private:
        string nick;
        string contra;
        string descripcion;
        string nombre;
    public:
        DataUsuario() = default;
        DataUsuario(string, string, string);
        DataUsuario(string, string, string, string);
        string getNick() const;
        void setNick(string);
        string getContra() const;
        void setContra(string);
        string getDescripcion() const;
        void setDescripcion(string);
        string getNombre() const;
        void setNombre(string);
};

class DataEstudiante : public DataUsuario{
    private:
        string pais;
        Fecha fecNac;
    public:
        DataEstudiante() = default;
        DataEstudiante(string, string, string, string, string, Fecha);
        DataEstudiante(string, Fecha);
        string getPais() const;
        Fecha getFechaNac() const;
};

class DataProfesor : public DataUsuario{
    private:
        string instituto;
        list<DataIdioma> idiomas;
    public:
        DataProfesor() = default;
        DataProfesor(string, string, string, string, string, list<DataIdioma>);
        DataProfesor(string);
        DataProfesor(string, list<DataIdioma>);
        string getInstituto() const;
        list<DataIdioma> getIdiomas() const;
};

std::ostream& operator<<(std::ostream& os, const DataUsuario& du);
std::ostream& operator<<(std::ostream& os, const DataEstudiante& de);
std::ostream& operator<<(std::ostream& os, const DataProfesor& dp);


#endif