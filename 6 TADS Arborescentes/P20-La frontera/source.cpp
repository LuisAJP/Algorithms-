
/*
Tema:9
Problema 20 la frontera
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

template <typename T>
void frontera(vector<T> &v, bintree<T> const& a){
	if (a.empty()) 
		return;
	frontera(v,a.left());
	frontera(v, a.right());
	if (a.left().empty() && a.right().empty())
		v.push_back(a.root());
	return;
}

// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol(-1);
	vector<int> v;
	frontera(v, arbol);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

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
