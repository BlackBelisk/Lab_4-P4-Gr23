#include <iostream>
#include <string>

#include "include/usuario.h"
#include "include/estudiante.h"
#include "include/profesor.h"
#include "include/idioma.h"
#include "include/curso.h"
#include "include/leccion.h"
#include "include/ejercicio.h"

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
        }
        else{
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (tipo != "1" && tipo != "2");
    cu->confirmarAltaUsuario(stoi(tipo));
}

// Función para realizar una acción específica del menú
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
            // Alta de idioma
            altaIdioma();
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
