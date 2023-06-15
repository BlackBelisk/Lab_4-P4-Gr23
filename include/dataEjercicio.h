#ifndef _CLASSDATAEJERCICIO_H_
#define _CLASSDATAEJERCICIO_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class DataEjercicio{
    private:
            string desc;
            string fraseComp;
            vector<string> solComp;
            string fraseTrad;
            string solTrad;
            bool tipo;
    public:
            DataEjercicio(string, string, string);
            DataEjercicio(string, string, vector<string>);
            string getDesc() const;
            bool getTipo()const; 
            string toString();
            string mostrarEj();    

            //Traducir
            string getFraseT()const;
            string getSolT()const; 

            //Completar
            string getFraseC()const;
            vector<string> getSolC()const;
            string solToString();

            bool operator==(const DataEjercicio &de);
};

#endif