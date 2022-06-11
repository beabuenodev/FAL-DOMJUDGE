//Beatriz Bueno Almagro E12

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct tSolucion {
    int lmax;
    vector <int> iniciollanos;
};

tSolucion heidi(vector<int> const& v, int lmin) {
    tSolucion sol;
    sol.lmax = 0;

    int max = v[v.size() - 1], cllano  = 1;
    int anterior = v[v.size() - 1];

    if (v.size() == 1) {
        return sol;
    }
    for (int i = v.size() - 2; i >= 0; i--) {
        if (v[i] > max) {
            max = v[i];
        }
        if (v[i] == anterior && anterior >= max) { 
            cllano++;
            if (cllano == lmin) 
                sol.iniciollanos.push_back(i + cllano - 1);
            if (cllano > sol.lmax && cllano >= lmin)
                sol.lmax = cllano;
        }
        else {
            cllano = 1;
        }
        anterior = v[i];
    }

    return sol;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int aux, n, lmin = 1;
    vector <int> v;

    cin >> n;
    cin >> lmin;

    if (!std::cin)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.push_back(aux);
    }

    tSolucion sol;

    //Resolver problema
    
    sol = heidi(v, lmin);

    //Escribir resultado

    cout << sol.lmax << " " << sol.iniciollanos.size() << " ";
    for (int i = 0; i < sol.iniciollanos.size(); i++)
        cout << sol.iniciollanos[i] << " ";
    cout << endl;

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
