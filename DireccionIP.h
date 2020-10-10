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
    int getByteA() const;
    int getByteB() const;
    int getByteC() const;
    int getByteD() const;
    int getPort() const;
    bool isAfter(DireccionIP dir2);
    bool operator <(const DireccionIP& dir2) const;
    string toString() const;
};

#endif