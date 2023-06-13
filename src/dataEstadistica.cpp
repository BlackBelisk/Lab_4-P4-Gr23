#include <iostream>
#include <string>
#include <list>
#include "../include/dataEstadistica.h"
#include "dataCurso.h"
using namespace std;

DataAvance::DataAvance(string curso, int avance): curso(curso), avance(avance){};

string DataAvance::getCurso() const{return this->curso;}

float DataAvance::getAvance() const{return this->avance;}

DataEstadisticaEstudiante::DataEstadisticaEstudiante(list<DataAvance> avances): avancesEstudiante(avances){};

list<DataAvance> DataEstadisticaEstudiante::getAvances() const{return this->avancesEstudiante;}

DataEstadisticaProfesor::DataEstadisticaProfesor(list<DataAvance> avances):avancesCursos(avances){};

list<DataAvance> DataEstadisticaProfesor::getAvances() const{return this->avancesCursos;}

DataEstadisticaCurso::DataEstadisticaCurso(DataCurso curso, int prom):curso(curso), promedioGeneral(prom){};

DataCurso DataEstadisticaCurso::getCurso() const{return this->curso;}

float DataEstadisticaCurso::getPromedioGeneral() const{return this->promedioGeneral;}

