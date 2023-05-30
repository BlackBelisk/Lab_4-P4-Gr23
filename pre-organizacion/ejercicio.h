#ifndef _CLASSEJERCICIO_H_
#define _CLASSEJERCICIO_H_

#include <string>
#include <iostream>
#include <set>
#include <stdio.h>
#include <cstdlib>
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
		virtual string getDescripcion();\

		//Modifica la Descripcion del ejercicio
		virtual void setDescripcion(string);

		//Funcion esEjercicioCorrecto virtual pura, cada clase hija (Libro y JuegoMesa) tendra una implementacion distinta
		virtual bool esEjercicioCorrecto() = 0;
};


class Traduccion : public Ejercicio {
    private:
		string solucion;
		string fraseTrad;
	public:
		//Constructor y Destructor de Clase
		Traduccion(string, string);
		~Traduccion();
		
		//Setters y Getters
		void setSolucion(string);
		void setFraseTrad(string);
		string getSolucion();
		string getFraseTrad();

		//Funcion esEjericicioCorrecto para la subClase Traduccion
		virtual bool esEjercicioCorrecto();
};


class CompletarPalabra : public Ejercicio {
    private:
		set<string> solucion;
		set<string> frases;
	public:
	    //Constructor y Destructor de Clase
		CompletarPalabra(string, set<string>);
		~CompletarPalabra();

		//Setters y Getters
		void setSolucion(set<string>);
		void setFrases(set<string>);
		set<string> getSolucion();
		set<string> getFrases();

		//Funcion esEjericicioCorrecto para la subClase Traduccion
		virtual bool esEjercicioCorrecto();
 
};

#endif
