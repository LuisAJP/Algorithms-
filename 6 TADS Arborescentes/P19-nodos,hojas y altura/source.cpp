
/*
Tema:9
Problema 19 Numero de nodos, hojas y altura de un arbol binario
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

struct tInfo{
	int nodos;
	int hojas;
	int altura;
};

tInfo propiedades(const bintree<char> & a){
	if (a.empty())
		return{0,0,0};
	tInfo iz, dr,info;
	iz = propiedades(a.left());
	dr = propiedades(a.right());
	info = {0,0,0};
	
	if (a.left().empty() && a.right().empty())
		info.hojas += 1;
	
	info.nodos = info.nodos + iz.nodos + dr.nodos + 1;
	info.hojas = info.hojas + iz.hojas + dr.hojas;
	info.altura = max(iz.altura, dr.altura) + 1;

	return info;
}


void resuelveCaso() {
	bintree<char> a;
	a = leerArbol('.');
	tInfo info = propiedades(a);
	cout << info.nodos << " " << info.hojas << " " << info.altura << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
