#include "Fecha.h"
#include <string>

Fecha::Fecha(){
    this->mes = "Jan";
    this->dia = 1;
}
Fecha::Fecha(string mes, int dia){
    this->mes = mes;
    this->dia = dia;
}
string Fecha::getMes(){
	return this->mes;
}
int Fecha::getDia(){
	return this->dia;
}
bool Fecha::isAfter(Fecha fecha2){
    if (meses[this->mes] > meses[fecha2.getMes()]) {
            return true;
        } else if (meses[this->mes] == meses[fecha2.getMes()]) {
            if (this->dia > fecha2.getDia()) {
                return true;
            }
        }
        return false;
}
bool Fecha::isEqualTo(Fecha fecha2){
    if (this->mes == fecha2.getMes() && this->dia == fecha2.getDia()) {
            return true;
        } else {
            return false;
        }
}
string Fecha::toString() const {
    return this->mes + " " + to_string(this->dia);
}