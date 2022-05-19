#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "treemap_eda.h"
#include "hashmap_eda.h"
using namespace std;
/*
Tema:10
Problema 93 Renum
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/
struct tInfo {
	string comando;
	int salto;
};

void resuelve() {
	int n;//numero de linea
	cin >> n;

	map<int, tInfo> tmap;//numLinea e info
	unordered_map<int, int> hmap;//numLinea y numLinea(Basic) 
	int cont = 10;
	
	while (n != 0) {
		tInfo info;
		cin >> info.comando;

		if (info.comando == "GOTO" || info.comando == "GOSUB") 
			cin >> info.salto;
		
		tmap[n] = info;
		hmap[n] = cont;

		cont += 10;
		cin >> n;
	}

	for (auto x : tmap) {   
		cout << hmap[x.clave] << " " << x.valor.comando;

		if (x.valor.comando == "GOTO" || x.valor.comando == "GOSUB") 
			cout << " " << hmap[x.valor.salto];

		cout << "\n";
	}
		cout << "---" << "\n";
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelve();
	
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
