//faltan los parametros de las funciones.
//tambien hay que dejar que el user pueda darle valores a esos parametros de manera interactiva. habria que hacer eso adentro de cada case.
//no estoy seguro de como cargar los datos de prueba. tal vez se hace de otra forma.
//cualquier cosa modifiquen lo que quieran.

//y si, me ayudo mi ia favorita :)

#include <iostream>
#include "algo.h"

using namespace std;

// Función para cargar los datos de prueba
void cargarDatosPrueba() {
    // Aquí puedes incluir la lógica para cargar los datos de prueba
    // desde un archivo o inicializarlos manualmente.
    cout << "Cargando datos de prueba..." << endl;
    // Código para cargar los datos de prueba
    // Llamadas a funciones correspondientes
    altaUsuario("John Doe"...);
    altaIdioma("Inglés"...);
    altaCurso("Programación en C++"...);
    // ...
}

// Función para realizar una acción específica del menú
void realizarAccion(int opcion) {
    switch (opcion) {
        case 1:
            // Alta de usuario
            altaUsuario();
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
