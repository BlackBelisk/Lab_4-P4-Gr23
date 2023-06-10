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

#endif