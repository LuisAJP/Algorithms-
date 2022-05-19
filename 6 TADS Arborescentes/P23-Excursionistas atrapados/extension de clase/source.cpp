/*
Tema:09
Problema 23 Excursionistas atrapados
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct tInfo{
	int eq;
	int ex;

};

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
	
	tInfo rescate(){
		return rescate(this->raiz);
	}

private:
	
	tInfo rescate(Link r){
		if (r == nullptr)
			return{0,0};

		tInfo iz, dr;
		iz=rescate(r->left);
		dr=rescate(r->right);
		
		if (iz.eq == 0 && dr.eq == 0 && r->elem != 0)
			return {1,r->elem};

		int equipo = iz.eq + dr.eq;
		int atrapados = r->elem + max(iz.ex, dr.ex);
		return{equipo,atrapados};
		
	}
};

template <typename T>
bintree_ext<T> leerArbolext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolext(vacio);
		auto dr = leerArbolext(vacio);
		return{ iz, raiz, dr };
	}
}

void resuelveCaso() {
	bintree_ext<int> arbol;
	arbol = leerArbolext(-1);
	int n = 0, m = 0;
	tInfo info=arbol.rescate();
	cout << info.eq << " " << info.ex << "\n";
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
