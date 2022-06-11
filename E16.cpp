//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
* Aclaraciones:
* int i : inicio (ind)
* int f : final (ind)
* char p : primero 
* char u : ultimo
* 
* JUSTIFICACION DEL COSTE:
* T(n) = c0           si n = 1
* T(n) = c1 + T(N/2)  si n > 1
* siendo n el número de presos
* 
* Coste: O(log n) - resuelto por búsqueda binaria
*/

char busquedaPreso(vector<char> v, int i, int f, char p, char u) {
    //CB:
    if (i == f - 1) //Si el array tiene un elemento, p o u será el fugado.
        if (v[i] == p)
            return u;
        else 
            return p;
    //CR:
    else {
        int indmedio = (i + f) / 2;
        char medio = (p + u) / 2; //si sacamos del array nos podiamos perder al fugado. Así accedemos al vector de todos los presos, con el fugado.
        if (v[indmedio] > medio) //Si el hueco esta en la primera mitad se busca al preso en la primera mitad
            return busquedaPreso(v, i, indmedio, p, medio);
        else
            return busquedaPreso(v, indmedio, f, medio, u);
    }
}

char resolver(vector<char> const& v, char p, char u) {
    return busquedaPreso(v, 0, v.size(), p, u);
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    char p, u, aux;
    vector <char> v;
    cin >> p >> u;
    for (int i = 0; i < u - p; i++) {
        cin >> aux;
        v.push_back(aux);
    }
       //Calcula el resultado
    char sol = resolver(v, p, u);
       //Escribe el resultado
    cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}