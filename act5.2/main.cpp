#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void leerArchivoFallas(string path, ) {
    ifstream datos;
    datos.open(path);

    if (datos.fail()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    string line,
        prevDirIP,
        dirIP;

    // leer primer registro
    getline(datos, line);
    stringstream ssLine(line);
    ssLine >> prevDirIP;
    ssLine >> prevDirIP;
    ssLine >> prevDirIP;
    getline(ssLine, prevDirIP, ':');
    int apariciones = 1;

    // leer el resto de los registros
    while (getline(datos, line)) {
        stringstream ssLine(line);
        ssLine >> dirIP;
        ssLine >> dirIP;
        ssLine >> dirIP;
        getline(ssLine, dirIP, ':');
    }
    
    datos.close();
}
