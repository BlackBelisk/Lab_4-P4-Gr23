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