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
