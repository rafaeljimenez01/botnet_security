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
    //checar si existe una
// new nodo dirIP

    getline(datos, line);
    stringstream ssLine(line);
    ssLine >> prevDirIP;
    ssLine >> prevDirIP;
    ssLine >> prevDirIP;
    getline(ssLine, prevDirIP, ':');
    int apariciones = 1;
    int total = 0;
    int totalLineas = 1;
    while (getline(datos, line)) { //reads the IP without port.
        // si sig. es igual,
        //      duplicados++
        // si es diferente,
        //      insertar anterior y crear nuevo nodo
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
            total = total + apariciones;
            apariciones = 1;
        }
        totalLineas++;
    }
    
    bst.insert(dirIP, apariciones);
    total = total + apariciones;
    cout << "TOTAL: " << total << endl;
    cout << "TOTAL LINEASSSSS " << totalLineas << endl;
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
    
    bst.inorder();

    bst.top5();

    return 0;
}
