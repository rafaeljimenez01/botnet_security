
#ifndef FALLAS_H
#define FALLAS_H

#include "Fecha.h"
#include "Hora.h"
#include "DireccionIP.h"
class Falla {
private:
    Fecha fecha;
    Hora hora;
    DireccionIP direccionIP;
    string razon;
public:
    Falla();
    Falla(string line);
    Fecha getFecha();
    Hora getHora();
    DireccionIP getDireccionIP();
    string getRazon();
	bool isAfter(Falla falla2);
	string toString() const;
    friend ostream& operator << (ostream& os, const Falla& falla) {
        os << falla.toString();
        return os;
    }
};
#endif