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
#include "controladorIdiomas.h"
#include "curso.h"
#include "dataCurso.h"
#include "dataIdioma.h"
#include "dataUsuario.h"
#include "dataLeccion.h"
#include "dataEjercicio.h"
#include "dataInscripcion.h"


class ControladorCursos : public IControladorCursos{
    private:
            map<string, Curso*> cursos;
            Curso* curso;
            Estudiante* estud;
            Profesor* profe;
            Idioma* idi;
            Leccion* lec;
            Ejercicio* ejSel;
            vector<string> resComp;
            string resTrad;
            int tipo;
            Inscripcion* ins;
            static ControladorCursos* instance;  


            ControladorCursos() = default;
    public:
            void crearCurso(string nomCurso, string descCurso, dif difCurso) override;
            list<DataCurso> listarCursosHab() override;
            list<DataCurso> listarCursosNA() override;
            void agregarPrevia(string nPrevia) override;
            void agregarLeccionCN(string nomTema, string objLeccion) override;
            void agregarEjercicio(string desc, string, string) override;
            void agregarEjercicio(string desc, string, vector<string>) override;
            void finalizarAltaCurso() override;
            list<DataIdioma> listarIdiomasProfesor() override;
            //void crearTraducir(string desc, string fraseT, string solT) override;
            //void crearCompletar(string desc, string fraseC, vector<string> solC) override;
            void eliminarCurso(string nc) override;
            list<DataCurso> obtenerCursosNoAprobadosEstudiante() override;
            list<DataEjercicio> listarEjerciciosNoAprobados() override;
            void ingresarSolEjercicio(string resp) override;
            void comprobarSolucionEjercicio() override;
            bool comprobarCompletarPalabra() override;
            bool comprobarTraducir() override;
            //string mostrarFraseATraducir() override;
            //string mostrarFraseACompletar() override;
            void ingresarSolEjercicio(vector<string> respuestas) override;
            string enunciarEjercicio() override;
            list<DataCurso> listarCursos() override;
            void habilitarCurso(string c) override;
            //void obtenerInformacionCurso(DataCurso) override;
            list<DataCurso> listarCursosDisponibles() override;
            void nuevoCurso(DataCurso) override;
            void insLeccion(string nomCurso, string nomTema, string obj) override;
            void finalizarAgLec() override;
            vector<DataLeccion> listarLecciones() override;
            void darAltaEjercicio() override;
            void finalizarInscripcion() override;
            bool getTipoEjercicio() override;
            bool esCursoHabilitable(string c) override;

            void elegirProfesor(string nickProfesor) override;
            void elegirIdiomaProfesor(DataIdioma) override;
            void seleccionarEstudiante(string nickE) override;
            void seleccionarCurso(string nombre) override;
            void seleccionarEjercicio(DataEjercicio ej) override;
            void seleccionarLeccion(DataLeccion l) override;


            Estudiante* getEstudianteSeleccionado();
            Curso* getCurso();
            Profesor* getProfesorElegido();
            Idioma* getIdiomaElegido();
            Ejercicio* getEjercicioSeleccionado();
            vector<string> getRespuestaEjercicioCompletar();
            Curso* encontrarCurso(string nomCurso);

            static ControladorCursos* getInstance();
};


#endif