#include <fstream>
#include <iostream>
#include "bintree_eda.h"
using namespace std;

typedef struct {
	int rescate;//grupo rescate
	int atrapados;//grupo atrapados
}tInfo;

tInfo excursionista(const bintree <int> &a){
	if (a.empty())
		return{ 0, 0 };

	tInfo iz = excursionista(a.left());
	tInfo dr = excursionista(a.right());
	tInfo info;
	if (a.root() != 0 && iz.rescate == 0 && dr.rescate == 0){
		info.rescate = 1;//numero equipo rescate
		info.atrapados = a.root();//numero excursionistas atrapados
	}
	else{
		info.rescate = iz.rescate + dr.rescate;//numero equipo rescate
		info.atrapados = a.root() + max(iz.atrapados, dr.atrapados);//numero excursionistas atrapados
	}
		
	return info;
}

void resuelve(){
	bintree <int> a;
	a = leerArbol(-1);
	tInfo info = excursionista(a);
	cout <<info.rescate<<" "<< info.atrapados<<"\n";
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