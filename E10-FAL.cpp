//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX_VALUE = 1000;

/*
* ESPECIFICACION:
* P = { 0 <= v.size() <= 1000 && max > 0 }
* bool resolver(vector <int> v, int max) dev bool b
* Q = { b true si (forall k: 0 <= k < v.size(): v[k] <= v[k+1] && (v[k+1] - v[k] = 1 || v[k+1] - v[k] = 0))
*         false en caso contrario }
* 
* I: { 0 <= i < v.size()
*   AND anterior = v[i-1]
*   AND reps[] = {forall k: 0 <= k < length(reps): reps[k] = {# l: 0 < l <= v.size() : v[l] = k}}
* FUNCION COTA: v.size() - i
* 
* COSTE : O(n)
* JUSTIFICACION DEL COSTE : Este algoritmo recorre el array solo una vez y todas las operaciones que se realizan dentro
*                           del bucle son de coste lineal, por lo tanto tiene coste de orden O(n), siendo n el número de
*                           elementos en el array
* 
*/

bool resolver(vector <int> v, int max) {
    bool sol = true;
    int anterior = v[0];
    int reps[MAX_VALUE] = { 0 };
    reps[anterior]++;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] - anterior != 0 && v[i] - anterior != 1) {
            return false;
        }
        reps[v[i]]++;
        if (reps[v[i]] > max)
            return false;
        anterior = v[i];
    }

    return sol;
}

void resuelveCaso() {
    //resuelve aqui tu caso
    vector <int> v;
    int aux, max, n;
    bool sol;
    //Lee los datos
    cin >> max;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    //Calcula el resultado
    sol = resolver(v, max);
    //Escribe el resultado
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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
