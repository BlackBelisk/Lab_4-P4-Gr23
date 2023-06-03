#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include "../include/IControladorUsuarios.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorIdiomas.h"
#include "../include/usuario.h"
#include "../include/estudiante.h"
#include "../include/profesor.h"
#include "../include/dataUsuario.h"

using namespace std;

void ControladorUsuarios::ingresarUsuario(DataUsuario dataU){
    this->setDataUsuarioIngresado(dataU);
};

void ControladorUsuarios::setDataUsuarioIngresado(DataUsuario dataU){
    this->usuarioIngresado = dataU;
};

DataUsuario ControladorUsuarios::getDataUsuarioIngresado(){
    return this->usuarioIngresado;
}

DataEstudiante ControladorUsuarios::getDataEstudianteIngresado(){
    return this->estudianteIngresado;
}

DataProfesor ControladorUsuarios::getDataProfesorIngresado(){
    return this->profesorIngresado;
}

void ControladorUsuarios::ingresarDatosEstudiante(string pais, Fecha fecN){
    this->estudianteIngresado = DataEstudiante(pais, fecN);
}

void ControladorUsuarios::ingresarInstituto(string insti){
    this->profesorIngresado = DataProfesor(insti);
}

void ControladorUsuarios::agregarEspecializacion(DataIdioma idi){
    this->especializacionesProfesor.insert(especializacionesProfesor.end(),idi);
}

void ControladorUsuarios::confirmarAltaUsuario(int opcion){
    if(opcion == 1){
        this->confirmarAltaEstudiante();
    }
    else if (opcion == 2)
    {
        this->confirmarAltaProfesor();
    }
};

void ControladorUsuarios::confirmarAltaEstudiante(){
    DataUsuario data = this->getDataUsuarioIngresado();
    DataEstudiante dataE = this->getDataEstudianteIngresado();
    Estudiante * e = new Estudiante(data, dataE);
    this->usuarios.insert(make_pair(data.getNick(),e));
    this->estudiantes.insert(make_pair(data.getNick(),e));
}

void ControladorUsuarios::confirmarAltaProfesor(){
    DataUsuario data = this->getDataUsuarioIngresado();
    DataProfesor dataP = this->getDataProfesorIngresado();

    Profesor * p = new Profesor(data, dataP);
    
    ControladorIdiomas& ci = ControladorIdiomas::getInstance();
    
    for(auto it = this->especializacionesProfesor.begin(); it != this->especializacionesProfesor.end(); ++it){
        p->agregarIdioma(ci.encontrarIdioma(it->getNombre()));
    }

    this->usuarios.insert(make_pair(data.getNick(),p));
    this->profesores.insert(make_pair(data.getNick(),p));
    this->especializacionesProfesor.clear();
};

void ControladorUsuarios::nuevoEstudiante(DataEstudiante dataE){
    Estudiante * e = new Estudiante(dataE);
    this->usuarios.insert(make_pair(dataE.getNick(),e));
    this->estudiantes.insert(make_pair(dataE.getNick(),e));
}

void ControladorUsuarios::nuevoProfesor(DataProfesor dataP){
    Profesor * p = new Profesor(dataP);
    ControladorIdiomas& ci = ControladorIdiomas::getInstance();
    for(auto it = dataP.getIdiomas().begin(); it != dataP.getIdiomas().end(); ++it){
        p->agregarIdioma(ci.encontrarIdioma(it->getNombre()));
    }
    this->usuarios.insert(make_pair(dataP.getNick(),p));
    this->profesores.insert(make_pair(dataP.getNick(),p));
}

list<DataUsuario> ControladorUsuarios::obtenerUsuarios(){
    list<DataUsuario> dataUsuarios;
    for(auto it = this->usuarios.begin(); it != this->usuarios.end(); ++it){
        dataUsuarios.insert(dataUsuarios.end(), it->second->getDataUsuario());
    }
    return dataUsuarios;
}

list<DataEstudiante> ControladorUsuarios::obtenerEstudiantes(){
    list<DataEstudiante> dataEstudiantes;
    for(auto it = this->estudiantes.begin(); it != this->estudiantes.end(); ++it){
        dataEstudiantes.insert(dataEstudiantes.end(), it->second->getDataEstudiante());
    }
    return dataEstudiantes;
}

list<DataProfesor> ControladorUsuarios::obtenerProfesores(){
    list<DataProfesor> dataProfesores;
    for(auto it = this->profesores.begin(); it != this->profesores.end(); ++it){
        dataProfesores.insert(dataProfesores.end(), it->second->getDataProfesor());
    }
    return dataProfesores;
}

Usuario* ControladorUsuarios::encontrarUsuario(string nickname){
    return this->usuarios.find(nickname)->second;
};

Estudiante* ControladorUsuarios::encontrarEstudiante(string nickname){
    return this->estudiantes.find(nickname)->second;
};

Profesor* ControladorUsuarios::encontrarProfesor(string nickname){
    return this->profesores.find(nickname)->second;
};