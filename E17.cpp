//Beatriz Bueno Almagro E12

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int minimo(vector<int> const& v, int i, int f) {
    if (i == f - 1) //el vector tiene un elemento
        return v[i];
    else if (v[i] > v[f - 1]) //si no está rotado
        return v[f - 1];
    else { //caso recursivo
        int medio = (i + f) / 2;
        if (v[medio] > v[i])
            return minimo(v, i, medio);
        else
            return minimo(v, medio, f);

    }
}

int resolver(vector <int> const& v) {
    return minimo(v, 0, v.size());
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n, aux;
    vector <int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    if (!std::cin)
        return false;

    //Resolver problema
    int sol = resolver(v);
    //Escribir resultado
    cout << sol << '\n';
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
