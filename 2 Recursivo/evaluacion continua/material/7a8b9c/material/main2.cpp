//Nombre y apellidos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>



//Define aqui tu funcion recursiva

//...

//Analisis y justificacion del coste



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (!std::cin) return false;
    int K;
    std::cin >> K;
    std::vector<int> v(num);
    for (int & n: v) std::cin >> n;
    
    bool b;
    
    //Llama aqui a tu funcion recursiva
    
    
    if (b) std::cout << "SI\n";
    else std::cout << "NO\n";
    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
    std::ifstream in("sample2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
   #endif
    
    while (resuelveCaso());
    
    // restablecimiento de cin
    
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
