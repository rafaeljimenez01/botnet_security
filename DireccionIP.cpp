#include "DireccionIP.h"
#include <iostream>
#include <sstream>
using namespace std;

DireccionIP::DireccionIP() {
    this->byteA = 0;
    this->byteB = 0;
    this->byteC = 0;
    this->byteD = 0;
    this->port = 0;
}

DireccionIP::DireccionIP(string IPString) {
    stringstream ss(IPString);
    string substr;
    getline(ss, substr, '.');
    this->byteA = stoi(substr);
    getline(ss, substr, '.');
    this->byteB = stoi(substr);
    getline(ss, substr, '.');
    this->byteC = stoi(substr);
    getline(ss, substr, ':');
    this->byteD = stoi(substr);
    ss >> this->port;
}

int DireccionIP::getByteA() const{
    return this->byteA;
}
int DireccionIP::getByteB() const{
    return this->byteB;
}
int DireccionIP::getByteC() const{
    return this->byteC;
}
int DireccionIP::getByteD() const{
    return this->byteD;
}
int DireccionIP::getPort() const{
    return this->port;
}

bool DireccionIP::isAfter(DireccionIP dir2) {
    if(this->byteA > dir2.getByteA()){
        return true;
    } else if (this->byteA == dir2.getByteA()) {
        if (this->byteB > dir2.getByteB()) {
            return true;
        } else if (this->byteC == dir2.getByteC()) {
            if(this->byteC > dir2.getByteC()){
                return true;
            } else if (this->byteD == dir2.getByteD()) {
                if(this->byteD > dir2.getByteD()){
                    return true;
                } else {
                    return this->port > dir2.getPort();
                }
            }
        }
    }
    return false;
}

bool DireccionIP::operator <(const DireccionIP& dir2) const {
    if(this->byteA < dir2.getByteA()){
        return true;
    } else if (this->byteA == dir2.getByteA()) {
        if (this->byteB < dir2.getByteB()) {
            return true;
        } else if (this->byteB == dir2.getByteB()) {
            if(this->byteC < dir2.getByteC()){
                return true;
            } else if (this->byteC == dir2.getByteC()) {
                if(this->byteD < dir2.getByteD()){
                    return true;
                } else if (this->byteD == dir2.getByteD()) {
                    return this->port < dir2.getPort();
                }
            }
        }
    }
    return false;

}

bool DireccionIP::operator ==(const DireccionIP& dir2) const {
    if (this->byteA == dir2.getByteA()) {
        if (this->byteB == dir2.getByteB()) {
            if (this->byteC == dir2.getByteC()) {
                if (this->byteD == dir2.getByteD()) {
                    if (this->port == dir2.getPort()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

string DireccionIP::toString() const {
    string IPstring =   to_string(byteA) + '.' +
                        to_string(byteB) + '.' +
                        to_string(byteC) + '.' +
                        to_string(byteD) + ':' +
                        to_string(port);
    return IPstring;
}

string DireccionIP::noPort() const {
    string noPort =     to_string(byteA) + '.' +
                        to_string(byteB) + '.' +
                        to_string(byteC) + '.' +
                        to_string(byteD);
    return noPort;
}
