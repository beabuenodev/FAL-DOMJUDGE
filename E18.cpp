//Beatriz Bueno Almagro E12

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool bongo(vector<int> const& v, int i, int f, int x, int& pos) {
    /*if (i == f - 1) {
        if (v[i] == x)  //el vector solo tiene un elemento
            return v[i];
        else
            return -1;
    } 
    else {
        int medio = (i + f) / 2;
        if (v[medio] == x + medio)
            return v[medio];
        else if (v[medio] > x + medio)
            return bongo(v, i, medio, x);
        else
            return bongo(v, medio, f, x);
    }*/
    int m = (i + f) / 2;
    
    if (x + m == v[m]) {
        pos = v[m];
        return true;
    }
    else if (i == f) { return false; }
    else {
        if (x + m > v[m]) {
            return bongo(v, m + 1, f, x, pos);
        }
        else {
            return bongo(v, i, m, x, pos);
        }
    }

}

bool resolver(vector<int> const& v, int x, int& pos) {
    return bongo(v, 0, v.size() - 1, x, pos);
}

void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos
    int n, x, aux, pos = -1;
    vector <int> v;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }
    //Calcula el resultado
    bool sol = resolver(v, x, pos);
    //Escribe el resultado
    if (!sol)
        cout << "NO\n";
    else
        cout << pos << '\n';
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