#ifndef _CLASSDATAEJERCICIO_H_
#define _CLASSDATAEJERCICIO_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class DataEjercicio{
    public:
            string desc;
            DataEjercicio(string, string, string);
            DataEjercicio(string, string, vector<string>);
            
};

class DataCompletar: public DataEjercicio{
    public:
            vector<string> solucion;
		    string fraseComp;

            DataCompletar(string, string, vector<string>);
};

class DataTraducir: public DataEjercicio{
    public:
            string solucion;
		    string fraseTrad;
            DataTraducir(string, string, string);
};
#endif