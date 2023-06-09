realizarEjercicio(Estudiante e){
    
//cursosNoAprobadosEstudiante no deberia de pasarle un estudiante como paramentro ????
//crear funcion listarEjNoAprovadosUltimaLeccion a partir del set ejesCompletados en inscripcion.h
//crear funcion en caso de que el estudiante al realizar el ejercicio complete y finalice el curso 

    //lista los cursos a los que esta inscripto el estudiante e y los imprime en pantalla
    list<DataCurso> cursos = cursosNoAprobadosEstudiante();
    for(int i=0; i < cursos.size(); ++i){
        cout >> i >> " - " >> cursos.getNombre(); 
    }

    //el usuario selecciona el numero del curso y se guarda la referencia a la inscripcion de dicho curso
    cin >> i;
    Inscripcion *ins = encontrarInscripcion(cursos[i].getNombre());

    //devuelve una lista con los ejercicios no aprovados de la leccion actual del curso y los imprime en pantalla
    list<DataEjercicio> ejesNoAprob = ins.listarEjNoAprovadosUltimaLeccion();
    for(int i=0; i < ejesNoAprob.size(); ++i){
        cout >> i >> " - " >> ejesNoAprob.getDescripcion(); 
    }

    //devuelve el dataEjercicio del ejercicio no completado seleccionado
    cin >> i;
    DataEjercicio ejer = ins.lecActual->ejsToData[i];

    //respuestas del estudiante
    vector<string> respuesta;

    if(ejer.esCorrectoEjercicio(respuesta)){
        ins.agregarCompletado(ejer);
        cout >> "Respuesta Correcta. Ejercicio Completado"
        if(ins.obtenerProgreso() == 100){
            //nueva funcion Curso Completado (Felicidades)
        }
    }
    else{
        cout >> "Respuesta Incorrecta." >> "\n" >> "Presione 1 para reintentar o 0 para salir" >> "\n";
        cin << i;
        if(i=1){
            realizarEjercicio(e);
        }
}   

}
