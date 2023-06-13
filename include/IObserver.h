#ifndef _CLASSIOBSERVER_H_
#define _CLASSIOBSERVER_H_

#include <iostream>
#include <string>
#include "notificacion.h"

using namespace std;

class IObserver{
    public:
            virtual void Notificar(Notificacion*) = 0;
            virtual void eliminarNotificacion(string) = 0;
            virtual void eliminarNotificaciones() = 0;
            virtual ~IObserver() = 0;
};

#endif