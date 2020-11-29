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
    // ejemplo:
    char option;
    option = 'y';
    while(option != 'n'){
        if(option == 'n'){
            option = 'n';
        }
        else if(option != 'n' && option != 'y'){
            cout << "Introduce un valor valido [y/n] " << endl;
            cin >> option;
        }
        else{
        cout << "De que IP deseas conocer la informacion: " << endl;
        string ip;
        cin >> ip;
        cout << "La informacion de: " << ip << " es: " << endl;
        cout << hh[ip] << endl;
        cout << "Deseas buscar otra ip [y/n]: ";
        cin >>option;
        }
    }

}
