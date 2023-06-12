#include <iostream>
#include <list>
#include <map>
#include "../include/IControladorIdiomas.h"
#include "../include/ControladorIdiomas.h"
#include "../include/controladorUsuarios.h"
#include "../include/idioma.h"
#include "../include/dataIdioma.h"

using namespace std;

ControladorIdiomas* ControladorIdiomas::instancia = nullptr;
ControladorIdiomas* ControladorIdiomas::getInstance(){
    if(instancia==nullptr){instancia = new ControladorIdiomas();}
    return instancia;
}

bool ControladorIdiomas::existeIdioma(string nombre){
    return this->idiomas.count(nombre) > 0;
}
DataIdioma ControladorIdiomas::obtenerDataIdioma(string nombre){
    if (existeIdioma(nombre))
    {
        return this->idiomas.find(nombre)->second->getDataIdioma();
    }
    return DataIdioma();
}
list<DataIdioma> ControladorIdiomas::listarIdiomas(){
    list<DataIdioma> dataIdiomas;
    for(auto it = this->idiomas.begin(); it!= this->idiomas.end();it++){
        dataIdiomas.insert(dataIdiomas.end(), it->second->getDataIdioma());
    }
    return dataIdiomas;
}

Idioma* ControladorIdiomas::encontrarIdioma(string nomIdi){
    return this->idiomas.find(nomIdi)->second;}

void ControladorIdiomas::setDataIdiomaIngresado(DataIdioma dataI){
    this->idiomaIngresado = dataI;
}

DataIdioma ControladorIdiomas::getDataIdiomaIngresado(){
    return this->idiomaIngresado;
}

void ControladorIdiomas::ingresarIdioma(DataIdioma dataI){
    this->setDataIdiomaIngresado(dataI);
};

void ControladorIdiomas::confirmarAltaIdioma(){
    DataIdioma dataI = this->getDataIdiomaIngresado();
    Idioma* i = new Idioma(dataI);
    this->idiomas.insert(make_pair(dataI.getNombre(),i));
};

void ControladorIdiomas::nuevoIdioma(DataIdioma dataI){
    Idioma* i = new Idioma(dataI);
    this->idiomas.insert(make_pair(dataI.getNombre(),i));
};

bool ControladorIdiomas::estaSuscritoA(IObserver* susc, Idioma* idi){
    return idi->estaSuscrito(susc);
}

list<DataIdioma> ControladorIdiomas::suscripcionesDisponiblesPara(IObserver* obs){
    list<DataIdioma> disp;
    for (auto it = idiomas.begin(); it != idiomas.end(); it++)
    {
        if (!estaSuscritoA(obs,it->second))
        {
            disp.push_back(it->second->getDataIdioma());
        }
    }
    return disp;
}

void ControladorIdiomas::ingresarSuscripcionDeUsuarioA(DataIdioma idi, DataUsuario susc){
        Idioma* idioma = this->encontrarIdioma(idi.getNombre());
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        Usuario* user = cu->encontrarUsuario(susc.getNick());
        idioma->agregarUsuarioSuscripto(user);
}

void ControladorIdiomas::eliminarSuscriptor(DataIdioma idi, DataUsuario susc){
    Idioma* idioma = this->encontrarIdioma(idi.getNombre());
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        Usuario* user = cu->encontrarUsuario(susc.getNick());
        idioma->removerObservador(user);
}