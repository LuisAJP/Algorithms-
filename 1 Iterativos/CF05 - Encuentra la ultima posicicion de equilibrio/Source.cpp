/*
Tema:Recursion
Problema CF05
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;




void resuelveCaso();
int resuelve(const vector<int>& v);

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++){
		resuelveCaso();
	
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


void resuelveCaso(){
	int numElems;
	cin >> numElems;
	int a;
	vector<int>v(numElems);
	for (int i = 0; i < v.size();i++){
		cin >> v[i];
	}

	int p = resuelve(v);
	cout << p;
	cout << "\n";
}

int resuelve(const vector<int>& v){

	int p = -1;
	int cero=0, uno = 0;
	int i = 0;

	while (i < v.size()){
		if (v.at(i) == 0) 
			cero++;
		if (v.at(i) == 1) 
			uno++;
		if (cero == uno) 
			p = i;
		i++;

	}
	return p;
}