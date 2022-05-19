/*
Tema:9
Problema 17 Altura de un arbolAutor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
#include <iostream>
using namespace std;


int altura(int nivel){
	int numHijos;
	cin >> numHijos;
	if (numHijos == 0){
		return 1;
	}
	else{
		int maxLocal = 0;
		for (int i = 0; i < numHijos; i++){
			int altLocal = altura(nivel + 1);
			maxLocal = max(altLocal, maxLocal);
		}
		return maxLocal + 1;
	}
}

void resuelveCaso() {
	cout<< altura(0)<<"\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++){
		resuelveCaso();
	}
		
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
