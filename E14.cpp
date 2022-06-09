//Beatriz Bueno Almagro E12

#include <iostream>
#include <fstream>
using namespace std;

/*
* Justificacion Coste Digito Complementario e Inverso:
* 
* T(n) = c0              si n = 0
* T(n) = c2              si n = 1
* T(n) = T(n - 1) + c1   si n > 1
* siendo n el numero de cifras (suponemos que el 0 no tiene cifras)
* 
* Despliegue
* T(n) = c1 + T(n - 1) = c1 + c1 + T(n - 2) = c1 + c1 + c1 + T(n-3) = ...
*      = c1 * k + T(n - k)
* 
* Postulado
* n - k = 0 -> k = n
* T(n) = c1*n + T(n-n) = c1 * n + T(0) = c1*n + c0 = n
* 
* Coste: O(n) siendo n el número de cifras
*/

int complementarioSimple(long long int n) {
    return 9 - n;
}

int digitoComplementario(long long int n) {
    if (n / 10 == 0) return complementarioSimple(n);
    else {
        long long int problemasimple = digitoComplementario(n / 10);
        long long int problemaoriginal = problemasimple * 10 + complementarioSimple(n % 10);
        return problemaoriginal;
    }
}

void digitoCompInverso(long long int n, long long int& r) {
    if (n < 10) {
        r *= 10;
        r += complementarioSimple(n);
    }
    else {
        r *= 10;
        r += complementarioSimple(n % 10);
        digitoCompInverso(n / 10, r);
    }

}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    long long int n, comp = 0, compinv = 0;
    cin >> n;
       //Calcula el resultado
    comp = digitoComplementario(n);
    digitoCompInverso(n, compinv);
       //Escribe el resultado
    cout << comp << " " << compinv << "\n";
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
