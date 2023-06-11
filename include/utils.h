#include <vector>
#include <list>
#include <sstream>
#include <string>
#include "dataIdioma.h"
using namespace std;

vector<string> convertirAVector(string);

void imprimirListaDataIdiomas(list<DataIdioma> idiomas){
    int num = 1;
    for (auto it = idiomas.begin(); it != idiomas.end(); it++)
    {
        cout << num << ". " << it->getNombre() << "." << endl;
        num++;
    }   
}