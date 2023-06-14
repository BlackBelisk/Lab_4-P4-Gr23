#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "dataIdioma.h"
#include "dataUsuario.h"
#include "dataNotificacion.h"
#include "dataLeccion.h"
#include "dataCurso.h"
using namespace std;

vector<string> convertirAVector(string);

void imprimirListaDataIdiomas(list<DataIdioma> idiomas);

void imprimirListaDataUsuarios(list<DataUsuario> usuarios);

void imprimirListaDataEstudiantes(list<DataEstudiante> estudiantes);

void imprimirListaDataProfesores(list<DataProfesor> profesores);

void imprimirListaCursos(list<DataCurso> cursos);

void imprimirListaNotificaciones(list<DataNotificacion> notificaciones);

void imprimirListaEjercicios(list<DataEjercicio> ejercicios);

void imprimirListaLeccion(vector<DataLeccion> lecciones);

void esperarEnter();