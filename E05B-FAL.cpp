//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
* Especificación
* P = {0 <= n <= 100000}
* bool viscoso(vector <int> const& v, int& p) dev sol
* Q = {sol = true if existe j tal que v[j] = sum k : j <= k < v.size() : v[k]
*            false en caso contrario
*      p = max l : 0 <= l < v.size() and v[l] = (sum k : l <= k < v.size() : v[k]): l}
* 
* Funcion de cota: v.size() - i
* Invariante = {0 <= i < v.size()
*               and p = max l : i <= l < v.size() and v[l] = (sum k : l <= k < v.size() : v[k]): l}
*               and suma = sum k : i <= k < v.size() : v[k]
* 
* Coste = O(n)
* Justificación - El coste del algoritmo es de orden lineal ya que se recorre cada componente del vector exactamente una vez y todas las operaciones realizadas son de orden lineal
*/

bool viscoso(vector <int> const& v, int& p) {
    bool sol;
    int suma = 0;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == suma) {
            p = i;
            return true;
        }
        else {
            suma = suma + v[i];
        }
    }

    return false;

}

void resuelveCaso() {
    //resuelve aqui tu caso
    int n, aux, p = -1;
    vector <int> v;
    bool sol;

    //Lee los datos
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    //Calcula el resultado
    sol = viscoso(v, p);
    //Escribe el resultado
    if (sol)
        cout << "Si " << p << endl;
    else
        cout << "No" << endl;
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