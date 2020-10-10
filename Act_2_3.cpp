/*
*   Act_2_3.cpp - Equipo 8
*   
*   Ordenar direcciones IP
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   9 de octubre de 2020
*/

#include <fstream>
#include <stdexcept>
#include "Falla.h"
#include "DbLinkedList.h"
using namespace std;

void leerArchivoFallas(string path, DbLinkedList& fallas) {
    ifstream datos;
    datos.open(path);
    if (datos.fail()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    string line;

    while (getline(datos, line)) {
        fallas.insertLast(Falla(line));
    }

    datos.close();
}

int main() {

    DbLinkedList fallas;
    try {
        leerArchivoFallas("bitacora.txt", fallas);
    } catch (runtime_error &re) {
        cerr << re.what() << endl;
        return 0;
    }

    cout << fallas;

    return 0;
}
