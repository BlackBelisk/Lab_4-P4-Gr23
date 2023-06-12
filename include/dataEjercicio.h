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
            string toString();//Pendiente      

            //Traducir
            string getFraseT()const;
            string getSolT()const; 

            //Completar
            string getFraseC()const;
            vector<string> getSolC()const;
            string solToString();
};
/*
class DataCompletar: public DataEjercicio{
    private:
            vector<string> solucion;
		    string fraseComp;
    public:
            string getFrase()const;
            vector<string> getSol()const;
            DataCompletar(string, string, vector<string>);
            string solToString();
            string toString();
};

class DataTraducir: public DataEjercicio{
    private:
            string solucion;
		    string fraseTrad;
    public:        
            string getFrase()const;
            string getSol()const;
            DataTraducir(string, string, string);
            string toString();
};*/
#endif