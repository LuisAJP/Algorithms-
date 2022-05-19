
/*
Tema:9
Problema 86 Perfil izquierdo de un arbol binario
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/


#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "bintree_eda.h"
#include <iostream>
#include <sstream>
using namespace std;

vector<int> &leftShapeG(const bintree<int> &a, const int level, vector<int> &sol, int &maxlevel) {
	if (a.empty())
		return sol;
	if (level > maxlevel)
		sol.push_back(a.root());
	maxlevel = max(maxlevel, level);

	leftShapeG(a.left(), level + 1, sol, maxlevel);
	leftShapeG(a.right(), level + 1, sol, maxlevel);
	return sol;
}


void resuelveCaso() {
	bintree<int>a;
	vector<int> sol;
	a = leerArbol(-1);
	
	int maxLevel = 0;
	sol=leftShapeG(a, 1, sol, maxLevel);

	for (int x : sol)
		cout << x << " ";
	cout << "\n";

}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}
