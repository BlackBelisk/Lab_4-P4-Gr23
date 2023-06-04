#include <iostream>
#include <list>
#include <map>
#include "../include/IControladorIdiomas.h"
#include "../include/ControladorIdiomas.h"
#include "../include/idioma.h"
#include "../include/dataIdioma.h"

using namespace std;

ControladorIdiomas* ControladorIdiomas::instancia = nullptr;
ControladorIdiomas* ControladorIdiomas::getInstance(){
    if(instancia==nullptr){instancia = new ControladorIdiomas();}
    return instancia;
}

//map se llama idiomas
//el idioma en memoria idiomaIngresado :)

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