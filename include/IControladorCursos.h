#ifndef _CLASSICONTROLADORCURSOS_H_
#define _CLASSICONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
//enum dif {Principiante, Intermedio, Avanzado};

#include "curso.h"
#include "estudiante.h"

class IControladorCursos{//Interfaz
   public:
        virtual void crearCurso(string nomCurso, string descCurso, dif difCurso) = 0;
        virtual unordered_set<Curso*> cursosNoAprobadosEstudiante() = 0;
        virtual void elegirProfesor(string nickProfesor) = 0;
        virtual unordered_set<Curso*> listarCursosHab() = 0;
        virtual void agregarPrevia(Curso* nPrevia) = 0;
        virtual void agregarLeccionCN(string nomTema, string objLeccion) = 0;
        virtual void agregarEjercicio(string desc, Leccion* lec) = 0;
        virtual void finalizarAltaCurso() = 0;
        virtual unordered_set<Idioma*> listarIdiomasProfesor() = 0;
        virtual void crearTraducir(string desc, string fraseT, string solT) = 0;
        virtual void crearCompletar(string desc, string fraseC, set<string> solC) = 0;
        virtual void eliminarCurso(Curso c) = 0;
        virtual void seleccionarEstudiante(string nickE) = 0;
        virtual unordered_set<Curso*> obtenerCursosNoAprobadosEstudiante() = 0;
        virtual void seleccionarCurso(Curso c) = 0;
        virtual unordered_set<Ejercicio*> listarEjerciciosNoAprobados() = 0;
        virtual void ingresarSolEjercicioTrad(string resp) = 0;
        virtual bool comprobarSolucionEjercicio() = 0;
        virtual bool comprobarCompletarPalabra() = 0;
        virtual bool comprobarTraducir() = 0;
        virtual string mostrarFraseATraducir() = 0;
        virtual string mostrarFraseACompletar() = 0;
        virtual void ingresarSolEjercicioComp(set<string> respuestas) = 0;
        virtual Ejercicio enunciarEjercicio() = 0;
        virtual void seleccionarEjercicio(Ejercicio ej) = 0;
        virtual unordered_set<Curso*> listarCursos() = 0;
        virtual ~IControladorCursos(){};
};
#endif