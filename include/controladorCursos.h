#ifndef _CLASSCONTROLADORCURSOS_H_
#define _CLASSCONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>

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
            map<string, Curso*> cursos;
            Curso* curso;
            Estudiante* estud;
            Profesor* profe;
            Idioma* idi;
            Ejercicio* ejSel;
            vector<string> resComp;
            static ControladorCursos* instance;    

            ControladorCursos() = default;
    public:
            void crearCurso(string nomCurso, string descCurso, dif difCurso) override;
            list<DataCurso> cursosNoAprobadosEstudiante() override;
            list<DataCurso> listarCursosHab() override;
            void agregarPrevia(string nPrevia) override;
            void agregarLeccionCN(string nomTema, string objLeccion) override;
            void agregarEjercicio(string desc, DataLeccion lec) override;
            void finalizarAltaCurso() override;
            list<DataIdioma> listarIdiomasProfesor() override;
            void crearTraducir(string desc, string fraseT, string solT) override;
            void crearCompletar(string desc, string fraseC, vector<string> solC) override;
            void eliminarCurso(string nc) override;
            list<DataCurso> obtenerCursosNoAprobadosEstudiante() override;
            list<DataEjercicio> listarEjerciciosNoAprobados() override;
            void ingresarSolEjercicioTrad(string resp) override;
            bool comprobarSolucionEjercicio() override;
            bool comprobarCompletarPalabra() override;
            bool comprobarTraducir() override;
            string mostrarFraseATraducir() override;
            string mostrarFraseACompletar() override;
            void ingresarSolEjercicioComp(set<string> respuestas) override;
            DataEjercicio enunciarEjercicio() override;
            list<DataCurso> listarCursos() override;
            void habilitarCurso(string c) override;
            void consultarCurso() override;
            list<DataCurso> listarCursosDisponibles(string nick);


            void elegirProfesor(string nickProfesor) override;
            void seleccionarEstudiante(string nickE) override;
            void seleccionarCurso(DataCurso c) override;
            void seleccionarEjercicio(DataEjercicio ej) override;


            Estudiante* getEstudianteSeleccionado();
            Curso* getCurso();
            Profesor* getProfesorElegido();
            Idioma* getIdiomaElegido();
            Ejercicio* getEjercicioSeleccionado();
            vector<string> getRespuestaEjercicioCompletar();


            static ControladorCursos* getInstance();
};


#endif