
#include "Falla.h"
#include <iostream>

using namespace std;

Falla::Falla(){
        this->fecha = Fecha();
        this->hora = Hora();
        this->direccionIP = DireccionIP();
        this->razon = "Reason";
}

Falla::Falla(string line){
        string mes, diaString, horaString, direccionIPstring;
        stringstream sstr(line);
        sstr >> mes;
        sstr >> diaString;
        sstr >> horaString;
        sstr >> direccionIPstring;
        getline(sstr, this->razon);
        this->fecha = Fecha(mes, stoi(diaString));
        this->hora = Hora(horaString);
        this->direccionIP = DireccionIP(direccionIPstring);
}

Fecha Falla::getFecha(){
     return this->fecha;
}
Hora Falla::getHora(){
	return this->hora;
}
DireccionIP Falla::getDireccionIP(){
	return this->direccionIP;
}
string Falla::getRazon(){
    return this->razon;
}
bool Falla::isAfter(Falla falla2){
    //Compara dos fechas y ve cual es mayor 
    if (this->fecha.isAfter(falla2.getFecha())) {
        return true;
        //Compara la fecha
    }
    else if (this->fecha.isEqualTo(falla2.getFecha()))
    {
        //Si las fechas son iguales compara la hora del mismo dia 
        return this->hora.isAfter(falla2.getHora());
    }
    return false;
}
string Falla::toString() const {
        return this->fecha.toString() + " " + this->hora.toString() + " " + this->direccionIP.toString() + razon;
}
