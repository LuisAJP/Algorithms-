#include <iostream>
#include "list_eda.h"
#include <string>
#include <fstream>
#include "hashmap_eda.h"
using namespace std;

/*
Tema:10
Problema 90 Eliminar redundancia
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

//El coste es de orden O(M) donde M es el numero de elementos no repetidos, 
//el coste  tanto del insert,push y count es O(1)
bool resuelveCaso() {
	list<int> lista;
	int N = 0,c;

	unordered_map<int, int>  mapa;
	cin >> N;
	if (!cin) return false;
	for (int i = 0;i < N;i++) {
		cin >> c;
		if (mapa.count(c) == 0) {
			mapa.insert({ c,1});
			lista.push_back(c);
		}
		else 
			mapa[c]++;
	}

	for (auto& n : lista)
		cout << n<<" "<<mapa[n]<<"\n";
		
	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
