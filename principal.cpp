#include <iostream>
#include <string>

#include "include/usuario.h"
#include "include/estudiante.h"
#include "include/profesor.h"
#include "include/idioma.h"
#include "include/curso.h"
#include "include/leccion.h"
#include "include/ejercicio.h"

#include "include/utils.h"
#include "include/excepciones.h"
//Controladores
#include "factory.h"

#include "include/IControladorCursos.h"
#include "include/ControladorCursos.h"

#include "include/IControladorUsuarios.h"
#include "include/ControladorUsuarios.h"

#include "include/IControladorIdiomas.h"
#include "include/ControladorIdiomas.h"

#include "include/IControladorEstadisticas.h"
#include "include/controladorEstadisticas.h"
//Controladores

//Datausuarios 
#include "include/dataCurso.h"
#include "include/dataEjercicio.h"
#include "include/dataLeccion.h"
#include "include/dataEstadistica.h"
#include "include/dataInscripcion.h"
#include "include/dataNotificacion.h"
#include "include/dataUsuario.h"

using namespace std;

// Función para cargar los datos de prueba
void cargarDatosPrueba() {
   
}

void altaUsuario(){
    Factory * factory = Factory::getInstance();
    IControladorUsuarios * cu = factory->getIControladorUsuarios();
    string nickname;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nickname: " << endl;
    getline(cin, nickname);
    if (cu->existeUsuario(nickname))
    {
        throw ExYaExisteUsuario();
    }
    string contra;
    do
    {
        cout << "Ingrese su contrasena (Debe tener al menos 6 caracteres): " << endl;
        getline(cin, contra);
        if (contra.length() < 6)
        {
            cout << "La contrasena debe tener al menos 6 caracteres. Intentelo de nuevo." << endl;
        }
    } while (contra.length() < 6);

    string desc;
    cout << "Ingrese una descripcion: " <<endl;
    getline(cin, desc);

    string nombre;
    cout << "Ingrese su nombre: " << endl;
    getline(cin, nombre);

    DataUsuario dataU = DataUsuario(nickname, contra, desc, nombre);
    cu->ingresarUsuario(dataU);
    string tipo;
    do
    {
        cout << "Ingrese tipo de usuario: " << endl << "1. Estudiante." << endl << "2. Profesor. " << endl;
        getline(cin, tipo);
        if (tipo == "1")
        {
            string pais;
            cout << "Ingrese pais de nacimiento: " << endl;
            getline(cin, pais);
            string fecha;
            cout << "Ingrese su fecha de nacimiento (DD/MM/AAAA): ";
            getline(cin,fecha);
            cu->ingresarDatosEstudiante(pais, Fecha(stoi(fecha.substr(0,2)), stoi(fecha.substr(3,2)), stoi(fecha.substr(6,4))));
        }
        else if (tipo == "2")
        {
            string instituto;
            cout << "Ingrese instituto donde trabaja: " << endl;
            getline(cin, instituto);
            cu->ingresarInstituto(instituto);

            IControladorIdiomas* ci = factory->getIControladorIdiomas();
            list<DataIdioma> listaIdiomas = ci->listarIdiomas();
            imprimirListaDataIdiomas(listaIdiomas);
            cout << "0. Dejar de ingresar idiomas." << endl; 
            int espec;
            do
            {
                cout << "Seleccione el idioma a agregar ingresando el numero: " << endl;
                cin >> espec;
                if (espec < 0 || espec > listaIdiomas.size())
                {
                    cout << "Numero de idioma invalido. Intente nuevamente." << endl;
                }
                else if(espec > 0){
                    auto it = listaIdiomas.begin();
                    advance(it, espec - 1);
                    cu->agregarEspecializacion(*it);
                    cout << "Idioma agregado." << endl;
                }
            } while (espec <= 0 || espec > listaIdiomas.size());
        }
        else{
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (tipo != "1" && tipo != "2");
    cu->confirmarAltaUsuario(stoi(tipo));
}

void consultarUsuario(){
    Factory* factory = Factory::getInstance();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    list<DataUsuario> usuarios = cu->obtenerUsuarios();
    imprimirListaDataUsuarios(usuarios);
    int user;
    do
    {
        cout << "Seleccione el usuario ingresando el numero: " << endl;
        cin >> user;
        if (user < 0 || user > usuarios.size())
        {
            cout << "Numero de usuario invalido. Intente nuevamente" << endl; 
        }
    } while (user < 0 || user > usuarios.size());
    auto it = usuarios.begin();
    advance(it, user - 1);
    if (cu->esEstudiante(it->getNick()))
    {
        DataEstudiante estudiante = cu->obtenerDataEstudiante(it->getNick());
        cout << estudiante << endl;
    }
    else if(cu->esProfesor(it->getNick())){
        DataProfesor profesor = cu->obtenerDataProfesor(it->getNick());
        cout << profesor << endl;
    }   
}

void altaIdioma(){
    Factory * factory = Factory::getInstance();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    string nomIdi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese el nombre del idioma: " << endl;
    getline(cin, nomIdi);
    if (ci->existeIdioma(nomIdi))
    {
        throw ExYaExisteIdioma();
    }
    DataIdioma idioma = DataIdioma(nomIdi);
    ci->ingresarIdioma(idioma);
    ci->confirmarAltaIdioma();
}

void consultarIdiomas(){
    Factory * factory = Factory::getInstance();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataIdioma> listaIdiomas = ci->listarIdiomas();
    imprimirListaDataIdiomas(listaIdiomas);
} 

void altaCurso(){

}

void agregarLeccion(){

}

void agregarEjercicio(){

}

void habilitarCurso(){

    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    list<DataCurso> cursos = cc->listarCursosNA();
    imprimirListaCursos(cursos);
    int course;
        do
        {
            cout << "Seleccione el curso a habilitar ingresando el numero: " << endl;
            cin >> course;
            if (course < 0 || course > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente" << endl; 
            }
        } while (course < 0 || course > cursos.size());
    auto it = cursos.begin();
    advance(it, course - 1);    
    if (it->getCantEjercicios() > 0){cc->habilitarCurso(it->getNomCurso());}
}

void eliminarCurso(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    list<DataCurso> cursos = cc->listarCursos();
    imprimirListaCursos(cursos);
    int course;
    do
    {
        cout << "Seleccione el curso a eliminar ingresando el numero: " << endl;
        cin >> course;
        if (course < 0 || course > cursos.size())
        {
            cout << "Numero de curso invalido. Intente nuevamente" << endl; 
        }
    } while (course < 0 || course > cursos.size());
    auto it = cursos.begin();
    advance(it, course - 1);
    cc->eliminarCurso(it->getNomCurso());
}

void consultarCurso(){

}

void inscribirseACurso(){

}

void realizarEjercicio(){

}

void consultarEstadisticas(){
    Factory* factory = Factory::getInstance();
    IControladorEstadisticas* ce = factory->getIControladorEstadisticas();
    int tipoEstad;
    do
    {
        cout << "Ingrese el tipo de estadistica que quiere consultar: " 
             << endl << "1. Estudiante. "
             << endl << "2. Profesor. "
             << endl << "3. Curso. " << endl;
        if (tipoEstad < 0 || tipoEstad > 3)
        {
            cout << "Numero de estadistica invalida. Intente nuevamente" << endl;
        }
    } while (tipoEstad < 0 || tipoEstad > 3);

    if (tipoEstad == 1)
    {
        IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
        list<DataEstudiante> estudiantes = cUsers->obtenerEstudiantes();
        imprimirListaDataEstudiantes(estudiantes);
        int estud;
        do
        {
            cout << "Seleccione el estudiante ingresando el numero: " << endl;
            cin >> estud;
            if (estud < 0 || estud > estudiantes.size())
            {
                cout << "Numero de estudiante invalido. Intente nuevamente." << endl;
            }
            
        } while (estud < 0 || estud > estudiantes.size());
        auto it = estudiantes.begin();
        advance(it, estud - 1);
        DataEstadisticaEstudiante dataEstadEstud = ce->listarEstadisticaEstudiante(*it);
        cout << "Estadisticas de: " << it->getNick() << endl;
        for (auto it = dataEstadEstud.getAvances().begin(); it != dataEstadEstud.getAvances().end(); it++)
        {
            cout << "Curso: " << it->getCurso() << endl; 
            cout << "Avance: " << it->getAvance() << "%" << endl;
        }
    }
    else if (tipoEstad == 2)
    {
        IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
        list<DataProfesor> profesores = cUsers->obtenerProfesores();
        imprimirListaDataProfesores(profesores);
        int profe;
        do
        {
            cout << "Seleccione el profesor ingresando el numero: " << endl;
            cin >> profe;
            if (profe < 0 || profe > profesores.size())
            {
                cout << "Numero de profesor invalido. Intente nuevamente." << endl;
            }
            
        } while (profe < 0 || profe > profesores.size());
        auto it = profesores.begin();
        advance(it, profe - 1);
        DataEstadisticaProfesor dataEstadProfe = ce->listarEstadisticaProfesor(*it);
        cout << "Estadisticas de: " << it->getNick() << endl;
        for (auto it = dataEstadProfe.getAvances().begin(); it != dataEstadProfe.getAvances().end(); it++)
        {
            cout << "Curso: " << it->getCurso() << endl;
            cout << "Avance: " << it->getAvance() << "%" << endl;
        }
    }
    else if (tipoEstad == 3)
    {
        IControladorCursos* cc = factory->getIControladorCursos();
        list<DataCurso> cursos = cc->listarCursosHab();
        imprimirListaCursos(cursos);
        int curso;
        do
        {
            cout << "Seleccione el curso ingresando el numero: " << endl;
            cin >> curso;
            if (curso < 0 || curso > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente." << endl;
            }
            
        } while (curso < 0 || curso > cursos.size());
        auto it = cursos.begin();
        advance(it, curso - 1);
        DataEstadisticaCurso dataEstadCurso = ce->listarEstadisticaCurso(*it);
        cout << "Nombre del curso: " << dataEstadCurso.getCurso().getNomCurso() << endl;
        cout << "Idioma: " << dataEstadCurso.getCurso().getIdi().getNombre() << endl;
        //Se debe imprimir el nickname o el nombre del profesoR?
        cout << "Profesor: " << dataEstadCurso.getCurso().getProfe().getNick() << endl;
        cout << "Descripción: " << dataEstadCurso.getCurso().getDesc() << endl;
        cout << "Cantidad de lecciones: " << dataEstadCurso.getCurso().getLecciones().size() << endl;
        cout << "Cantidad de ejercicios: " << dataEstadCurso.getCurso().getCantEjercicios() << endl;
        cout << "Promedio general del curso: " << dataEstadCurso.getPromedioGeneral() << "%" << endl;
    }
}

void suscribirseANotificaciones(){
    Factory * factory = Factory::getInstance();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataUsuario> usuarios = cu->obtenerUsuarios();
    imprimirListaDataUsuarios(usuarios);
    int user;
    do
    {
        cout << "Seleccione el usuario ingresando el numero: " << endl;
        cin >> user;
        if (user < 0 || user > usuarios.size())
        {
            cout << "Numero de usuario invalido. Intente nuevamente" << endl; 
        }
    } while (user < 0 || user > usuarios.size());
    auto it = usuarios.begin();
    advance(it, user - 1);
    list<DataIdioma> idiomasDisp = cu->suscripcionesDisponibles(*it);
    imprimirListaDataIdiomas(idiomasDisp);
    cout << "0. Dejar de ingresar idiomas." << endl;
    int susc;
    do
    {
        cout << "Seleccione el idioma al que quiere suscribirse ingresando el numero: " << endl;
        cin >> susc;
        if (susc < 0 || susc > idiomasDisp.size())
        {
            cout << "Numero de idioma invalido. Intente nuevamente." << endl;
        }
        else if (susc > 0)
        {
            auto sus = idiomasDisp.begin();
            advance(sus, susc - 1);
            cu->agregarSuscripcionAusuario(*it,*sus);
            ci->ingresarSuscripcionDeUsuarioA(*sus,*it);
            cout << "Suscripción añadida." << endl;
        }
    } while (susc < 0 || susc > idiomasDisp.size());
}

void consultarNotificaciones(){
    Factory * factory = Factory::getInstance();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    list<DataUsuario> usuarios = cu->obtenerUsuarios();
    imprimirListaDataUsuarios(usuarios);
    int user;
    do
    {
        cout << "Seleccione el usuario ingresando el numero: " << endl;
        cin >> user;
        if (user < 0 || user > usuarios.size())
        {
            cout << "Numero de usuario invalido. Intente nuevamente" << endl; 
        }
    } while (user < 0 || user > usuarios.size());
    auto it = usuarios.begin();
    advance(it, user - 1);
    list<DataNotificacion> notificaciones = cu->consultarNotificaciones(*it);
    imprimirListaNotificaciones(notificaciones);
    cout << "Presione enter para continuar.";
    getchar();
    cu->limpiarNotificaciones(*it);
}

void eliminarSuscripciones(){
    Factory * factory = Factory::getInstance();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataUsuario> usuarios = cu->obtenerUsuarios();
    imprimirListaDataUsuarios(usuarios);
    int user;
    do
    {
        cout << "Seleccione el usuario ingresando el numero: " << endl;
        cin >> user;
        if (user < 0 || user > usuarios.size())
        {
            cout << "Numero de usuario invalido. Intente nuevamente" << endl; 
        }
    } while (user < 0 || user > usuarios.size());
    auto it = usuarios.begin();
    advance(it, user - 1);
    list<DataIdioma> suscripcionesActuales = cu->obtenerSuscripciones(*it);
    imprimirListaDataIdiomas(suscripcionesActuales);
    cout << "0. Dejar de ingresar idiomas." << endl;
    int susc;
    do
    {
        cout << "Seleccione el idioma del que quiere eliminar su suscripcion ingresando el numero: " << endl;
        cin >> susc;
        if (susc < 0 || susc > suscripcionesActuales.size())
        {
            cout << "Numero de idioma invalido. Intente nuevamente." << endl;
        }
        else if (susc > 0)
        {
            auto sus = suscripcionesActuales.begin();
            advance(sus, susc - 1);
            ci->eliminarSuscriptor(*sus, *it);
            cu->eliminarSuscripcionDeUsuario(*it,*sus);
            cout << "Suscripcion removida." << endl;
        }
    } while (susc < 0 || susc > suscripcionesActuales.size());
}

void realizarAccion(int opcion) {
    switch (opcion) {
        case 1:
           try
		{
			altaUsuario();
		}
		catch (const ExYaExisteUsuario& ex)
		{
			cout << "Error: " << ex.what() << endl;
		}
            break;
        case 2:
            // Consulta de usuario
            consultarUsuario();
            break;
        case 3:
            try
            {
                altaIdioma();
            }
            catch (const ExYaExisteIdioma& ex)
            {
                cout << "Error: " << ex.what() << endl;
            }
            break;
        case 4:
            // Consultar idiomas
            consultarIdiomas();
            break;
        case 5:
            // Alta de curso
            altaCurso();
            break;
        case 6:
            // Agregar lección
            agregarLeccion();
            break;
        case 7:
            // Agregar ejercicio
            agregarEjercicio();
            break;
        case 8:
            // Habilitar curso
            habilitarCurso();
            break;
        case 9:
            // Eliminar curso
            eliminarCurso();
            break;
        case 10:
            // Consultar curso
            consultarCurso();
            break;
        case 11:
            // Inscribirse a curso
            inscribirseACurso();
            break;
        case 12:
            // Realizar ejercicio
            realizarEjercicio();
            break;
        case 13:
            // Consultar estadísticas
            consultarEstadisticas();
            break;
        case 14:
            // Suscribirse a notificaciones
            suscribirseANotificaciones();
            break;
        case 15:
            // Consulta de notificaciones
            consultarNotificaciones();
            break;
        case 16:
            // Eliminar suscripciones
            eliminarSuscripciones();
            break;
        case 17:
            // Opción para cargar los datos de prueba
            cargarDatosPrueba();
            break;
        case 18:
            // Opción para salir del programa
            cout << "Saliendo del programa..." << endl;
            exit(0);
        default:
            cout << "Opción inválida. Por favor, selecciona una opción válida." << endl;
    }
}

// Función para mostrar el menú y obtener la opción seleccionada por el usuario
int mostrarMenu() {
    int opcion;
    cout << "===== MENÚ =====" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Consulta de usuario" << endl;
    cout << "3. Alta de idioma" << endl;
    cout << "4. Consultar idiomas" << endl;
    cout << "5. Alta de curso" << endl;
    cout << "6. Agregar lección" << endl;
    cout << "7. Agregar ejercicio" << endl;
    cout << "8. Habilitar curso" << endl;
    cout << "9. Eliminar curso" << endl;
    cout << "10. Consultar curso" << endl;
    cout << "11. Inscribirse a curso" << endl;
    cout << "12. Realizar ejercicio" << endl;
    cout << "13. Consultar estadísticas" << endl;
    cout << "14. Suscribirse a notificaciones" << endl;
    cout << "15. Consulta de notificaciones" << endl;
    cout << "16. Eliminar suscripciones" << endl;
    cout << "17. Cargar datos de prueba" << endl;
    cout << "18. Salir" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cout << endl;
    return opcion;
}

int main() {
    int opcion;
    do {
        opcion = mostrarMenu();
        realizarAccion(opcion);
        cout << endl;
    } while (opcion != 18);

    return 0;
}
