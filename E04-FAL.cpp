//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Especificacion
/*
* {true}
* proc equilibrio(vector<int> v) dev int p
* {-1 <= p > v.size() and numUnos(v,p+1) = numCeros(v,p+1)
* and forall k: p < k < v.size():numUnos(v, k+1) != numCeros(v, k+1)}
*
*/

int equilibrio(vector<int> v) {
    int p = -1;
    int numCeros = 0, numUnos = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            numCeros++;
        if (v[i] == 1)
            numUnos++;
        if (numUnos == numCeros)
            p = i;
    }
    return p;
}

void resuelveCaso() {
    //resuelve aqui tu caso

    int n, aux, p;
    vector<int>v; 

    //Lee los datos
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    //Calcula el resultado

    p = equilibrio(v);

    //Escribe el resultado
    cout << p << endl;
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