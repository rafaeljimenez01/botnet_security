/*
*   Act_1_3.cpp - Equipo 8
*   
*   Ordenador y buscador de fallas de bitácora
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   13 de septiembre de 2020
*/

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

    bool isEqualTo(Fecha fecha2) {
        if (this->mes == fecha2.getMes() && this->dia == fecha2.getDia()) {
            return true;
        } else {
            return false;
        }
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
    //Compara dos fechas y ve cual es mayor 
        if (this->fecha.isAfter(falla2.getFecha())) {
			return true;
            //Compara la fecha
		}
		else if (this->fecha.isEqualTo(falla2.getFecha()))
		{
            //Si las fechas son iguales compara la hora del mismo dia 
			if (this->hora.isAfter(falla2.getHora())) {
                return true;
            } else {
                return false;
            }
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
    datos.close();
    return fallas;
}

/*
*   QuickSort: particionar(int, int, vector) y quickSort(int, int, vector) 
*       Algoritmo que ordena los datos de un vector con una estrategia 
*       de "divide y vencerás"y un pivote.
*   Complejidad - mejor caso y caso promedio: O(n*log(n)), peor caso: O(n^2).
*/

/*      
        Función paticionar
        Parametros de entrada: int inicio del vector, int fin del vector, vector a particionar.
        Valores de retorno: entero indice del pivote.
        Complejidad - O(n) siempre   
*/
int particionar(int inicio,int fin, vector<Falla> &fallas){
    Falla pivot = fallas[inicio];
	int i = inicio + 1;
	Falla temp;
	for (int j = inicio + 1; j <= fin; j++)
	{
		if(pivot.isAfter(fallas[j])){
			temp = fallas[i];
			fallas[i] = fallas[j];
			fallas[j] = temp;
			i++;
		}
	}
    temp = fallas[inicio];
	fallas[inicio] = fallas[i - 1];
	fallas[i - 1] = temp;

	return i;
}

/*      
        Función quickSort
        Parametros de entrada: int inicio del vector, int fin del vector, vector a particionar.
        Valores de retorno: ninguno.
        Complejidad - mejor caso y caso promedio: O(n*log(n)), peor caso: O(n^2)  
*/

void quickSort(int inicio, int fin, vector<Falla> &fallas) {
	if (inicio < fin)
	{
		int posPiv = particionar(inicio, fin, fallas);
		quickSort(inicio, posPiv - 1, fallas);
		quickSort(posPiv, fin,fallas);
	}
}

/*
        Función Búsqueda Binaria
        Parametros de entrada: int inicio del vector, int fin del vector, vector a particionar.
        Valores de retorno: indice donde aproximadamente se encuentra el elemento.
        Complejidad - mejor caso: O(1), peor caso: O(log(n)).
*/
int busquedaBinaria(Fecha f, vector <Falla> &fallas) {
    int min = 0,
		max = fallas.size(),
		avg;
	while(min <= max){
		avg = (min + max) / 2;
        if (f.isEqualTo(fallas[avg].getFecha())){
			return avg;
		}
		else if(fallas[avg].getFecha().isAfter(f)){
            max = avg - 1;
		}
		else{
			min = avg + 1;
		}
	}
    // Caso en el que no encuentra la fecha exactamente
    // Devuelve avg que es la posición más cercana
	return avg;
}

/*
        Función Búsqueda Secuencial Primero
        Algoritmo de búsqueda secuencial que encuentra el primer elemento entre
        varios que son iguales dentro de un vector ordenado.
        -Parametros de entrada: inicio de busqueda, vector donde se realizara la busqueda.
        -Valores de retorno: indice de primer valor encontrado.
        Complejidad - O(n).
*/
int busquedaSecuencialPrimero(int pos, vector<Falla> &fallas) {
    Fecha fechaOriginal = fallas[pos].getFecha();
    while (fallas[pos].getFecha().isEqualTo(fechaOriginal)) {
        pos--;
    }
    return pos+1;
}

/*
*   Función Búsqueda Secuencial Ultimo
    Algoritmo de búsqueda secuencial que encuentra el último elemento entre
    varios que son iguales en un vector ordenado.
    -Parametros de entrada: int pos, vector a particionar.
    -Valores de retorno: indice de ultimo valor encontrado.
    Complejidad - O(n) siempre.
*/
int busquedaSecuencialUltimo(int pos, vector<Falla> &fallas) {
    Fecha fechaOriginal = fallas[pos].getFecha();
    while (fallas[pos].getFecha().isEqualTo(fechaOriginal)) {
        pos++;
    }
    return pos;
}

/*
    Búsqueda.
    -Parámetros de entrada: Fecha inicio, Fecha fin, vector a particionar.
    -Valor de returno: un vector de Fallas que satisfacen los criterios de búsqueda.
    Complejidad - O(n).
*/
vector<Falla> busqueda(Fecha inicio, Fecha fin, vector<Falla> &fallas) {
	int primero = busquedaBinaria(inicio, fallas);
    primero = busquedaSecuencialPrimero(primero, fallas);
    int ultimo = busquedaBinaria(fin, fallas);
    ultimo = busquedaSecuencialUltimo(ultimo, fallas);
    vector<Falla> resultado;
    for (int i = primero; i < ultimo ; i++) {
        resultado.push_back(fallas[i]);
    }
	return resultado;
}

int main() {
    vector<Falla> fallas;
    try {
        fallas = leerArchivoFallas("bitacora.txt");
    } catch (runtime_error &re) {
        cerr << re.what() << endl;
        return 0;
    }
    
    quickSort(0, fallas.size()-1, fallas);
	ofstream fallasOrdenadas("FallasOrdenadas.txt");
    for (Falla f : fallas) {
        fallasOrdenadas << f.toString() << "\n";
    }
	fallasOrdenadas.close();

	int dia1, dia2;
    string mes1, mes2;

    cin >> mes1 >> dia1 >> mes2 >> dia2;
    Fecha f1(mes1, dia1);
    Fecha f2(mes2, dia2);
    vector<Falla> resultado = busqueda(f1, f2, fallas);
    for (Falla f : resultado) {
        cout << f.toString() << endl;
    } 

    return 0;
}
