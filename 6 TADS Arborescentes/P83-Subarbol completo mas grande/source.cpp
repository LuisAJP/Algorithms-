
/*
Tema:9
Problema 83 Subarbol completo mas grande
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/


// Construye un árbol binario a partir de la entrada y después
// calcula su altura de forma recursiva
#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <iostream>
using namespace std;


struct tInfo {
	int maxAltura;
	int altura;
};

/*El coste es O(N), donde N es el numero de nodos, recorre todos los nodos
del arbol para buscar el subarbol completo mas grande, el recorrido del arbol
se hace en postorden(iz,dr,raiz)
*/
tInfo completo(const bintree<char> &a) {
	if (a.empty()) 
		return{ 0, 0 };
	tInfo iz = completo(a.left());
	tInfo dr = completo(a.right());
	tInfo info;
	info.altura = min(iz.altura,dr.altura)+1;
	info.maxAltura = max(iz.maxAltura, dr.maxAltura);
	info.maxAltura = max(info.altura, info.maxAltura);
	return info;
}

// resuelve un caso de prueba
void resuelveCaso() {

	bintree<char> a;
	a = leerArbol('.');
	tInfo info = completo(a);
	cout << info.maxAltura << '\n';
}

int main() {


	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}
