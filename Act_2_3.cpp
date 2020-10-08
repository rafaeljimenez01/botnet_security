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

DbLinkedList leerArchivoFallas(string path) {
    ifstream datos;
    datos.open(path);
    if (datos.fail()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    string line;
    DbLinkedList fallas;
    
    while (getline(datos, line)) {
        fallas.insertLast(Falla(line));
    }
    datos.close();
    return fallas;
}

int main() {
    DbLinkedList fallas;
    try {
        fallas = leerArchivoFallas("bitacora.txt");
    } catch (runtime_error &re) {
        cerr << re.what() << endl;
        return 0;
    }
    
    /*
    cout << "Ordenando..." << endl;
    quickSort(0, fallas.size()-1, fallas);

    
	ofstream fallasOrdenadas("bitacoraOrdenada.txt");
    for (Falla f : fallas) {
        fallasOrdenadas << f.toString() << "\n";
    }
	fallasOrdenadas.close();
    cout << "Registros ordenados guardados en 'bitacoraOrdenada.txt'" << endl;
    

	int dia1, dia2;
    string mes1, mes2;
    cout << "Ingresa las fechas inicial y final de búsqueda en una línea (ej.: Aug 1 Aug 2):" << endl;
    cin >> mes1 >> dia1 >> mes2 >> dia2;
    Fecha f1(mes1, dia1);
    Fecha f2(mes2, dia2);
    vector<Falla> resultado = busqueda(f1, f2, fallas);
    for (Falla f : resultado) {
        cout << f.toString() << endl;
    } 

    */

   /*
    for (int i = 0; i < fallas.length(); i++) {
        cout << fallas.getAt(i) << endl;
    } */

    return 0;
}
