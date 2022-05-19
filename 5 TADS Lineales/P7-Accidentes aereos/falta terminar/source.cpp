/*
Tema:08
Problema Primera Evaluación continua grupo:F, Eliminar los elementos decrecientes de una lista enlazada simple
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "list_eda.h"
using namespace std;


typedef struct{
	string fecha;
	int numero;
}tInfo;

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)return false;
	list<tInfo> l;
	tInfo maximo;
	tInfo ant;
	tInfo info;
	for (int i = 0; i < N; i++){
		cin >> info.fecha >> info.numero;
		l.push_back(info);
	}
	int temp;
	for (int i = 0; i < N; i++){
		
		if (l.front().numero>maximo.numero){
			maximo = l.front();
			cout << "NO HAY\n";
		}
		else{
			if (ant.numero>l.front().numero)
				cout << ant.fecha << "\n";
			else
				cout << maximo.fecha << "\n";
		}
		ant = l.front();
		l.pop_front();
	}
	cout << "---" << "\n";
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
