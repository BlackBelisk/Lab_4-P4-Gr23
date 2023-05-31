#include <iostream>
#include <string>
#include <ctime>
#include "../include/fecha.h"
using namespace std;

  Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
  }
  Fecha::Fecha(){
    time_t hoy = time(nullptr);
    tm* localTime = localtime(&hoy);
    dia = localTime->tm_mday + 1900;
    mes = localTime->tm_mon + 1;
    anio = localTime->tm_year;
  }

    std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
  }
  
  string Fecha::toString(){
    return to_string(dia) +  "/" + to_string(mes) + "/" + to_string(anio);
  }