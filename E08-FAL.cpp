//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
* ESPECIFICACIÓN:
* P = {v.size() > 0 && v.size() <= 1000}
* int resolver(vector <int> v) dev sol
* Q = {sol = max(y - x : forall k 0 <= y <= k <= x < v.size() : v[k] >= v[k+1])}
* 
* Invariante: { 0 <= i < v.size()
*               AND contador = y - x : forall k 0 <= y <= k <= x < v.size() : v[k] >= v[k+1]
*               AND maxcontador = max(for all contador)
*               AND b = true si v.size() - 1 AND (contador == 0 OR v[i-1] < v[i])
*                               OR (v[i] >= v[i + 1] OR (i != 0 AND i == v.size() - 2) }
* Funcion de cota: v.size() - i - 1
* 
* COSTE: O(n)
* JUSTIFICACION: El array se recorre una sola vez con un bucle for, y todas las operaciones realizadas sobre el array son
*               lineales, por lo tanto el coste es lineal O(n) siendo n el número de elementos del array.
*/

int resolver(vector <int> v) {
    
    int x = 1, xaux = 1, temp = v[0];

    if (v.size() == 0)
        x = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= temp) {
            xaux++;

            if (xaux >= x)
                x = xaux;
        }
        else xaux = 1;
        temp = v[i];
    }

    return x;
}

void resuelveCaso() {
    //resuelve aqui tu caso
    int aux, n;
    vector <int> v;
    int sol;
    //Lee los datos
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    //Calcula el resultado
    sol = resolver(v);
    //Escribe el resultado
    cout << sol << endl;
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
