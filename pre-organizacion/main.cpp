
//faltan los parametros de las funciones.
//tambien hay que dejar que el user pueda darle valores a esos parametros de manera interactiva. habria que hacer eso adentro de cada case.
//no estoy seguro de como cargar los datos de prueba. tal vez se hace de otra forma.
//cualquier cosa modifiquen lo que quieran.

//y si, me ayudo mi ia favorita :)

#include <iostream>
#include "algo.h"


// Función para cargar los datos de prueba
void cargarDatosPrueba() {
    // Aquí puedes incluir la lógica para cargar los datos de prueba
    // desde un archivo o inicializarlos manualmente.
    std::cout << "Cargando datos de prueba..." << std::endl;
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
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opción inválida. Por favor, selecciona una opción válida." << std::endl;
    }
}

// Función para mostrar el menú y obtener la opción seleccionada por el usuario
int mostrarMenu() {
    int opcion;
    std::cout << "===== MENÚ =====" << std::endl;
    std::cout << "1. Alta de usuario" << std::endl;
    std::cout << "2. Consulta de usuario" << std::endl;
    std::cout << "3. Alta de idioma" << std::endl;
    std::cout << "4. Consultar idiomas" << std::endl;
    std::cout << "5. Alta de curso" << std::endl;
    std::cout << "6. Agregar lección" << std::endl;
    std::cout << "7. Agregar ejercicio" << std::endl;
    std::cout << "8. Habilitar curso" << std::endl;
    std::cout << "9. Eliminar curso" << std::endl;
    std::cout << "10. Consultar curso" << std::endl;
    std::cout << "11. Inscribirse a curso" << std::endl;
    std::cout << "12. Realizar ejercicio" << std::endl;
    std::cout << "13. Consultar estadísticas" << std::endl;
    std::cout << "14. Suscribirse a notificaciones" << std::endl;
    std::cout << "15. Consulta de notificaciones" << std::endl;
    std::cout << "16. Eliminar suscripciones" << std::endl;
    std::cout << "17. Cargar datos de prueba" << std::endl;
    std::cout << "18. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    std::cout << std::endl;
    return opcion;
}

int main() {
    int opcion;
    do {
        opcion = mostrarMenu();
        realizarAccion(opcion);
        std::cout << std::endl;
    } while (opcion != 18);

    return 0;
}
