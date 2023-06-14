#include <iostream>
#include <string>
#include <list>
#include <map>
#include "../include/IControladorUsuarios.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorIdiomas.h"

using namespace std;

ControladorUsuarios* ControladorUsuarios::instancia = nullptr;
ControladorUsuarios* ControladorUsuarios::getInstance() {
    if(instancia == nullptr){instancia = new ControladorUsuarios();}
    return instancia;
}

void ControladorUsuarios::setDataUsuarioIngresado(DataUsuario dataU){
    this->usuarioIngresado = dataU;
};

DataUsuario ControladorUsuarios::getDataUsuarioIngresado(){
    return this->usuarioIngresado;
}

bool ControladorUsuarios::existeUsuario(string nickname){
    return this->usuarios.count(nickname) > 0;
}

bool ControladorUsuarios::esEstudiante(string nickname){
    return this->estudiantes.count(nickname) > 0;
}

bool ControladorUsuarios::esProfesor(string nickname){
    return this->profesores.count(nickname) > 0;
}

void ControladorUsuarios::ingresarUsuario(DataUsuario dataU){
    this->setDataUsuarioIngresado(dataU);
};

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
    
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    
    for(auto it = this->especializacionesProfesor.begin(); it != this->especializacionesProfesor.end(); ++it){
        p->agregarIdioma(ci->encontrarIdioma(it->getNombre()));
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
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    list<DataIdioma> idiomas = dataP.getIdiomas();
    for(auto it = idiomas.begin(); it != idiomas.end(); ++it){
           p->agregarIdioma(ci->encontrarIdioma(it->getNombre()));
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
    if (existeUsuario(nickname))
    {
        return this->usuarios.find(nickname)->second;
    }
    return nullptr;
};

Estudiante* ControladorUsuarios::encontrarEstudiante(string nickname){
    if (esEstudiante(nickname))
    {
        return this->estudiantes.find(nickname)->second;
    }
    return nullptr;
};

Profesor* ControladorUsuarios::encontrarProfesor(string nickname){
    if (esProfesor(nickname))
    {
        return this->profesores.find(nickname)->second;
    }
    return nullptr;
};

DataUsuario ControladorUsuarios::obtenerDataUsuario(string nickname){
    Usuario * user = encontrarUsuario(nickname);
    if (user != nullptr)
    {
        return user->getDataUsuario();
    }
    return DataUsuario();
}

DataProfesor ControladorUsuarios::obtenerDataProfesor(string nickname){
    Profesor* profe = encontrarProfesor(nickname);
    if (profe != nullptr)
    {
        return profe->getDataProfesor();
    }
    return DataProfesor();
}

DataEstudiante ControladorUsuarios::obtenerDataEstudiante(string nickname){
    Estudiante * estud = encontrarEstudiante(nickname);
    if (estud != nullptr)
    {
        return estud->getDataEstudiante();
    }
    return DataEstudiante();
}

list<DataNotificacion> ControladorUsuarios::consultarNotificaciones(DataUsuario user){
    Usuario* u = encontrarUsuario(user.getNick());
    list<DataNotificacion> notificaciones = u->obtenerNotificaciones();
    return notificaciones;
}

void ControladorUsuarios::limpiarNotificaciones(DataUsuario user){
    Usuario* u = encontrarUsuario(user.getNick());
    u->eliminarNotificaciones();
}

list<DataIdioma> ControladorUsuarios::obtenerSuscripciones(DataUsuario user){
    Usuario* u = encontrarUsuario(user.getNick());
    list<DataIdioma> suscripciones = u->obtenerSuscripciones();
    return suscripciones;
}

list<DataIdioma> ControladorUsuarios::suscripcionesDisponibles(DataUsuario user){
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    Usuario* u = encontrarUsuario(user.getNick());
    list<DataIdioma> disponibles = ci->suscripcionesDisponiblesPara(u);
    return disponibles;
}

void ControladorUsuarios::agregarSuscripcionAusuario(DataUsuario user, DataIdioma idi){
    Usuario* u = encontrarUsuario(user.getNick());
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    Idioma* susc = ci->encontrarIdioma(idi.getNombre());
    u->agregarSuscripcion(susc);
}

void ControladorUsuarios::eliminarSuscripcionDeUsuario(DataUsuario user, DataIdioma idi){
    Usuario* u = encontrarUsuario(user.getNick());
    ControladorIdiomas* ci = ControladorIdiomas::getInstance();
    Idioma* susc = ci->encontrarIdioma(idi.getNombre());
    u->removerSuscripcionAIdioma(susc);
}
