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

class ExNoHayEstudiante : public exception{
    public:
        ExNoHayEstudiante() = default;

        const char* what() const noexcept override{
            return "No existen estudiantes ingresados en el sistema.";
        }
};

class ExNoEstaInscripto : public exception{
    public:
        ExNoEstaInscripto() = default;

        const char* what() const noexcept override{
            return "El estudiante seleccionado no se encuentra inscripto a ningún curso. ";
        }
};

class ExNoHayProfesor : public exception{
    public:
        ExNoHayProfesor() = default;

        const char* what() const noexcept override{
            return "No existen profesores ingresados en el sistema.";
        }
};

class ExProfesorSinIdiomas : public exception{
    public:
        ExProfesorSinIdiomas() = default;

        const char* what() const noexcept override{
            return "El profesor elegido no posee idiomas.";
        }
};

class ExNoHayCursosNoHabilitados : public exception{
    public:
        ExNoHayCursosNoHabilitados() = default;

        const char* what() const noexcept override{
            return "Actualmente no existen cursos no habilitados en el sistema.";
        }
};

class ExNoHayCursosDisponibles : public exception{
    public:
        ExNoHayCursosDisponibles() = default;

        const char* what() const noexcept override{
            return "El estudiante seleccionado no tiene cursos disponibles";
        }
};

class ExNoHaPropuestoCursos : public exception{
    public:
        ExNoHaPropuestoCursos() = default;

        const char* what() const noexcept override{
            return "El profesor seleccionado no ha propuesto/imparte algún curso";
        }
};

class ExNoExistenCursos : public exception{
     public:
        ExNoExistenCursos() = default;
        const char* what() const noexcept override{
            return "No existen cursos en el sistema.";
        }
};

class ExNoCursosEnCurso : public exception{
     public:
        ExNoCursosEnCurso() = default;
        const char* what() const noexcept override{
            return "El estudiante no tiene ningun curso en progreso.";
        }
};

class ExNoHayLeccionesEnCurso : public exception{
     public:
        ExNoHayLeccionesEnCurso() = default;
        const char* what() const noexcept override{
            return "El curso elegido no posee ninguna leccion.";
        }
};

class ExCursoEsPrevia : public exception{
     public:
        ExCursoEsPrevia() = default;
        const char* what() const noexcept override{
            return "Este curso es previa de otro(s) y por lo tanto no puede eliminarse.";
        }
};

class ExNoHayUsuarios : public exception{
     public:
        ExNoHayUsuarios() = default;
        const char* what() const noexcept override{
            return "No hay usuarios ingresados en el sistema.";
        }
};

class ExNoHayIdiomasDisponibles : public exception{
     public:
        ExNoHayIdiomasDisponibles() = default;
        const char* what() const noexcept override{
            return "No hay suscripciones disponibles.";
        }
};

class ExNoHayNotificaciones : public exception{
     public:
        ExNoHayNotificaciones() = default;
        const char* what() const noexcept override{
            return "No hay notificaciones pendientes.";
        }
};

class ExNoHaySuscripciones : public exception{
     public:
        ExNoHaySuscripciones() = default;
        const char* what() const noexcept override{
            return "Este usuario no esta suscrito a ningun idioma.";
        }
};

class ExNoHayIdiomas : public exception{
    public:
        ExNoHayIdiomas() = default;
        const char* what() const noexcept override{
            return "No hay idiomas ingresados en el sistema.";
        }
};
#endif