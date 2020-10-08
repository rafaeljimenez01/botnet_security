#include <string>
#include <unordered_map>
using namespace std;
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
	Fecha();
	Fecha(string mes, int dia);
    string getMes();
    int getDia();
	bool isAfter(Fecha fecha2);
	bool isEqualTo(Fecha fecha2);
	string toString() const;
};