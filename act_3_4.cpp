/*
*   Act_3_4.cpp - Equipo 8
*   
*   Árbol binario
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   02 de noviembre de 2020
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include "BSTdirIP.h"
using namespace std;

void leerArchivoFallas(string path, BSTdirIP& bst) {
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
        if (dirIP == prevDirIP) {
            apariciones++;
        }
        else {
            bst.insert(prevDirIP, apariciones);
            prevDirIP = dirIP;
            apariciones = 1;
        }
    }
    
    bst.insert(dirIP, apariciones);
    datos.close();
}

int main() {
    BSTdirIP bst;
    try {
        leerArchivoFallas("Bitacora_Ordenada2.txt", bst);
    }
    catch (runtime_error& re) {
        cerr << re.what() << endl;
    }

    cout << "\nDirecciones con más accesos: " << endl;
    bst.top5();

    return 0;
}
