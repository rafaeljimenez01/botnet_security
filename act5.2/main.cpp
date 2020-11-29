#include <iostream>
#include <sstream>
#include <fstream>
#include "MyHashTable.h"

using namespace std;

void leerArchivoFallas(string path, MyHashTable& hh) {
    ifstream datos;
    datos.open(path);

    if (datos.fail()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    string  line,
            month,
            day,
            time,
            dirIP,
            date;

    // leer el resto de los registros
    while (getline(datos, line)) {
        stringstream ssLine(line);
        ssLine >> month;
        ssLine >> day;
        ssLine >> time;
        ssLine >> dirIP;
        getline(stringstream(dirIP), dirIP, ':');
        date = month + " " + day;
        hh.put(dirIP, date);
        
    }
    
    datos.close();
}

int main() {
    MyHashTable hh;
    leerArchivoFallas("bitacora2.txt", hh);
    cout << hh.getSize() << endl;
    // ejemplo:
    cout << "Total de accesos para IP 10.15.179.240: " << hh["10.15.179.240"]->numAccess << endl;
    cout << "Fechas correspondientes a IP 10.15.179.240: " << endl;
    for (string date : hh["10.15.179.240"]->dates) {
        cout << "\t" << date << endl;
    }
}
