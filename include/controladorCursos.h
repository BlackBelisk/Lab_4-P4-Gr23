#ifndef _CLASSCONTROLADORCURSOS_H_
#define _CLASSCONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <set>

using namespace std;
#include "IControladorCursos.h"
#include "controladorUsuarios.h"
#include "curso.h"

class ControladorCursos : public IControladorCursos{
    private:
            set<Curso*> cursos;
            Curso* curso;
            Estudiante* estud;
            Profesor* profe;
            Idioma* idi;
            Ejercicio* ejSel;
            vector<string> resComp;
    public:
            void crearCurso(string nomCurso, string descCurso, dif difCurso) override;
            set<Curso*> cursosNoAprobadosEstudiante() override;
            set<Curso*> listarCursosHab() override;
            void agregarPrevia(Curso* nPrevia) override;
            void agregarLeccionCN(string nomTema, string objLeccion) override;
            void agregarEjercicio(string desc, Leccion* lec) override;
            void finalizarAltaCurso() override;
            set<Idioma*> listarIdiomasProfesor() override;
            void crearTraducir(string desc, string fraseT, string solT) override;
            void crearCompletar(string desc, string fraseC, vector<string> solC) override;
            void eliminarCurso(Curso* c) override;
            set<Curso*> obtenerCursosNoAprobadosEstudiante() override;
            set<Ejercicio*> listarEjerciciosNoAprobados() override;
            void ingresarSolEjercicioTrad(string resp) override;
            bool comprobarSolucionEjercicio() override;
            bool comprobarCompletarPalabra() override;
            bool comprobarTraducir() override;
            string mostrarFraseATraducir() override;
            string mostrarFraseACompletar() override;
            void ingresarSolEjercicioComp(set<string> respuestas) override;
            Ejercicio* enunciarEjercicio() override;
            set<Curso*> listarCursos() override;
            void habilitarCurso(Curso* c) override;
            void consultarCurso() override;
            set<Curso*> listarCursosDisponibles(string nick);


            void elegirProfesor(string nickProfesor) override;
            void seleccionarEstudiante(string nickE) override;
            void seleccionarCurso(Curso* c) override;
            void seleccionarEjercicio(Ejercicio* ej) override;


            Estudiante* getEstudianteSeleccionado();
            Curso* getCurso();
            Profesor* getProfesorElegido();
            Idioma* getIdiomaElegido();
            Ejercicio* getEjercicioSeleccionado();
            vector<string> getRespuestaEjercicioCompletar();


            static ControladorCursos& getInstance();
};


#endif