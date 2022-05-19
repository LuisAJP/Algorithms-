
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




bool simetrico(const bintree<char> &iz, const bintree<char> &dr){
	if (iz.empty() && dr.empty())//Si es hoja
		return true;//simetrico
	if (!iz.empty() && dr.empty())//solo iz
		return false;
	if (iz.empty() && !dr.empty())//solo dr
		return false;

	bool a = simetrico(iz.left(), dr.right());
	bool b = simetrico(iz.right(), dr.left());
	return (a && b);
}

bool symTree(const bintree<char> &a){
	if (a.empty())
		return true;
	return simetrico(a.left(), a.right());
}

// resuelve un caso de prueba
void resuelveCaso() {
	bintree<char> a;
	a = leerArbol('.');
	cout << (symTree(a) ? "SI" : "NO") << endl;
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
