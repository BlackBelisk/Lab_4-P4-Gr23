#ifndef _CLASSCONTROLADORCURSOS_H_
#define _CLASSCONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
#include "IControladorCursos.h"
#include "curso.h"

class ControladorCursos : public IControladorCursos{
    private:
            unordered_set<Curso*> cursos;
            Curso* curso;
            Estudiante* estud;
            Profesor* profe;
            Idioma* idi;
            Ejercicio* ejSel;
            vector<string> resComp;
    public:
            void crearCurso(string nomCurso, string descCurso, dif difCurso) override;
            unordered_set<Curso*> cursosNoAprobadosEstudiante() override;
            void elegirProfesor(string nickProfesor) override;
            unordered_set<Curso*> listarCursosHab() override;
            void agregarPrevia(Curso* nPrevia) override;
            void agregarLeccionCN(string nomTema, string objLeccion) override;
            void agregarEjercicio(string desc, Leccion* lec) override;
            void finalizarAltaCurso() override;
            unordered_set<Idioma*> listarIdiomasProfesor() override;
            void crearTraducir(string desc, string fraseT, string solT) override;
            void crearCompletar(string desc, string fraseC, set<string> solC) override;
            void eliminarCurso(Curso c) override;
            void seleccionarEstudiante(string nickE) override;
            unordered_set<Curso*> obtenerCursosNoAprobadosEstudiante() override;
            void seleccionarCurso(Curso c) override;
            unordered_set<Ejercicio*> listarEjerciciosNoAprobados() override;
            void ingresarSolEjercicioTrad(string resp) override;
            bool comprobarSolucionEjercicio() override;
            bool comprobarCompletarPalabra() override;
            bool comprobarTraducir() override;
            string mostrarFraseATraducir() override;
            string mostrarFraseACompletar() override;
            void ingresarSolEjercicioComp(set<string> respuestas) override;
            Ejercicio* enunciarEjercicio() override;
            void seleccionarEjercicio(Ejercicio* ej) override;
            unordered_set<Curso*> listarCursos() override;

            Estudiante* getEstudianteSeleccionado();
            Curso* getCurso();
            Profesor* getProfesorElegido();
            Idioma* getIdiomaElegido();
            Ejercicio* getEjercicioSeleccionado();
            vector<string> getRespuestaEjercicioCompletar();
};


#endif