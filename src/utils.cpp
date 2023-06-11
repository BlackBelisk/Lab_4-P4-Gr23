#include <vector>
#include <sstream>
#include <string>
#include "../include/utils.h"

using namespace std;


vector<string> convertirAVector(string s){
    vector<string> res;
    istringstream iss(s);
    string palabra;
    while (getline(iss, palabra, ' ')) {
        res.push_back(palabra);
    }
    return res;
}

void imprimirListaDataIdiomas(list<DataIdioma> idiomas){
    int num = 1;
    for (auto it = idiomas.begin(); it != idiomas.end(); it++)
    {
        cout << num << ". " << it->getNombre() << "." << endl;
        num++;
    }   
}

//Imprime unicamente el nickname
void imprimirListaDataUsuarios(list<DataUsuario> usuarios){
    int num = 1;
    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        cout << num << ". " << it->getNick() << "." << endl;
        num++;
    }   
}

void imprimirListaDataEstudiantes(list<DataEstudiante> estudiantes){
    int num = 1;
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++)
    {
        cout << num << ". " << it->getNick() << "." << endl;
        num++;
    } 
}

void imprimirListaDataEstudiantes(list<DataEstudiante> profesores){
    int num = 1;
    for (auto it = profesores.begin(); it != profesores.end(); it++)
    {
        cout << num << ". " << it->getNick() << "." << endl;
        num++;
    } 
}

void imprimirListaCursos(list<DataCurso> cursos){
    int num = 1;
    for (auto it = cursos.begin(); it != cursos.end(); it++)
    {
        cout << num << ". " << it->getNomCurso() << "." << endl;
        num++;
    } 
}