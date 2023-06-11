#ifndef EXCEPCION_H
#define EXCEPCION_H

#include <exception>
#include <string>
using namespace std;

class ExYaExisteUsuario : public exception {
public:
    ExYaExisteUsuario() = default;

    const char* what() const noexcept override {
        return "El nickname ingresado ya se encuentra en uso.";
    }
};

class ExYaExisteIdioma : public exception{
public:
    ExYaExisteIdioma() = default;

    const char* what() const noexcept override {
        return "El idoma ya se encuentra ingresado en el sistema.";
    }
};

#endif