#ifndef DIRECCIONIP_H
#define DIRECCIONIP_H

#include <string>
using namespace std;

class DireccionIP {
private:
    int byteA;
    int byteB;
    int byteC;
    int byteD;
    int port;
public:
    DireccionIP();
    DireccionIP(string IPString);
    int getByteA();
    int getByteB();
    int getByteC();
    int getByteD();
    int getPort();
    bool isAfter(DireccionIP dir2);
    string toString() const;
};

#endif