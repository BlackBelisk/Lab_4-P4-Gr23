#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <list>
#include <set>

//Controladores

#include "include/dataIdioma.h"
#include "include/dataUsuario.h"
#include "include/dataCurso.h"
#include "include/dataEjercicio.h"
#include "include/dataLeccion.h"
#include "include/dataEstadistica.h"
#include "include/dataInscripcion.h"
#include "include/dataNotificacion.h"
#include "include/utils.h"

#include "include/usuario.h"
#include "include/estudiante.h"
#include "include/profesor.h"
#include "include/idioma.h"
#include "include/curso.h"
#include "include/leccion.h"
#include "include/ejercicio.h"

#include "include/factory.h"
#include "include/IControladorCursos.h"
#include "include/ControladorCursos.h"

#include "include/IControladorUsuarios.h"
#include "include/ControladorUsuarios.h"

#include "include/IControladorIdiomas.h"
#include "include/ControladorIdiomas.h"

#include "include/IControladorEstadisticas.h"
#include "include/controladorEstadisticas.h"
//Controladores
#include "include/excepciones.h"
//Datausuarios 


using namespace std;

// Función para cargar los datos de prueba
void cargarDatosPrueba() {
    Factory * factory = Factory::getInstance();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    IControladorCursos* cc = factory->getIControladorCursos();
    
    /* Idiomas */
    /* DataIdioma */
    /* I1 */ DataIdioma ingles = DataIdioma("Ingles");
    /* I2 */ DataIdioma aleman = DataIdioma("Aleman");
    /* I3 */ DataIdioma portugues = DataIdioma("Portugues");
    /* DataIdioma */

    /* Ingreso de Idiomas */
    /* I1 */ ci->nuevoIdioma(ingles);
    /* I2 */ ci->nuevoIdioma(aleman);
    /* I3 */ ci->nuevoIdioma(portugues);
    /* Ingreso de Idiomas */
    /* Idiomas */

    /* Usuarios */ 
    /* Estudiantes */
    /* U1 */ DataEstudiante jpidiom = DataEstudiante("jpidiom","asdfg123","Soy un apasionado del aprendizaje de idiomas.","Juan Perez", "Argentina", Fecha(15,7,1995));
    /* U2 */ DataEstudiante marsilva = DataEstudiante("marsilva", "qwer456", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Maria Silva", "Ecuador", Fecha(28,2,1998));
    /* U3 */ DataEstudiante pero12 = DataEstudiante("pero12", "789werty", "Soy un entusiasta del aprendizaje de idiomas.", "Pedro Rodriguez", "Peru", Fecha(10,11,1994));
    /* U4 */ DataEstudiante laugu = DataEstudiante("laugu", "c1v2b3m4", "Estoy fascinada por la forma en que las palabras pueden unir a las personas.", "Laura Gutierrez", "Chile", Fecha(22,4,1997));
    /* U5 */ DataEstudiante carlo22 = DataEstudiante("carlo22", "tyuipz147", "Emocionado por adquirir fluidez en diferentes lenguas.", "Carlos Lopez", "Uruguay", Fecha(3,9,1996));
    /* U6 */ DataEstudiante anator = DataEstudiante("anator", "1qsxc36", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Ana Torres", "Argentina", Fecha(12,1,1999));
    /* U7 */ DataEstudiante luher24 = DataEstudiante("luher24", "t7h8y5u6", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Lucia Hernandez", "Colombia", Fecha(25,6,1993));
    /* U8 */ DataEstudiante dagon = DataEstudiante("dagon", "1w2e3r4t5","Aprender nuevas lenguas y sumergirme en diferentes culturas.", "David Gonzalez", "Uruguay", Fecha(9,12,1997));
    /* U9 */ DataEstudiante carmor = DataEstudiante("carmor", "6yu7i8m9", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Carmen Morales", "Chile", Fecha(17,3,1995));
    /*U10 */ DataEstudiante jose24 = DataEstudiante("jose24", "qwj789p", "Disfruto del proceso de descubrir nuevas formas de comunicarme.", "Jose Fernandez", "Bolivia", Fecha(2,8,1998));
    /* Estudiantes */

    /* Ingreso de estudiantes */
    /* U1 */ cu->nuevoEstudiante(jpidiom);
    /* U2 */ cu->nuevoEstudiante(marsilva);
    /* U3 */ cu->nuevoEstudiante(pero12);
    /* U4 */ cu->nuevoEstudiante(laugu);
    /* U5 */ cu->nuevoEstudiante(carlo22);
    /* U6 */ cu->nuevoEstudiante(anator);
    /* U7 */ cu->nuevoEstudiante(luher24);
    /* U8 */ cu->nuevoEstudiante(dagon);
    /* U9 */ cu->nuevoEstudiante(carmor);
    /*U10 */ cu->nuevoEstudiante(jose24);
    /* Ingreso de estudiantes */

    /* Lista de Idiomas para profesores */
    list<DataIdioma> u11 = {ingles, portugues};
    list<DataIdioma> u12 = {ingles, aleman, portugues};
    list<DataIdioma> u13 = {aleman};
    list<DataIdioma> u14 = {portugues};
    list<DataIdioma> u15 = {ingles};
    /* Lista de Idiomas para profesores */

    /* Profesores */
    /* U11 */ DataProfesor langMaster = DataProfesor("langMaster", "P4s512", "Soy una profesora apasionada por los idiomas.", "Marta Grecia", "Instituto de Idiomas Moderno", u11);
    /* U12 */ DataProfesor linguaPro = DataProfesor("linguaPro", "Pess23", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Carlos Petro", "Centro Global", u12);
    /* U13 */ DataProfesor talkExpert = DataProfesor("talkExpert","Secret1", "Soy una profesora entusiasta del aprendizaje de idiomas", "Laura Perez","Instituto de Idiomas Vanguardia", u13);
    /* U14 */ DataProfesor lingoSensei = DataProfesor("lingoSensei","Secure2", "Apasionado en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", "Franco Lopez","Centro de Idiomas", u14);
    /* U15 */ DataProfesor wordMaestro = DataProfesor("wordMaestro","Passw0","Soy una profesora comprometida en desarrollo de habilidades idiomaticas","Ana Morales","Instituto de Idiomas Progreso",u15);
    // /* Profesores */
    // /* Ingreso de profesores */
    /* U11 */ cu->nuevoProfesor(langMaster);
    /* U12 */ cu->nuevoProfesor(linguaPro);
    /* U13 */ cu->nuevoProfesor(talkExpert);
    /* U14 */ cu->nuevoProfesor(lingoSensei);
    /* U15 */ cu->nuevoProfesor(wordMaestro);
    /* Ingreso de profesores */
    /* Usuarios */


    /* Vectores completar */
    /* R1 */ vector<string> R1 = {"allow", "myself"};
    /* R2 */ vector<string> R2 = {"some"};
    /* R3 */ vector<string> R3 = {"up"};
    /* R4 */ vector<string> R4 = {"have", "past"};
    /* Vectores completar */


    /* Ejercicios */
    /* E1 */ DataEjercicio e1 = DataEjercicio("Presentaciones", "Mucho gusto en conocerte", "Nice to meet you");
    /* E2 */ DataEjercicio e2 = DataEjercicio("Presentaciones formales", "Please — me to introduce —", R1);
    /* E3 */ DataEjercicio e3 = DataEjercicio("Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
    /* E4 */ DataEjercicio e4 = DataEjercicio("Sustantivos contables en plural", "Can I have — water, please?", R2);
    /* E5 */ DataEjercicio e5 = DataEjercicio("Actividades diarias", "Wake —", R3);
    /* E6 */ DataEjercicio e6 = DataEjercicio("Consultas de la hora", "Q: Do you — the time?, A: Yes, it is half — 4", R4);
    /* E7 */ DataEjercicio e7 = DataEjercicio("Dar consejos o expresar obligacion", "You should visit that museum", "Deberias visitar ese museo");
    /* E8 */ DataEjercicio e8 = DataEjercicio("Imperativo", "Fale comigo", "Habla conmigo");
    /* Ejercicios */


    /* Listas de Ejercicios */
    /* L1 */ list<DataEjercicio> L1 = {e1, e2};
    /* L2 */ list<DataEjercicio> L2 = {e3, e4};
    /* L3 */ list<DataEjercicio> L3 = {e5};
    /* L4 */ list<DataEjercicio> L4 = {};
    /* L5 */ list<DataEjercicio> L5 = {e6};
    /* L6 */ list<DataEjercicio> L6 = {e7};
    /* L7 */ list<DataEjercicio> L7 = {e8};
    /* Listas de Ejercicios */


    /* Lecciones */
    /* L1 */ DataLeccion l1 = DataLeccion("Saludos y Presentaciones", "Aprender a saludar y despedirse", L1, 0);
    /* L2 */ DataLeccion l2 = DataLeccion("Articulos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", L2, 1);
    /* L3 */ DataLeccion l3 = DataLeccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", L3, 2);
    /* L4 */ DataLeccion l4 = DataLeccion("Presente Simple", "Aprender el uso del presente simple", L4, 3);
    /* L5 */ DataLeccion l5 = DataLeccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes", L5, 4);
    /* L6 */ DataLeccion l6 = DataLeccion("Uso de modales avanzados", "Explorar el uso de los modales complejos", L6, 5);
    /* L7 */ DataLeccion l7 = DataLeccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas", L7, 6);
    /* Lecciones */


    /* Listas de Lecciones */
    /* C1 */ vector<DataLeccion> C1 = {l1, l2};
    /* C2 */ vector<DataLeccion> C2 = {l3, l4};
    /* C3 */ vector<DataLeccion> C3 = {l5};
    /* C4 */ vector<DataLeccion> C4 = {l6};
    /* C5 */ vector<DataLeccion> C5 = {l7};
    /* C6 */ vector<DataLeccion> C6 = {};
    /* Listas de Lecciones */


    /* Listas de Ejercicios Aprobados */
    /* N1 */ list<DataEjercicio> N1 = {e1, e2, e3, e4};
    /* N2 */ list<DataEjercicio> N2 = {e6};
    /* N3 */ list<DataEjercicio> N3 = {};
    /* N4 */ list<DataEjercicio> N4 = {e1,e2};
    /* N5 */ list<DataEjercicio> N5 = {e1, e2, e4};
    /* N6 */ list<DataEjercicio> N6 = {};
    /* N7 */ list<DataEjercicio> N7 = {};
    /* N8 */ list<DataEjercicio> N8 = {};
    /* Listas de Ejercicios Aprobados */


    /* Fechas de inscripcion */
    /* N1 */ Fecha f1 = Fecha(01,01,2022);
    /* N2 */ Fecha f2 = Fecha(12,06,2022);
    /* N3 */ Fecha f3 = Fecha(02,03,2023);
    /* N4 */ Fecha f4 = Fecha(02,01,2022);
    /* N5 */ Fecha f5 = Fecha(02,01,2022);
    /* N6 */ Fecha f6 = Fecha(03,01,2023);
    /* N7 */ Fecha f7 = Fecha(03,01,2023);
    /* N8 */ Fecha f8 = Fecha(05,01,2023);
    /* Fechas de inscripcion */


    /* Lecciones */
    /* N1 */ DataInscripcion n1 = DataInscripcion(jpidiom.getNick(), jpidiom.getNombre(), "Ingles para principiantes", l2, N1, f1, true);
    /* N2 */ DataInscripcion n2 = DataInscripcion(jpidiom.getNick(), jpidiom.getNombre(), "Ingles intermedio: mejora tu nivel", l5, N2, f2, true);
    /* N3 */ DataInscripcion n3 = DataInscripcion(jpidiom.getNick(), jpidiom.getNombre(), "Curso avanzado de ingles", l6, N3, f3, false);
    /* N4 */ DataInscripcion n4 = DataInscripcion(marsilva.getNick(), marsilva.getNombre(), "Ingles para principiantes", l2, N4, f4, false);
    /* N5 */ DataInscripcion n5 = DataInscripcion(pero12.getNick(), pero12.getNombre(), "Ingles para principiantes", l2, N5, f5, false);
    /* N6 */ DataInscripcion n6 = DataInscripcion(laugu.getNick(), laugu.getNombre(), "Ingles para principiantes", l1, N6, f6, false);
    /* N7 */ DataInscripcion n7 = DataInscripcion(laugu.getNick(), laugu.getNombre(), "Portugues intermedio", l7, N7, f7, false);
    /* N8 */ DataInscripcion n8 = DataInscripcion(carlo22.getNick(), carlo22.getNombre(), "Portugues intermedio", l7, N8, f8, false);
    /* Lecciones */


    /* Cursos, inscripciones y previas */
    /* C1 */ list<DataCurso> P1 = {};
    /* C1 */ list<DataInscripcion> I1 = {n1, n4, n5, n6};
    /* C1 */ DataCurso c1 = DataCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", Principiante, true, ingles, langMaster, C1, I1, P1, 4);
    /* C2 */ list<DataCurso> P2 = {};
    /* C2 */ list<DataInscripcion> I2 = {};
    /* C2 */ DataCurso c2 = DataCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", Principiante, false, ingles, langMaster, C2, I2, P2, 1);
    /* C3 */ list<DataCurso> P3 = {c1};
    /* C3 */ list<DataInscripcion> I3 = {n2};
    /* C3 */ DataCurso c3 = DataCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", Intermedio, true, ingles, linguaPro, C3, I3, P3, 1);
    /* C4 */ list<DataCurso> P4 = {c1, c3};
    /* C4 */ list<DataInscripcion> I4 = {};
    /* C4 */ DataCurso c4 = DataCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", Avanzado, true, ingles, linguaPro, C4, I4, P4, 1);
    /* C5 */ list<DataCurso> P5 = {};
    /* C5 */ list<DataInscripcion> I5 = {n7, n8};
    /* C5 */ DataCurso c5 = DataCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", Intermedio, true, portugues, linguaPro, C5, I5, P5, 1);
    /* C6 */ list<DataCurso> P6 = {c5};
    /* C6 */ list<DataInscripcion> I6 = {};
    /* C6 */ DataCurso c6 = DataCurso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", Avanzado, false, portugues, lingoSensei, C6, I6, P6, 0);
    /* Cursos y previas */


    /* Cursos */
    /* C1 */ cc->nuevoCurso(c1);
    /* C2 */ cc->nuevoCurso(c2);
    /* C3 */ cc->nuevoCurso(c3);
    /* C4 */ cc->nuevoCurso(c4);
    /* C5 */ cc->nuevoCurso(c5);
    /* C6 */ cc->nuevoCurso(c6);
    /* Cursos */
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

    string nombre;
    cout << "Ingrese su nombre: " << endl;
    getline(cin, nombre);

    string desc;
    cout << "Ingrese una descripcion: " <<endl;
    getline(cin, desc);

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
            
            int espec;
            do
            {
                cout << "Idiomas: " << endl;
                imprimirListaDataIdiomas(listaIdiomas);
                cout << "0. Dejar de ingresar idiomas." << endl; 
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
                    listaIdiomas.erase(it);
                    cout << "Idioma agregado." << endl;
                }
            } while (espec != 0 && listaIdiomas.size()>0);
        }
        else{
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (tipo != "1" && tipo != "2");
    cu->confirmarAltaUsuario(stoi(tipo));
    cout << "--Usuario creado exitosamente--" << endl << endl;
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
    cout << "--Idioma creado exitosamente--" << endl << endl;
}

void consultarIdiomas(){
    Factory * factory = Factory::getInstance();
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataIdioma> listaIdiomas = ci->listarIdiomas();
    imprimirListaDataIdiomas(listaIdiomas);
} 

void altaCurso(){
    Factory * factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();

    //Selecciona el profesor que dictara el curso
    IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
    list<DataProfesor> profesores = cUsers->obtenerProfesores();
    if(profesores.size() == 0){
        throw ExNoHayProfesor();
    }
    imprimirListaDataProfesores(profesores);
    int profe;
    do {
            cout << "Seleccione el profesor que dictara el curso ingresando el numero: " << endl;
            cin >> profe;
            if (profe <= 0 || profe > profesores.size())
            {
                cout << "Numero de profesor invalido. Intente nuevamente." << endl;
            }
            
        } while (profe <= 0 || profe > profesores.size());
    auto it = profesores.begin();
    advance(it, profe - 1);
    cc->elegirProfesor(it->getNick());

    //Selecciona el idioma del curso a partir del profesor seleccionado
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataIdioma> idprof = cc->listarIdiomasProfesor();
    if(idprof.size() == 0){
        throw ExProfesorSinIdiomas();
    }
    imprimirListaDataIdiomas(idprof);
    int idioma;
    do
        {
            cout << "Seleccione el idioma del curso ingresando el numero: " << endl;
            cin >> idioma;
            if (idioma <= 0 || idioma > idprof.size())
            {
                cout << "Numero de idioma invalido. Intente nuevamente." << endl;
            }
            
        } while (idioma <= 0 || idioma > idprof.size());
    auto it2 = idprof.begin();
    advance(it2, idioma - 1);
    cc->elegirIdiomaProfesor(*it2);

    //Se crea el curso
    string nombreCurso;
    cout << "Ingrese el nombre del curso: " << endl;
    cin.ignore();
    getline(cin, nombreCurso);

    string descripcionCurso;
    cout << "Ingrese la descripcion del curso: " << endl;
    getline(cin,descripcionCurso);

    int dificultadCurso;
    dif dc;
    do
        {
            cout << "Seleccione la dificultad del curso: " << endl << "0. Principiante" << endl << "1. Intermedio" << endl << "2. Avanzado" << endl;
            cin >> dificultadCurso;
            switch(dificultadCurso){
                case 0:
                    dc = Principiante;
                    break;
                case 1:
                    dc = Intermedio;
                    break;
                case 2:
                    dc = Avanzado;
                    break;
                default:
                    cout << "Numero de dificultad invalido. Intente nuevamente." << endl;
                    break;
            }
            
        } while (dificultadCurso < 0 || dificultadCurso > 2);
    cc->crearCurso(nombreCurso, descripcionCurso, dc);

    //Selecciona las Previas que contendrá el curso (puede contener o no)
    
    int seleccionador;
    do
        {
            cout << "Si desea agregar previas al curso ingrese 1, si no desea hacerlo, ingrese 0." << endl;
            cin.ignore();
            cin >> seleccionador;
            if (seleccionador < 0 || seleccionador > 1)
            {
                cout << "Accion Incorrecta. Intente nuevamente." << endl;
            }
            
        } while (seleccionador < 0 || seleccionador > 1);

    if (seleccionador == 1){
        //Agregar previas
        list<DataCurso> cursos = cc->listarCursosHab();
        if(cursos.size() == 0){
            cout << "No hay cursos habilitados todavia. " << endl;
        }else{
            imprimirListaCursos(cursos);
            int curso;

            //Bucle para agregar tantas previas como quiera
            do
            {
                do
                {
                    cout << "Seleccione el curso ingresando el numero o 0 para detenerse: " << endl;
                    cin >> curso;
                    if (curso < 0 || curso > cursos.size())
                    {
                        cout << "Numero de curso invalido. Intente nuevamente." << endl;
                    }
                } while (curso < 0 || curso > cursos.size());
                if(curso != 0){
                    //Agrega la previa seleccionada
                    auto it3 = cursos.begin();
                    advance(it3, curso - 1);
                    cc->agregarPrevia(it3->getNomCurso());
                }
            } while (curso != 0);
        }
    }


    //Agregar Lecciones y Ejercicios al Curso (puede no agregar)
    do
        {
            cout << "Si desea agregar lecciones al curso ingrese 1, si no desea hacerlo, ingrese 0." << endl;
            cin.ignore();
            cin >> seleccionador;
            if (seleccionador != 0 && seleccionador != 1)
            {
                cout << "Accion incorrecta. Intente nuevamente." << endl;
            }
            
        } while (seleccionador != 0 && seleccionador != 1);
    if (seleccionador == 1){
        do
        {
            //Agregar lecciones
            cout << "Ingrese el tema del que tratara la leccion: " << endl;
            string tema;
            cin.ignore();
            getline(cin, tema);
            cout << "Ingrese el objetivo de la leccion: " << endl;
            string obj;
            getline(cin, obj);
            cc->agregarLeccionCN(tema, obj);
            cout << "Leccion añadida." << endl;
            do
            {
                cout << "Si desea agregar ejercicios a la leccion ingrese 1, si no desea hacerlo, ingrese 0." << endl;
                cin >> seleccionador;
                if (seleccionador != 0 && seleccionador != 1)
                {
                    cout << "Accion incorrecta. Intente nuevamente." << endl;
                }
            } while (seleccionador != 0 && seleccionador != 1);

            if(seleccionador == 1){
                do{
                    do
                    {
                        cout << "Si desea agregar un ejercicio de tipo completar ingrese 1, si desea agregar uno de tipo traducir, ingrese 2. Si desea detenerse ingrese 0." << endl;
                        cin >> seleccionador;
                        if (seleccionador < 0 || seleccionador > 2)
                        {
                            cout << "Accion incorrecta. Intente nuevamente." << endl;
                        }
                    } while (seleccionador < 0 || seleccionador > 2);
                    //Agregar ejercicios
                    if(seleccionador != 0){
                        cout << "Ingrese la descripcion del ejercicio: " << endl;
                        string desc;
                        cin.ignore();
                        getline(cin, desc);
                        if(seleccionador == 1){
                            cout << "Ingrese la frase a completar con '-' donde va una palabra: " << endl;
                            string fraseC;
                            getline(cin, fraseC);
                            cout << "Ingrese el conjunto de palabras solucion separadas por un espacio: " << endl;
                            string solS;
                            getline(cin, solS);
                            vector<string> solC = convertirAVector(solS);
                            cc->agregarEjercicio(desc, fraseC, solC);
                        }else{
                            cout << "Ingrese la frase a traducir: " << endl;
                            string fraseT;
                            getline(cin, fraseT);
                            cout << "Ingrese la solucion: " << endl;
                            string solT;
                            getline(cin, solT);
                            cc->agregarEjercicio(desc, fraseT, solT);
                        }
                    }
                }while(seleccionador != 0);
            }
            do
            {
                cout << "Si desea agregar otra leccion, ingrese 1. Si no, ingrese 0." << endl;
                cin.ignore();
                cin >> seleccionador;
                if (seleccionador != 0 && seleccionador != 1)
                {
                    cout << "Accion incorrecta. Intente nuevamente." << endl;
                }
            } while (seleccionador != 0 && seleccionador != 1);
        }while(seleccionador != 0);
    }
    cc->finalizarAltaCurso();
    cout << "--Curso creado exitosamente--" << endl << endl;
}

void agregarLeccion(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    list<DataCurso> cursos = cc->listarCursosNA();
    imprimirListaCursos(cursos);
    int course;
        do
        {
            cout << "Seleccione el curso al que desea agregar leccion ingresando el numero: " << endl;
            cin >> course;
            if (course <= 0 || course > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente" << endl; 
            }
        } while (course <= 0 || course > cursos.size());
    auto it = cursos.begin();
    advance(it, course - 1); 
    string nomTema, obj;
    cout << "Ingrese el nombre del tema de la leccion: " << endl;
    cin.ignore();
    getline(cin, nomTema);
    cout << "Ingrese el objetivo de la leccion: " << endl;
    getline(cin, obj);

    cc->insLeccion(it->getNomCurso(), nomTema , obj);
    
   int num=420;
   do { cout << endl;
        if (num==420){ cout << "Opcionalmente puede agregar ejercicios a la nueva leccion: " << endl;} //todo por el disenio
        else {cout << "Puede agregar otro ejercicio a la nueva leccion: " << endl;}
        do{
            cout << "1. Agregar Traduccion." << endl;
            cout << "2. Agregar Completar Palabra." << endl;
            cout << "3. No agregar ejercicio." << endl;
            cout << endl;
            cin >> num;
            if (num <= 0 || num > 3)
            {
                cout << "Accion incorrecta. Intente nuevamente." << endl;
            }
        }while(num <= 0 || num > 3);
        
        if (num == 1){
            string descT,fraseT,solT;
            cout << "Ingrese la descripcion del ejercicio: " << endl;
            cin.ignore();
            getline(cin,descT);
            cout << "Ingrese la frase a traducir: " << endl;
            getline(cin,fraseT);
            cout << "Ingrese la solucion de la traduccion: " << endl;
            getline(cin,solT);
            cout << endl;

            cc->agregarEjercicio(descT, fraseT, solT); //lec deberia ser la ultima leccion. entonces creo que esta bien UwU
            cout << "--Ejercicio agregado exitosamente--" << endl;
        }
        else if (num == 2){
            string descC,fraseC,solCString;
            cout << "Ingrese la descripcion del ejercicio: " << endl;
            cin.ignore();
            getline(cin,descC);
            cout << "Ingrese la frase a completar: " << endl;
            getline(cin,fraseC);
            cout << "Ingrese la solucion de las palabras faltantes con espacios de esta forma: " << endl;
            cout << "Palabra1 palabra2 palabra3" << endl;
            getline(cin,solCString);
            vector<string> solC = convertirAVector(solCString); 
                                          
            cc->agregarEjercicio(descC, fraseC, solC);
            cout << "--Ejercicio agregado exitosamente--" << endl;
        }
    }while (num!=3);

cc->finalizarAgLec();
cout << "--Leccion agregada exitosamente--" << endl << endl;
}

void agregarEjercicio(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    list<DataCurso> cursos = cc->listarCursosNA();
    imprimirListaCursos(cursos);
    int course;
        do
        {
            cout << "Seleccione el curso deseado ingresando el numero: " << endl;
            cin >> course;
            if (course <= 0 || course > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente" << endl; 
            }
        } while (course <= 0 || course > cursos.size());
    auto itC = cursos.begin();
    advance(itC, course - 1); 

    cc->seleccionarCurso(itC->getNomCurso());
    vector<DataLeccion> lex = cc->listarLecciones();

    imprimirListaLeccion(lex);//esta es nueva. si, es con vectores, no con listas como las otras :o
    int numLec;
        do
        {
            cout << "Seleccione la leccion deseada ingresando el numero: " << endl;
            cin >> numLec;
            if (numLec <= 0 || numLec > lex.size())
            {
                cout << "Numero de leccion invalido. Intente nuevamente" << endl; 
            }
        } while (numLec <= 0 || numLec > lex.size());
    cc->seleccionarLeccion(lex[numLec-1]);

    int num;
    do{
        cout << "Selecciona el tipo de ejercicio para agregar: " << endl;
        cout << "1. Agregar Traduccion." << endl;
        cout << "2. Agregar Completar Palabra." << endl;
        cin >> num;
        if (num == 1){
            string descT,fraseT,solT;
            cout << "Ingrese la descripcion del ejercicio: " << endl;
            cin.ignore();
            getline(cin,descT);
            cout << "Ingrese la frase a traducir: " << endl;
            getline(cin,fraseT);
            cout << "Ingrese la solucion de la traduccion: " << endl;
            getline(cin,solT);
            cout << endl;

            cc->agregarEjercicio(descT, fraseT, solT);
        }
        else if (num == 2){
            string descC,fraseC,solCString;
            cout << "Ingrese la descripcion del ejercicio: " << endl;
            cin.ignore();
            getline(cin,descC);
            cout << "Ingrese la frase a completar: " << endl;
            getline(cin,fraseC);
            cout << "Ingrese la solucion de las palabras faltantes con espacios de esta forma: " << endl;
            cout << "Palabra1 palabra2 palabra3" << endl;
            getline(cin, solCString);
            vector<string> solC = convertirAVector(solCString); 
                                          
            cc->agregarEjercicio(descC, fraseC, solC);
        }
        else  {cout << "Opcion invalida. Intente nuevamente" << endl; }
        }while (num != 1 && num != 2);

    cc->darAltaEjercicio();
    cout << "--Ejercicio agregado exitosamente--" << endl << endl;
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
            if (course <= 0 || course > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente" << endl; 
            }
        } while (course <= 0 || course > cursos.size());
    auto it = cursos.begin();
    advance(it, course - 1);    
    if (cc->esCursoHabilitable((*it).getNomCurso())){
        cc->habilitarCurso((*it).getNomCurso());
        cout << "--Curso habilitado exitosamente--" << endl;    
    }else{
        cout << "Curso no habilitable." << endl << endl;
    }
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
        if (course <= 0 || course > cursos.size())
        {
            cout << "Numero de curso invalido. Intente nuevamente" << endl; 
        }
    } while (course <= 0 || course > cursos.size());
    auto it = cursos.begin();
    advance(it, course - 1);
    cc->eliminarCurso(it->getNomCurso());
    cout << "--Curso eliminado exitosamente--" << endl << endl;
}

void consultarCurso(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    list<DataCurso> cursos = cc->listarCursos();
    if(cursos.size() == 0){
        cout << "No hay cursos en el sistema." << endl;
    }else{
        imprimirListaCursos(cursos);
        int curso;
        do
        {
            cout << "Seleccione el curso ingresando el numero: " << endl;
            cin >> curso;
            if (curso <= 0 || curso > cursos.size())
            {
                cout << "Numero de curso invalido. Intente nuevamente." << endl;
            }
            
        } while (curso <= 0 || curso > cursos.size());
        auto iter = cursos.begin();
        advance(iter, curso - 1);
        cout << *iter << endl; 
    }
}

void inscribirseACurso(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    list<DataEstudiante> estudiantes = cu->obtenerEstudiantes();
    if(estudiantes.size() == 0){
        throw ExNoExistenEstudiantes();
    }
    imprimirListaDataEstudiantes(estudiantes);
    int estud;
    do
    {
        cout << "Seleccione el estudiante ingresando el numero: " << endl;
        cin >> estud;
        if (estud <= 0 || estud > estudiantes.size())
        {
            cout << "Numero de estudiante invalido. Intente nuevamente." << endl;
        }
        
    } while (estud <= 0 || estud > estudiantes.size());
    auto iterador = estudiantes.begin();
    advance(iterador, estud - 1);
    cc->seleccionarEstudiante(iterador->getNick());
    list<DataCurso> disponibles = cc->listarCursosDisponibles();
    if(disponibles.size() == 0){
        throw ExNoHayCursosDisponibles();
    }
    int num = 1;
    for (auto it = disponibles.begin(); it != disponibles.end(); it++){
        cout << num << ". " << "Nombre: " << it->getNomCurso() 
            << endl << "Descripcion: " << it->getDesc()
            << endl << "Idioma: " << (*it).getIdi().getNombre() 
            << endl << "Profesor: " << it->getProfe()
            << endl << "Dificultad: " << it->enumToString()
            << endl << "Cantidad de Lecciones: " << it->getLecciones().size()
            << endl << "Cantidad de Ejercicios: " << it->getCantEjercicios() << endl << endl;
        num++;
    }
    int curso;
    do
    {
        cout << "Seleccione el curso ingresando el numero: " << endl;
        cin >> curso;
        if (curso <= 0 || curso > disponibles.size())
        {
            cout << "Numero de curso invalido. Intente nuevamente." << endl;
        }
        
    } while (curso <= 0 || curso > disponibles.size());
    auto iter = disponibles.begin();
    advance(iter, curso - 1);
    cc->seleccionarCurso(iter->getNomCurso());
    cc->finalizarInscripcion();
    cout << "--Inscripcion realizada exitosamente--" << endl << endl;
}

void realizarEjercicio(){
    Factory* factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();
    IControladorUsuarios* cu = factory->getIControladorUsuarios();
    list<DataEstudiante> estudiantes = cu->obtenerEstudiantes();
    if(estudiantes.size() == 0){
        throw ExNoHayEstudiante();
    }
    imprimirListaDataEstudiantes(estudiantes);
    int estud;
    do
    {
        cout << "Seleccione el estudiante ingresando el numero: " << endl;
        cin >> estud;
        if (estud <= 0 || estud > estudiantes.size())
        {
            cout << "Numero de estudiante invalido. Intente nuevamente." << endl;
        }
        
    } while (estud <= 0 || estud > estudiantes.size());
    auto iterador = estudiantes.begin();
    advance(iterador, estud - 1);
    cc->seleccionarEstudiante(iterador->getNick());
    list<DataCurso> cursos = cc->obtenerCursosNoAprobadosEstudiante();
    if(cursos.size() == 0){
        throw ExNoCursosEnCurso();
    }
    imprimirListaCursos(cursos);
    int cur;
    do
    {
        cout << "Seleccione el curso ingresando el numero: " << endl;
        cin >> cur;
        if (cur < 0 || cur >= cursos.size())
        {
            cout << "Numero de curso invalido. Intente nuevamente." << endl;
        }
        
    } while (cur < 0 || cur >= cursos.size());
    auto iter = cursos.begin();
    advance(iter, cur - 1);
    cc->seleccionarCurso(iter->getNomCurso());
    list<DataEjercicio> ejercicios = cc->listarEjerciciosNoAprobados();
    int ej;
    do
    {
        cout << "Seleccione el ejercicio ingresando el numero: " << endl;
        cin >> ej;
        if (ej < 0 || ej >= ejercicios.size())
        {
            cout << "Numero de ejercicio invalido. Intente nuevamente." << endl;
        }
        
    } while (ej < 0 || ej >= ejercicios.size());
    auto otroiter = ejercicios.begin();
    advance(otroiter, ej - 1);
    cc->seleccionarEjercicio(*otroiter);
    string letra = cc->enunciarEjercicio();
    cout << letra << endl;
    if(cc->getTipoEjercicio()){
        cout << (*otroiter).getFraseC() << endl;
        cout << "Ingrese las palabras faltantes separadas por un espacio: " << endl;
        string s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        cc->ingresarSolEjercicio(convertirAVector(s));
        
    }else{
        cout << (*otroiter).getFraseT() << endl;
        cout << "Ingrese la frase traducida: " << endl;
        string s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        cc->ingresarSolEjercicio(s);
    }
    cc->comprobarSolucionEjercicio();
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
        cin >> tipoEstad;
        if (tipoEstad < 0 || tipoEstad > 3)
        {
            cout << "Numero de estadistica invalida. Intente nuevamente" << endl;
        }
    } while (tipoEstad < 0 || tipoEstad > 3);

    if (tipoEstad == 1)
    {
        IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
        list<DataEstudiante> estudiantes = cUsers->obtenerEstudiantes();
        if (estudiantes.size() == 0)
        {
            throw ExNoHayEstudiante();
        }
        
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
        list<DataAvance> avances = dataEstadEstud.getAvances();
        if (avances.size() == 0)
        {
            throw ExNoEstaInscripto();
        }
        cout << "Estadisticas de: " << it->getNick() << endl;
        for (auto iter = avances.begin(); iter != avances.end(); iter++)
        {
            cout << "Curso: " << iter->getCurso() << endl; 
            cout << "Avance: " << iter->getAvance() << "%" << endl;
        }
    }
    else if (tipoEstad == 2)
    {
        IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
        list<DataProfesor> profesores = cUsers->obtenerProfesores();
        if (profesores.size() == 0)
        {
            throw ExNoHayProfesor();
        }
        
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
        list<DataAvance> avances = dataEstadProfe.getAvances();
        if (avances.size() == 0)
        {
            throw ExNoHaPropuestoCursos();
        }
        
        cout << "Estadisticas de: " << it->getNick() << endl;
        for (auto iter = avances.begin(); iter != avances.end(); iter++)
        {
            cout << "Curso: " << iter->getCurso() << endl;
            cout << "Avance: " << iter->getAvance() << "%" << endl;
        }
    }
    else if (tipoEstad == 3)
    {
        IControladorCursos* cc = factory->getIControladorCursos();
        list<DataCurso> cursos = cc->listarCursosHab();
        if (cursos.size() == 0)
        {
            throw ExNoExistenCursos();
        }
        
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
    // if (idiomasDisp.size() == 0)
    // {
    //     cout << "No hay suscripciones disponibles" << endl;
    // }
    int susc;
    do
    {
        cout << "Idiomas disponibles: " << endl;
        imprimirListaDataIdiomas(idiomasDisp);
        cout << "0. Dejar de ingresar idiomas." << endl;    
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
            idiomasDisp.erase(sus);
            cout << "--Suscripción añadida--" << endl;
        }
    } while (susc !=0 && idiomasDisp.size()>0);
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
    
    int susc;
    do
    {
        cout << "Tus suscripciones: " << endl;
        imprimirListaDataIdiomas(suscripcionesActuales);
        cout << "0. Dejar de ingresar idiomas." << endl;
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
            suscripcionesActuales.erase(sus);
            cout << "--Suscripcion removida exitosamente--" << endl << endl;
        }
    } while (susc !=0 && suscripcionesActuales.size()>0);
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
        esperarEnter();
            break;
        case 2:
            // Consulta de usuario
            consultarUsuario();
            esperarEnter();
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
            esperarEnter();
            break;
        case 4:
            // Consultar idiomas
            consultarIdiomas();
            esperarEnter();
            break;
        case 5:
        // Alta de curso
            try
		    {
                altaCurso();
		    }catch (const ExNoHayProfesor& ex){
		    	cout << "Error: " << ex.what() << endl;
		    }catch (const ExProfesorSinIdiomas& ex){
		    	cout << "Error: " << ex.what() << endl;
		    }
            esperarEnter();        
            break;
        case 6:
            // Agregar lección
            agregarLeccion();
            esperarEnter();
            break;
        case 7:
            // Agregar ejercicio
            agregarEjercicio();
            esperarEnter();
            break;
        case 8:
            // Habilitar curso
            habilitarCurso();
            esperarEnter();
            break;
        case 9:
            // Eliminar curso
            eliminarCurso();
            esperarEnter();
            break;
        case 10:
            // Consultar curso
            consultarCurso();
            esperarEnter();
            break;
        case 11:
            // Inscribirse a curso
            try{
                inscribirseACurso();
            }catch(const ExNoExistenEstudiantes& ex){
		    	cout << "Error: " << ex.what() << endl;
		    }catch(const ExNoHayCursosDisponibles& ex){
		    	cout << "Error: " << ex.what() << endl;
		    }
            esperarEnter();
            break;
        case 12:
            // Realizar ejercicio
            try
            {
            realizarEjercicio();
            }
            catch (const ExNoHayEstudiante& ex){
                cout << "Error: " << ex.what() << endl;
            }catch (const ExNoCursosEnCurso& ex){
                cout << "Error: " << ex.what() << endl;
            }
            esperarEnter();
            break;
        case 13:
            // Consultar estadísticas
            try
            {
            consultarEstadisticas();
            }
            catch (const ExNoHayEstudiante& ex){
                cout << "Error: " << ex.what() << endl;
            }
            catch (const ExNoHayProfesor& ex ){
                cout << "Error: " << ex.what() << endl;
            }
            catch (const ExNoEstaInscripto& ex){
                cout << ex.what() << endl;
            }
            catch (const ExNoHaPropuestoCursos& ex){
                cout << ex.what() << endl; 
            }
            catch (const ExNoExistenCursos& ex){
                cout << ex.what() << endl;
            }
            esperarEnter();
            break;
        case 14:
            // Suscribirse a notificaciones
            suscribirseANotificaciones();
            esperarEnter();
            break;
        case 15:
            // Consulta de notificaciones
            consultarNotificaciones();
            esperarEnter();
            break;
        case 16:
            // Eliminar suscripciones
            eliminarSuscripciones();
            esperarEnter();
            break;
        case 17:
            // Opción para cargar los datos de prueba
            cargarDatosPrueba();
            esperarEnter();
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
    cout << "6. Agregar leccion" << endl;
    cout << "7. Agregar ejercicio" << endl;
    cout << "8. Habilitar curso" << endl;
    cout << "9. Eliminar curso" << endl;
    cout << "10. Consultar curso" << endl;
    cout << "11. Inscribirse a curso" << endl;
    cout << "12. Realizar ejercicio" << endl;
    cout << "13. Consultar estadisticas" << endl;
    cout << "14. Suscribirse a notificaciones" << endl;
    cout << "15. Consulta de notificaciones" << endl;
    cout << "16. Eliminar suscripciones" << endl;
    cout << "17. Cargar datos de prueba" << endl;
    cout << "18. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cout << endl;
    return opcion;
}

int main() {
    int opcion;
    cargarDatosPrueba();
    do {
        opcion = mostrarMenu();
        realizarAccion(opcion);
        cout << endl;
    } while (opcion != 18);

    return 0;
}
