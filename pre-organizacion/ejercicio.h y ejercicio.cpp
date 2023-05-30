// .h para Ejercicio con sus subClases

#include <string>
#include <vector>
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


// .cpp para Ejercicio con sus subClases

//Metodos de Ejercicios

Ejercicio::Ejercicio(string descr) {
	this->descripcion = descr;
}

Ejercicio::~Ejercicio(){}

string Ejercicio::getDescripcion() {
	return descripcion;
}

void Ejercicio::setDescripcion(string descr) {
	this->descripcion = descr;
}



//Metodos de Traduccion

Traduccion::Traduccion(string descr, string sol):Ejercicio(descr){
	this->solucion = sol;
}
Traduccion::~Traduccion(){}
string Traduccion::getSolucion(){
	return this->solucion;
}
void Traduccion::setSolucion(string sol){
	this->solucion = sol;
}
string Traduccion::getFraseTrad(){
	return this->fraseTrad;
}
void Traduccion::setFraseTrad(string frase){
	this->fraseTrad = frase;
}
bool Traduccion::esEjercicioCorrecto() {
	return (this->solucion == this->fraseTrad);
}



//Metodos de CompletarPalabra
CompletarPalabra::CompletarPalabra(string descr, set<string> setSol):Ejercicio(descr){
	this->solucion = setSol;
}
CompletarPalabra::~CompletarPalabra(){}
set<string> CompletarPalabra::getSolucion() {
	return this->solucion;
}
void CompletarPalabra::setSolucion(set<string> setSol) {
	this->solucion = setSol;
}
set<string> CompletarPalabra::getFrases() {
	return this->frases;
}
//PreCondicion: la variable setFrases contiene la misma cantidad de elementos que el setSolucion
void CompletarPalabra::setFrases(set<string> setFrases) {
	this->frases = setFrases;
}
//PreCondicion: Solucion y Frases tienen la misma cantidad de elementos
bool CompletarPalabra::esEjercicioCorrecto() {

	/*bool sonIguales = false;
	set<string>::iterator i = frases.begin();
	set<string>::iterator s = solucion.begin();
	for(i = solucion.begin(); i != solucion.end(); ++i){
		sonIguales = (i == s);
		++s;
	}*/
	return (solucion==frases);

}


int main(){
	set<string> palabras;
	palabras.insert("hello");
	palabras.insert("you");
	palabras.insert("me");
	CompletarPalabra *c = new CompletarPalabra("Descripcion de Prueba", palabras);
	cout << "Introduzca la traduccion de las siguientes palabras 'Hola', 'Tu' y 'Yo'" << "\n";
	set<string> respuestas;
	string frase;
	for(int i = 0; i <= (c->getSolucion()).size(); ++i) {
		cin >> frase;
		respuestas.insert(frase);
	}
	c->setSolucion(respuestas);
	if (c->esEjercicioCorrecto()) {
		cout << "La solucion es correcta" << "\n";
	}
	else {
		cout << "La solucion es incorrecta" << "\n";
	}
	delete c;

	Traduccion *t = new Traduccion("Descripcion", "Hello");
	cout << t->getDescripcion() <<"Introduzca la traduccion de la siguiente palabra 'Hola'";
	string respuesta;
	cin >> respuesta;
	t->setFraseTrad(respuesta);
	if (t->esEjercicioCorrecto()) {
		cout << "\n" << "La solucion es correcta" << "\n";
	}
	else {
		cout << "\n" << "La solucion es incorrecta" << "\n";
	}

	delete t;
	system("pause");
	return 0;
} 
