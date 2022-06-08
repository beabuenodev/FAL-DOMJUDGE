//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
* ESPECIFICACION
* P = {edificios.size() > 0 and existe k:0 <= k < edificios.size(): edificios[k] > nave}
* tSolucion resolver(vector <int> edificios, int nave) dev sol.inicio, sol.fin
* Q = {0 < = sol.inicio <= sol.fin < edificios.size() AND forall i: sol.inicio <= i <= sol.fin : edificios[i] > nave
*       AND max(sol.fin - (sol.inicio - 1))}
* INVARIANTE = {0 <= sol.inicio <= sol.fin < edificios.size() AND contadorSegMax = max(sol.fin - (sol.inicio - 1))
*               AND contadorSeg (sol.fin - (sol.inicio - 1))}
* 
* Coste : O(n)
* Justificación: Todas las operaciones dentro del bucle son de coste constante salvo el propio bucle que se repite n veces
*               siendo n el número de edificios.
*/

struct tSolucion {
    int inicio;
    int fin;
};

tSolucion resolver(vector <int> edificios, int nave) {
    tSolucion sol;

    int contadorSegMax = 0, contadorSeg = 0;
    for (int i = 0; i < edificios.size(); i++) {
        if (edificios[i] > nave) {
            contadorSeg++;
            if (contadorSeg > contadorSegMax) {
                contadorSegMax = contadorSeg;
                sol.inicio = i - contadorSeg + 1;
            }
        }
        else contadorSeg = 0;
    }

    sol.fin = sol.inicio + contadorSegMax - 1;

    return sol;
}

void resuelveCaso() {
    //resuelve aqui tu caso
    int n, nave, aux;
    vector <int> edificios;
    //Lee los datos
    cin >> n;
    cin >> nave;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        edificios.push_back(aux);
    }
    //Calcula el resultado
    tSolucion sol;
    sol = resolver(edificios, nave);
    //Escribe el resultado
    cout << sol.inicio << " " << sol.fin << endl;
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
