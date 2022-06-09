// NOMBRE Y APELLIDOS 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>

/*
* noMasDos(v,i,j) dev bool b
* b = false si (existe k : i <= k < j : v[k - 1] > v[k] > v[k + 1])
*  true en caso contrario
*/

using namespace std;

//ESPECIFICA la funcion que resuelve el problema

int resolver(std::vector<int> const& v) {
	int x = 1, xmax = 1, aux = 1;

	//bucle
	if (v.size() > 2) {
		//resolucion
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] < v[i])
				aux++;
			else
				aux = 1;
			if (aux != 3) {
				x++;
				if (x > xmax) {
					xmax = x;
				}
			}
			else {
				x = 2;
				aux = 2;
			}
		}
	}
	else {
		return v.size();
	}

	//Funcion de cota
	//Invariante
	return xmax;

}


//Postcondicion: llama r al resultado

//Analisis justificado del coste - lineal O(n) - este algoritmo recorre todos los elementos del array una vez y realiza operaciones lineales sobre este. 

// Esta funcion resuelve un caso de prueba
void resuelveCaso() {
	int numElems = 0; size_t n;
	std::cin >> numElems;
	std::vector<int> v(numElems);
	for (int& i : v) std::cin >> i;
	int sol = resolver(v);
	std::cout << sol << "\n";

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("sample1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();



#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}