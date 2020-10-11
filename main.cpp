/*
*   Act_2_3.cpp - Equipo 8
*
*   Ordenar direcciones IP
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   11 de octubre de 2020
*/

#include <fstream>
#include <stdexcept>
#include <chrono>
#include "Falla.h"
#include "DbLinkedList.h"
using namespace std;
using namespace std::chrono;

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

void guardarArchivoFallas(string path, const DbLinkedList& fallas) {
    cout<<"Espera un momento, creando la copia ordenada en un archivo txt"<<endl;
	ofstream salida;
	salida.open(path, ios::out);
	if(salida.fail()){
        cout<<"No se pudo realizar la copia"<<endl;
	}
	salida<<fallas<<endl;
	salida.close();
	cout<<endl;
	cout<<"Archivo guardado como '" << path << "'" <<endl;
}

// buscarEnRangoIP
// Recibe las direcciones que delimitan la búsqueda como strings
// Despliega el resultado de búsqueda realizada en la lista de fallas
void buscarEnRangoIp(string dirIP1, string dirIP2, DbLinkedList& fallas) {
    DbLinkedListNode *inicio = fallas.binarySearch(DireccionIP(dirIP1));
    cout << "se encontró inicio" << endl;
    DbLinkedListNode *fin = fallas.binarySearch(DireccionIP(dirIP2));
    cout << "se encontró final" << endl;
    while (inicio != fin->next) {
		cout << inicio->falla << endl;
		inicio = inicio->next;
	}   
}

int main() {

    // Abrir el archivo
    DbLinkedList fallas;
    try {
        leerArchivoFallas("bitacora.txt", fallas);
    } catch (runtime_error &re) {
        cerr << re.what() << endl;
        return 0;
    }

    // Ordenar el archivo
    cout << "Ordenando por dirección IP..." << endl;
    auto start = high_resolution_clock::now();
    fallas.mergeSort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    double seconds = (double) duration.count() / 1000;
	cout << "Tiempo de ordenamiento: " << seconds << " segundos" << endl;

    // Búsqueda y despliegue
    char respuesta;
    while (respuesta != 'n') {
        cout << endl;
        cout << "***** Buscar direcciones IP ordenadas dentro de un rango *****" << endl;
        cout << "IP inicial: ";
        string stringIPinferior;
        cin >> stringIPinferior;
        cout << "IP final: ";
        string stringIPsuperior;
        cin >> stringIPsuperior;
        buscarEnRangoIp(stringIPinferior, stringIPsuperior, fallas);
        cout<<endl;
        cout << "¿Desea realizar otra búsqueda? ([y]yes / [n]no)" << endl;
        cin >> respuesta;
    }

    // Guardar en archivo el resultado del ordenamiento
    guardarArchivoFallas("Bitacora_Ordenada.txt", fallas);
	return 0;
}
