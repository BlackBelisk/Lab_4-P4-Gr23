#ifndef _CLASSIOBSERVER_H_
#define _CLASSIOBSERVER_H_

#include <iostream>
#include <string>

using namespace std;

class IObserver{
    public:
            virtual void Notificar(Notificacion*, Idioma* idi) = 0;
            virtual void eliminarNotificacion(string) = 0;
            virtual ~IObserver() = 0;
};

#endif