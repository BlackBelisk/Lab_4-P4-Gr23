#include <iostream>
#include <string>
#include "../include/fecha.h"

  Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
  }

    std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
  }
  
