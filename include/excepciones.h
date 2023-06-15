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
        return "El idioma ya se encuentra ingresado en el sistema.";
    }
};

class ExNoHayProfesor : public exception{
    public:
        ExNoHayProfesor() = default;

        const char* what() const noexcept override{
            return "No existe profesor ingresado en el sistema.";
        }
};

class ExProfesorSinIdiomas : public exception{
    public:
        ExProfesorSinIdiomas() = default;

        const char* what() const noexcept override{
            return "El profesor elegido no posee idiomas.";
        }
};

class ExNoExistenEstudiantes : public exception{
    public:
        ExNoExistenEstudiantes() = default;

        const char* what() const noexcept override{
            return "No existen estudiantes en el sistema.";
        }
};

class ExNoHayCursosDisponibles : public exception{
    public:
        ExNoHayCursosDisponibles() = default;

        const char* what() const noexcept override{
            return "El estudiante seleccionado no tiene cursos disponibles";
        }
};

#endif