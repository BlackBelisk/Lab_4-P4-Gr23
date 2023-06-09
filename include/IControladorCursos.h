#ifndef _CLASSICONTROLADORCURSOS_H_
#define _CLASSICONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;
//enum dif {Principiante, Intermedio, Avanzado};

#include "curso.h"
#include "estudiante.h"
#include "dataCurso.h"
#include "dataIdioma.h"
#include "dataUsuario.h"
#include "dataEjercicio.h"
#include "dataLeccion.h"

class IControladorCursos{//Interfaz
   public:
        virtual void crearCurso(string nomCurso, string descCurso, dif difCurso) = 0;
        virtual list<DataCurso> cursosNoAprobadosEstudiante() = 0;
        virtual void elegirProfesor(string nickProfesor) = 0;
        virtual list<DataCurso> listarCursosHab() = 0;
        virtual void agregarPrevia(string nPrevia) = 0;
        virtual void agregarLeccionCN(string nomTema, string objLeccion) = 0;
        virtual void agregarEjercicio(string desc, DataLeccion lec) = 0;
        virtual void finalizarAltaCurso() = 0;
        virtual list<DataIdioma> listarIdiomasProfesor() = 0;
        virtual void crearTraducir(string desc, string fraseT, string solT) = 0;
        virtual void crearCompletar(string desc, string fraseC, vector<string> solC) = 0;
        virtual void eliminarCurso(string nc) = 0;
        virtual void seleccionarEstudiante(string nickE) = 0;
        virtual list<DataCurso> obtenerCursosNoAprobadosEstudiante() = 0;
        virtual void seleccionarCurso(string nombre) = 0;
        virtual list<DataEjercicio> listarEjerciciosNoAprobados() = 0;
        virtual void ingresarSolEjercicioTrad(string resp) = 0;
        virtual bool comprobarSolucionEjercicio() = 0;
        virtual bool comprobarCompletarPalabra() = 0;
        virtual bool comprobarTraducir() = 0;
        virtual string mostrarFraseATraducir() = 0;
        virtual string mostrarFraseACompletar() = 0;
        virtual void ingresarSolEjercicioComp(set<string> respuestas) = 0;
        virtual DataEjercicio enunciarEjercicio() = 0;
        virtual void seleccionarEjercicio(DataEjercicio ej) = 0;
        virtual list<DataCurso> listarCursos() = 0;
        virtual void habilitarCurso(string c) = 0;
        virtual void consultarCurso() = 0;
        virtual ~IControladorCursos(){};
};
#endif