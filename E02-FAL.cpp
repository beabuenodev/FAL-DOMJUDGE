// Nombre del alumno Beatriz Bueno Almagro
// Usuario del Juez E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*

   Especificación

   P = 2 <= n <= 100.000 && forall i: 0 <= i < n : 1 <= alturas[i] <= 100.000
   fun resolver(int vector <int>& alturas) return bool dalton
   Q = forall w: 0 <= x < n: (alturas[x] < alturas[w+1] || (alturas[w] > alturas[w+1])

*/

// función que resuelve el problema
bool resolver(vector <int>& alturas) {

    bool dalton = false;
    int i = 0;

    if (alturas[0] < alturas[1]) {
        dalton = true;
        while (dalton && i < alturas.size() - 1) {
            if (alturas[i] >= alturas[i + 1])
                dalton = false;
            i++;
        }
    }
    else if (alturas[0] > alturas[1]) {
        dalton = true;
        while (dalton && i < alturas.size() - 1) {
            if (alturas[i] <= alturas[i + 1]) 
                dalton = false;
            i++;
        }
    }

    return dalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector <int> alturas;
    int aux;
    for (int i = 0; i < N; i++) {
        cin >> aux;
        alturas.push_back(aux);
    }

    bool sol = false;

    if (N >= 2 || N <= 100000) {
        sol = resolver(alturas);
    }

    // escribir sol
    if (sol) {
        cout << "DALTON" << endl;
    }
    else {
        cout << "DESCONOCIDOS" << endl;
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}