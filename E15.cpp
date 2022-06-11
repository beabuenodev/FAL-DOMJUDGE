// Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
* JUSTIFICACIÓN DE COSTE
* 
* Recurrencia:
* T(n) = c0             si (forall i : 0 < i < v.size() : v[i] > v[n])
* T(n) = c1 + T(n + 1)  en otro caso
* 
* Despliegue:
* T(n) = c1 + T(n + 1) = c1 + c1 + T(n + 2) = c1 + c1 + c1 + T(n + 3) = k * c1 + T(n + k)
* 
* Postulado:
* n + k = v.size() - 1
* T(n) = k*c1 + T(n + (v.size() - 1) - n) = k*c1 + c0
* 
* COSTe: O(n), siendo n el número de elementos del vector.
*/

int resolver(vector<int> v, int i) {
    if (v.size() < 2)
        return v[0];
    else {
        if (i == v.size() - 1)
            return v[i];
        else {
            if (v[i] < v[i + 1])
                return v[i];
            else
                return resolver(v, i + 1);
        }
    }
}

bool resuelveCaso() {

    int n, aux, min;
    vector <int> v;
    //Leer caso de prueba: cin>>...
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    if (!std::cin)
        return false;

    //Resolver problema
    min = resolver(v, 0);
    //Escribir resultado
    cout << min << "\n";
    return true;
}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}