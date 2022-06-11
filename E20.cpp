// NOMBRE Y APELLIDOS

#include <iostream>

#include <fstream>
using namespace std;

void tieneUno(int i, int& c) {

}

bool resuelveCaso() {
    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    int c = 0;
    tieneUno(n, c);
    //Resolver problema
    //Escribir resultado
    cout << c << "\n";
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
