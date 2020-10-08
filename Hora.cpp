#include "Hora.h"
#include <iostream>
using namespace std;

Hora::Hora() {
    this->hh = "00";
    this->mm = "00";
    this->ss = "00";
}

Hora::Hora(string hString) {
    stringstream sstr(hString);
    getline(sstr, this->hh, ':');
    getline(sstr, this->mm, ':');
    sstr >> ss;
}

string Hora::getHH() {
    return this->hh;
}
string Hora::getMM() {
    return this->mm;
}
string Hora::getSS() {
    return this->ss;
}

bool Hora::isAfter(Hora hora2) {
    if (stoi(this->hh) > stoi(hora2.getHH())) {
        return true;
    } else if (stoi(this->hh) == stoi(hora2.getHH())) {
        if (stoi(this->mm) > stoi(hora2.getMM())) {
            return true;
        } else if (stoi(this->mm) == stoi(hora2.getMM())) {
            if (stoi(this->ss) > stoi(hora2.getSS())) {
                return true;
            }
        }
    }
    return false;
}

string Hora::toString() const {
    return this->hh + ':' + this->mm + ':' + this->ss;
}