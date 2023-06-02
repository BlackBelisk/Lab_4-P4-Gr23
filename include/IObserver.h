#ifndef _CLASSIOBSERVER_H_
#define _CLASSIOBSERVER_H_

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class IObserver{
    public:
            virtual void notificar() = 0;
};

#endif