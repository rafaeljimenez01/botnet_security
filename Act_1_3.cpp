#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;


class DireccionIP {
private:
    int byteA;
    int byteB;
    int byteC;
    int byteD;
    int port;
public:
    DireccionIP() {
        this->byteA = 0;
        this->byteB = 0;
        this->byteC = 0;
        this->byteD = 0;
        this->port = 0;
    }

    DireccionIP(string IPString) {
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

    int getByteA() {
        return this->byteA;
    }
    int getByteB() {
        return this->byteB;
    }
    int getByteC() {
        return this->byteC;
    }
    int getByteD() {
        return this->byteD;
    }
    int getPort() {
        return this->port;
    }
    
    string toString() {
        string IPstring =   to_string(byteA) + '.' +
                            to_string(byteB) + '.' +
                            to_string(byteC) + '.' +
                            to_string(byteD) + '.' +
                            to_string(port);
        return IPstring;
    }
};


class Hora {
private:
    string  hh,
            mm,
            ss;
public:
    Hora() {
        this->hh = "00";
        this->mm = "00";
        this->ss = "00";
    }

    Hora(string hString) {
        stringstream sstr(hString);
        getline(sstr, this->hh, ':');
        getline(sstr, this->mm, ':');
        sstr >> ss;
    }

    string getHH() {
        return this->hh;
    }
    string getMM() {
        return this->mm;
    }
    string getSS() {
        return this->ss;
    }
    
    bool isAfter(Hora hora2) {
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

    string toString() {
        return this->hh + ':' + this->mm + ':' + this->ss;
    }
};


class Fecha {
private:
    string mes;
    int dia;
    unordered_map<string, int> meses {
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Aug", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12}
    };
public:
    Fecha() {
        this->mes = "Jan";
        this->dia = 1;
    }

    Fecha(string mes, int dia) {
        this->mes = mes;
        this->dia = dia;
    }

    string getMes() {
        return this->mes;
    }

    int getDia() {
        return this->dia;
    }

    bool isAfter(Fecha fecha2) {
        if (meses[this->mes] > meses[fecha2.getMes()]) {
            return true;
        } else if (meses[this->mes] == meses[fecha2.getMes()]) {
            if (this->dia > fecha2.getDia()) {
                return true;
            }
        }
        return false;
    }

    string toString() {
        return this->mes + " " + to_string(this->dia);
    }
};


class Falla {
private:
    Fecha fecha;
    Hora hora;
    DireccionIP direccionIP;
    string razon;
public:
    Falla() {
        this->fecha = Fecha();
        this->hora = Hora();
        this->direccionIP = DireccionIP();
        this->razon = "Reason";
    }

    Falla(string line) {
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

    Fecha getFecha() {
        return this->fecha;
    }

    Hora getHora() {
        return this->hora;
    }

    DireccionIP getDireccionIP() {
        return this->direccionIP;
    }

    string getRazon() {
        return this->razon;
    }

    bool isAfter(Falla falla2) {
        if (this->fecha.isAfter(falla2.getFecha()) /*&& this->hora.isAfter(falla2.getHora())*/) {
            return true;
        }
        return false;
    }

    string toString() {
        return this->fecha.toString() + " " + this->hora.toString() + " " + this->direccionIP.toString() + razon;
    }
};


vector<Falla> leerArchivoFallas(string path) {
    ifstream datos;
    datos.open(path);
    if (datos.fail()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    string line;
    vector<Falla> fallas;
    while (getline(datos, line)) {
        fallas.push_back(Falla(line));
    }
    return fallas;
}


int main() {
    vector<Falla> fallas;
    try {
        fallas = leerArchivoFallas("bitacora.txt");
    } catch (runtime_error &re) {
        cerr << re.what() << endl;
        return 0;
    }
    cout << fallas[1].isAfter(fallas[0]) << endl;
    return 0;
}
