//.h para Fecha

#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>

class Fecha {
private:
  int dia;
  int mes;
  int anio;

public:

  Fecha(int dia, int mes, int anio);

  friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
};

#endif  

// Implemetacion de Fecha

#include <iostream>
#include <string>

  Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
  }

    std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
  }
  

//Enum Dif

enum Dif {
    Principiante,
    Medio,
    Avanzado
}
