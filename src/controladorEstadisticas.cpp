#include <iostream>
#include <string>
#include <list>

#include "../include/IControladorEstadisticas.h"
#include "../include/controladorEstadisticas.h"
#include "../include/controladorUsuarios.h"
#include "../include/controladorCursos.h"
using namespace std;

ControladorEstadisticas* ControladorEstadisticas::instancia = nullptr;

ControladorEstadisticas* ControladorEstadisticas::getInstance(){
    if(instancia == nullptr){instancia = new ControladorEstadisticas();}
    return instancia;
}

DataEstadisticaEstudiante ControladorEstadisticas::listarEstadisticaEstudiante(DataEstudiante estud){
    ControladorUsuarios * cu = ControladorUsuarios::getInstance();
    list<DataAvance> avances;
    Estudiante* e = cu->encontrarEstudiante(estud.getNick());

    map<string, Inscripcion*> enCurso = e->getenCurso();
    map<string, Inscripcion*> aprobados = e->getAprobados();

    for (auto it  = enCurso.begin(); it != enCurso.end(); it++)
    {
        avances.push_back(DataAvance(it->second->getCurso()->getNombre(),it->second->obtenerProgreso()));
    }

    for (auto it  = aprobados.begin(); it != aprobados.end(); it++)
    {
        avances.push_back(DataAvance(it->second->getCurso()->getNombre(),it->second->obtenerProgreso()));
    }
    DataEstadisticaEstudiante dee = DataEstadisticaEstudiante(avances);
    return dee;
}

DataEstadisticaProfesor ControladorEstadisticas::listarEstadisticaProfesor(DataProfesor profe){
    ControladorUsuarios * cu = ControladorUsuarios::getInstance();
    list<DataAvance> avancesProfe;

    Profesor * p = cu->encontrarProfesor(profe.getNick());
    set<Curso*> cursos = p->getCursosProp();

    for (auto it = cursos.begin(); it != cursos.end(); it++)
    {
        avancesProfe.push_back(DataAvance((*it)->getNombre(),(*it)->obtenerPromedioCurso()));
    }

    DataEstadisticaProfesor dep = DataEstadisticaProfesor(avancesProfe);
    return dep;  
}

DataEstadisticaCurso ControladorEstadisticas::listarEstadisticaCurso(DataCurso curso){
    ControladorCursos * cc = ControladorCursos::getInstance();
    Curso * c = cc->encontrarCurso(curso.getNomCurso());
    DataEstadisticaCurso avancesCurso = DataEstadisticaCurso(curso, c->obtenerPromedioCurso());
    return avancesCurso;
}