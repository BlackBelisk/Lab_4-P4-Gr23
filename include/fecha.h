#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>
using namespace std;

class Fecha {
private:
  int dia;
  int mes;
  int anio;

public:

  Fecha(int dia, int mes, int anio);
  Fecha();

  friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
  string toString();
};

#endif  