/*
*   Act 5.2 main.cpp - Equipo 8
*
*   La actividad 5.2 guarda todas las ips en una hash table junto con un resumen de su informacion incluyendo
*   fechas de acceso y numero de accesos.
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   29 de noviembre de 2020
*/


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
        try{
            cout << hh[ip] << endl;
        }
        catch(logic_error r){
            cout << "No se encontro la ip " << "el error es: " << r.what() << endl;
        }
        cout << "Deseas buscar otra ip [y/n]: ";
        cin >>option;
        }
    }

}
