// .h para Ejercicio con sus subClases

#ifndef _CLASSEJERCICIO_H_
#define _CLASSEJERCICIO_H_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include "dataEjercicio.h"
using namespace std;



class Ejercicio {
    protected:
		string descripcion;

		//Constructor de objeto por parametros, al ser una clase abstracta, solo es utilizado para simplificar
		Ejercicio(string);
    public:
		//Destructor de Objeto
		virtual ~Ejercicio();

		//Retorna la descripcion del ejercicio
		virtual string getDescripcion();

		//Modifica la Descripcion del ejercicio
		virtual void setDescripcion(string);

		//Funcion esEjercicioCorrecto virtual pura, cada clase hija (Libro y JuegoMesa) tendra una implementacion distinta
		
		virtual DataEjercicio ejToData();

		//virtual vector<string> getSolucionComp() = 0;
		virtual string toString() = 0;
};


class Traduccion : public Ejercicio {
    private:
		string solucion;
		string fraseTrad;
	public:
		//Constructor y Destructor de Clase
		Traduccion(string, string, string);
		~Traduccion();
		
		//Setters y Getters
		void setSolucion(string);
		void setFraseTrad(string);
		string getSolucion();
		string getFraseTrad();

		//Funcion esEjericicioCorrecto para la subClase Traduccion
		virtual bool esEjercicioCorrecto(string respuesta);
		

		string toString();
		DataEjercicio ejToData();


};


class CompletarPalabra : public Ejercicio {
    private:
		vector<string> solucion;
		string fraseAComp;
	public:
	    //Constructor y Destructor de Clase
		CompletarPalabra(string, string, vector<string>);
		~CompletarPalabra();

		//Setters y Getters
		void setSolucionComp(vector<string>);
		void setFraseAComp(string);
		vector<string> getSolucionComp();
		string getFraseAComp();

		//Funcion esEjericicioCorrecto para la subClase Traduccion
		virtual bool esEjercicioCorrecto(vector<string> respuesta);



		string toString();
		string solToString();
		DataEjercicio ejToData();

};

#include "dataEjercicio.h"
#endif
