//BEATRIZ BUENO ALMAGRO E12
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool camino(vector<int> c, int D) {
    bool apta = true;
    int aux2 = c[0];
    int desnivel = 0, i = 1;

    while (apta && i < c.size()) {
        if (c[i] > aux2) {
            desnivel = desnivel + c[i] - aux2;
            if (desnivel > D)
                apta = false;
        }
        else
            desnivel = 0;

        aux2 = c[i];
        i++;
    }
    return apta;
}

bool resuelveCaso() {

    int D = 0, N = 0, aux;
    vector <int> c;
    //Leer caso de prueba: cin>>...
    cin >> D;
    cin >> N;

    if (!std::cin)
        return false;
    
    for (int i = 0; i < N; i++) {
        cin >> aux;
        c.push_back(aux);
    }

    //Resolver problema
    bool apta = camino(c, D);

    //Escribir resultado
    if (apta)
        cout << "APTA" << endl;
    else
        cout << "NO APTA" << endl;

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