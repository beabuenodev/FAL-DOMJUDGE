//Beatriz Bueno Almagro E12

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/*
* El caso base es cuando nos encontramos con un peso y no con un submovil. Recorremos el móvil como un árbol, descubriendo recursivamente
* submóviles (paso recursivo) hasta que nos encontramos con un peso individual (caso base)
*/

typedef struct {
    int peso;
    int dist;
}tPeso;

typedef struct {
    bool equilibrio;
    int sumapeso;
}tSol;

tSol resolver(tPeso peso) {
    int pesoizq, distizq, pesoder, distder;
    if (peso.peso != 0) { //CB: nos encontramos un peso y no otro submovil
        return { true, peso.peso };
    }
    else { //Nos encontramos un submovil. Dividimos
        cin >> pesoizq >> distizq >> pesoder >> distder;

        tPeso izq = { pesoizq, distizq };
        tPeso der = { pesoder, distder };

        tSol izquierda = resolver({ pesoizq, distizq });
        tSol derecha = resolver({ pesoder, distder });

        tSol sol;
        bool equilaux = (izquierda.sumapeso * distizq) == (derecha.sumapeso * distder);
        if (izquierda.equilibrio && derecha.equilibrio && equilaux)
            sol.equilibrio = true;
        else
            sol.equilibrio = false;
        sol.sumapeso = izquierda.sumapeso + derecha.sumapeso;
        return sol;
    }
}

void resuelveCaso() {
    tPeso raiz = { 0, 0 };
    tSol sol = resolver(raiz);
    //Escribe el resultado
    if (sol.equilibrio)
        cout << "SI\n";
    else
        cout << "NO\n";
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