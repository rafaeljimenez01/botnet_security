#ifndef HORA_H
#define HORA_H

#include <string>
#include <sstream>
using namespace std;

class Hora {
private:
    string  hh,
            mm,
            ss;
public:
    Hora();
    Hora(string hString);
    string getHH();
    string getMM();
    string getSS();
    bool isAfter(Hora hora2);
    string toString() const;
};

#endif