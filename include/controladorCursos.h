#ifndef _CLASSCONTROLADORCURSOS_H_
#define _CLASSCONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <set>

using namespace std;
#include "IControladorCursos.h"
#include "controladorUsuarios.h"
#include "curso.h"
#include "dataCurso.h"
#include "dataIdioma.h"
#include "dataUsuario.h"
#include "dataLeccion.h"
#include "dataEjercicio.h"

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
            set<DataCurso*> cursosNoAprobadosEstudiante() override;
            set<DataCurso*> listarCursosHab() override;
            void agregarPrevia(DataCurso* nPrevia) override;
            void agregarLeccionCN(string nomTema, string objLeccion) override;
            void agregarEjercicio(string desc, DataLeccion* lec) override;
            void finalizarAltaCurso() override;
            set<DataIdioma*> listarIdiomasProfesor() override;
            void crearTraducir(string desc, string fraseT, string solT) override;
            void crearCompletar(string desc, string fraseC, vector<string> solC) override;
            void eliminarCurso(DataCurso* c) override;
            set<DataCurso*> obtenerCursosNoAprobadosEstudiante() override;
            set<DataEjercicio*> listarEjerciciosNoAprobados() override;
            void ingresarSolEjercicioTrad(string resp) override;
            bool comprobarSolucionEjercicio() override;
            bool comprobarCompletarPalabra() override;
            bool comprobarTraducir() override;
            string mostrarFraseATraducir() override;
            string mostrarFraseACompletar() override;
            void ingresarSolEjercicioComp(set<string> respuestas) override;
            DataEjercicio* enunciarEjercicio() override;
            set<DataCurso*> listarCursos() override;
            void habilitarCurso(DataCurso* c) override;
            void consultarCurso() override;
            set<DataCurso*> listarCursosDisponibles(string nick);


            void elegirProfesor(string nickProfesor) override;
            void seleccionarEstudiante(string nickE) override;
            void seleccionarCurso(DataCurso* c) override;
            void seleccionarEjercicio(DataEjercicio* ej) override;


            Estudiante* getEstudianteSeleccionado();
            Curso* getCurso();
            Profesor* getProfesorElegido();
            Idioma* getIdiomaElegido();
            Ejercicio* getEjercicioSeleccionado();
            vector<string> getRespuestaEjercicioCompletar();


            static ControladorCursos& getInstance();
};


#endif