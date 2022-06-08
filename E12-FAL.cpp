//NOMBRE y APELLIDOS

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void invertir(int number, int& result) {
    if (number == 0) return;
    else {
        result *= 10;
        result += number % 10;
        invertir(number / 10, result);
    }
}

bool resuelveCaso() {
    //resuelve aqui tu caso
    int number;
    int sol = 0;
    //Lee los datos
    cin >> number;

    if (number == 0)
        return false;
    else //Calcula el resultado
        invertir(number, sol);
    cout << sol << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}