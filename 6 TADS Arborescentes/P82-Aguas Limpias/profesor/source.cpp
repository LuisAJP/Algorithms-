#include <fstream>
#include <iostream>
#include "bintree_eda.h"
using namespace std;

struct tInfo{
	int caudal;//capacidad de absorver 
	int cont;//
};

tInfo aguasLimpias(const bintree <int> &a){
	if (a.empty())
		return{0,0};

	tInfo iz, dr, info;
	iz = aguasLimpias(a.left());
	dr = aguasLimpias(a.right());

	info.caudal = max(dr.caudal + iz.caudal - a.root(), (a.left().empty() && a.right().empty()) ? 1 : 0);
	info.cont = iz.cont + dr.cont + (iz.caudal >= 3) + (dr.caudal >= 3);
	
	return info;
}

void resuelve(){
	bintree <int> a;
	a = leerArbol(-1);
	
	tInfo info = aguasLimpias(a);
	cout << info.cont<<"\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num_casos;
	std::cin >> num_casos;

	for (int i = 0; i < num_casos; i++) {
		resuelve();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// Descomentar si se trabaja en Windows
	system("PAUSE");
#endif
	return 0;
}

// SALT: 39318056200257442788