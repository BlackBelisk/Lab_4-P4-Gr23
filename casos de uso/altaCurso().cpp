void altaCurso(){
    Factory * factory = Factory::getInstance();
    IControladorCursos* cc = factory->getIControladorCursos();

    //Se crea el curso
    string nombreCurso;
    cout << "Ingrese el nombre del curso: " << endl;
    cin >> nombreCurso;

    string descripcionCurso;
    cout << "Ingrese la descripcion del curso: " << endl;
    cin >> nombreCurso;

    dif dificultadCurso;
    do
        {
            cout << "Seleccione la dificultad del curso: " << endl << "0. Principiante" << endl << "1. Intermedio" << endl << "2. Avanzado" << endl;
            cin >> dificultadCurso;
            if (dificultadCurso < 0 || dificultadCurso > 2)
            {
                cout << "Numero de dificultad invalido. Intente nuevamente." << endl;
            }
            
        } while (dificultadCurso < 0 || dificultadCurso > 2);
    
    //CREACION DEL CURSO
    cc->crearCurso(nombreCurso, descripcionCurso, dificultadCurso);


    //Selecciona el profesor que dictara el curso
    IControladorUsuarios* cUsers = factory->getIControladorUsuarios();
    list<DataProfesor> profesores = cUsers->obtenerProfesores();
    imprimirListaDataProfesores(profesores);
    int profe;
    do
        {
            cout << "Seleccione el profesor que dictara el curso ingresando el numero: " << endl;
            cin >> profe;
            if (profe < 0 || profe > profesores.size())
            {
                cout << "Numero de profesor invalido. Intente nuevamente." << endl;
            }
            
        } while (profe < 0 || profe > profesores.size());
    auto it = profesores.begin();
    advance(it, profe - 1);

    //AQUI MARCA PROFESOR
    cc->encontrarCurso(nombreCurso)->elegirProfesor(it->getNick());


    //Selecciona el idioma del curso a partir del profesor seleccionado
    IControladorIdiomas* ci = factory->getIControladorIdiomas();
    list<DataIdioma> idprof = profesor.listarIdiomasProfesor();
    imprimirListaDataIdiomas(idprof);
    int idioma;
    do
        {
            cout << "Seleccione el idioma del curso ingresando el numero: " << endl;
            cin >> idioma;
            if (idioma < 0 || idioma > idprof.size())
            {
                cout << "Numero de idioma invalido. Intente nuevamente." << endl;
            }
            
        } while (idioma < 0 || idioma > idprof.size());
    auto it2 = idprof.begin();
    advance(it2, idioma - 1);

    //AQUI MARCA IDIOMA
    cc->encontrarCurso(nombreCurso)->elegirIdiomaProfesor(it2->getNombre());


    //Selecciona las Previas que contiene el curso (puede contener o no)
    int seleccionador;
    do
        {
            cout << "Si el curso contiene previas presione 1, sino seleccione 0" << endl;
            cin >> seleccionador;
            if (seleccionador != 0 || seleccionador != 1)
            {
                cout << "Accion Incorrecta. Intente nuevamente." << endl;
            }
            
        } while (seleccionador != 0 || seleccionador != 1);

    if (seleccionador = 1){
        //Agregar previas
        list<DataCurso> cursos = cc->listarCursosHab();
        imprimirListaCursos(cursos);
        int curso;

        //Bucle para agregar tantas previas como quiera
        do
        {
            do
            {
                cout << "Seleccione el curso ingresando el numero: " << endl;
                cin >> curso;
                if (curso < 0 || curso > cursos.size())
                {
                    cout << "Numero de curso invalido. Intente nuevamente." << endl;
                }
            
            } while (curso < 0 || curso > cursos.size());

            //Agrega la previa seleccionada
            auto it3 = cursos.begin();
            advance(it3, curso - 1);

            //AQUI ADHIERE PREVIA
            cc->encontrarCurso(nombreCurso)->agregarPrevia(it3->getNomCurso());

            //Seguir agregando previas??
            do
            {
                cout << "Para seguir seleccionando previas presione 1, para dejar de seleccionar presione 0" << endl;
                cin >> seleccionador;
                if (seleccionador != 0 || seleccionador != 1)
                {
                    cout << "Accion Incorrecta. Intente nuevamente." << endl;
                    }
            
            } while (seleccionador != 0 || seleccionador != 1);
            
        } while (seleccionador != 0);
    }


    //Agregar Lecciones y Ejercicios al Curso (puede no agregar)

    do //Pregunta para agregar
    {
        cout << "Desea agregar lecciones para el nuevo curso? 1.Si o 0.No" << endl;
        cin >> seleccionador;
        if (seleccionador != 0 || seleccionador != 1)
        {
            cout << "Accion Incorrecta. Intente nuevamente." << endl;
        }
    } while (seleccionador != 0 || seleccionador != 1);

    if(seleccionador==1){
        
        do
        {
            //Agrega la leccion (Completar)
            string nomLec;
            cout << "Escriba el nombre de la nueva leccion: " << endl;
            cin >> nomLec;
            string descLec;
            cout << "Escriba la descripcion de la nueva leccion: " << endl;
            cin >> descLec;

            //AQUI AGREGA LECCION
            cc->encontrarCurso(nombreCurso)->agregarLeccionCN(nomLec, descLec);



            //Agregar Ejercicio a la Leccion
                        
            do //Pregunta para agregar
            {
                cout << "Desea agregar ejercicios para la nueva leccion creada? 1.Si o 0.No" << endl;
                cin >> seleccionador;
                if (seleccionador != 0 || seleccionador != 1)
                {
                    cout << "Accion Incorrecta. Intente nuevamente." << endl;
                }
            } while (seleccionador != 0 || seleccionador != 1);

            if(seleccionador==1){
                do
                {
                    //Crear y Agregar Ejercicio 
                    string descEjer;
                    cout << "Escriba la descripcion del ejercicio a continuacion: " << endl;
                    cin >> descEjer;
                    
                    int tipoEjer;
                    do //Pregunta para seleccionar tipo ejercicio
                    {
                        cout << "Seleccione el tipo de Ejercicio a crear: " << endl << "1. Traducir" << endl << "2. Completar" << endl;
                        cin >> tipoEjer;
                        if (tipoEjer != 0 || tipoEjer != 1)
                        {
                            cout << "Accion Incorrecta. Intente nuevamente." << endl;
                        }
                    } while (tipoEjer != 1 || tipoEjer != 2);
                    
                    if(tipoEjer == 1){ //EJERCICIO TRADUCIR
                        string fraseEjerTrad;
                        cout << "Escriba la frase del ejercicio a traducir: " << endl;
                        cin >> fraseEjerTrad;

                        string solTrad;
                        cout << "Escriba la solucion del ejercicio a traducir: " << endl;
                        cin >> solTrad;

                        //AQUI AGREGA
                        cc->encontrarCurso(nombreCurso)->agregarEjercicio(descEjer, fraseEjerTrad, solTrad); //lec deberia ser la ultima leccion agregada



                    }else{ //EJERCICIO COMPLETAR
                        string fraseEjerComp;
                        cout << "Escriba la frase del ejercicio a completar: " << endl;
                        cin >> fraseEjerComp;

                        vector<string> solComp;
                        string palComp;
                        do
                        {
                            cout << "Escriba la siguiente palabra solucion: " << endl;
                            cin >> palComp;
                            solComp.push_back(palComp);
                            do
                            {
                                cout << "Si desea agregar mas palabras al vector solucion presione 1, de lo contrario 0" << endl;
                                cin >> seleccionador;
                                if (seleccionador != 0 || seleccionador != 1)
                                {
                                    cout << "Accion Incorrecta. Intente nuevamente." << endl;
                                    }
                            } while (seleccionador != 0 || seleccionador != 1);

                        } while (seleccionador !=0);

                        //AQUI AGREGA
                        cc->encontrarCurso(nombreCurso)->agregarEjercicio(descEjer, fraseEjerComp, solComp); //lec deberia ser la ultima leccion agregada

                    }                    

                    
                    //Pregunta para Repetir Bucle de Agregado de Ejercicios
                    do
                    {
                        cout << "Desea agregar mas ejercicios a la leccion " << nomLec << " ? 1.Si o 0.No" << endl;
                        cin >> seleccionador;
                        if (seleccionador != 0 || seleccionador != 1)
                        {
                            cout << "Accion Incorrecta. Intente nuevamente." << endl;
                            }
                    } while (seleccionador != 0 || seleccionador != 1);


                } while (seleccionador != 0); //Sale del bucle al ingresar 0
            }



            //Pregunta para Repetir Bucle de Agregado de Lecciones
            do
            {
                cout << "Desea agregar mas lecciones para el nuevo curso? 1.Si o 0.No" << endl;
                cin >> seleccionador;
                if (seleccionador != 0 || seleccionador != 1)
                {
                    cout << "Accion Incorrecta. Intente nuevamente." << endl;
                }
            } while (seleccionador != 0 || seleccionador != 1);


        } while (seleccionador != 0); //Sale del bucle al ingresar 0

    }
    
    //Finaliza el Alta
    cc->encontrarCurso(nombreCurso)->finalizarAltaCurso();

}
