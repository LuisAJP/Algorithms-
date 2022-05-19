/*
Tema:9
Problema 80 Arbol genealogico
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

//Implementacion usando una funcion externa a la clase bintree


#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <iostream>
using namespace std;

typedef struct {
	int h;//altura
	int edad;
	bool posible;
} tInfo;

template<typename T>
tInfo genealogicos(bintree<T> const& a) {
	if (a.empty())
		return{ 0, 0, true };

	tInfo iz, dr, info;
	iz = genealogicos(a.left());
	dr = genealogicos(a.right());
	info = { 0, 0, false };

	//si es hoja
	if (a.left().empty() && a.right().empty())
		return{ 1, a.root(), true };

	int dph = a.root() - max(iz.edad, dr.edad);//diferencia edad padre e hijos
	int dh = iz.edad - dr.edad;//diferencia edad entre hermanos

	if (iz.posible && dr.posible){
		if (!a.left().empty() && !a.right().empty()){//Hay hijo iz e hijo dr
			//diferencia edad padre e hijos >= 18 y  diferencia edad entre hermanos >=2
			if (dph >= 18 && dh >= 2)
				info = { max(iz.h, dr.h) + 1, a.root(),true};//altura,edad,posible
			else
				info.posible = false;
		}
		else if (a.right().empty()){//si no hay hijo dr 
			//diferencia edad padre e hijo iz>=18
			if (dph >= 18)
				info = { max(iz.h, dr.h) + 1, a.root(), true };//altura,edad,posible
			else
				info.posible = false;
		}
		else if (a.left().empty() && !a.right().empty())//si no hay hijo iz y si hijo dr
			info.posible = false;
	}
	return info;
}

// resuelve un caso de prueba
void resuelveCaso() {
	bintree<int> arbol;
	arbol = leerArbol(-1);
	tInfo info = genealogicos(arbol);
	if (info.posible)
		cout << "SI" << " " << info.h << "\n";
	else
		cout << "NO\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}