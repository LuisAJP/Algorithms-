/*
Tema:9
Problema 87 Camino de pares
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
	int lm;// longitud maxima del camino
} tInfo;

//El coste es O(log 2^n) es igual a O(n), la implementacion 
//es mediante un arbol binario donde n es el numero de nodos 
//del arbol, es de orden O(n) porque  tiene que recorrer todos 
//los nodos para encontrar el camino de pares con mayor longitud
template<typename T>
tInfo longitudMaxima(bintree<T> const& a) {
	if (a.empty())
		return{ 0, 0 };

	tInfo iz, dr, info;
	iz = longitudMaxima(a.left());
	dr = longitudMaxima(a.right());
	info = {0,0};
	if (a.root() % 2 == 0) {//si es par
		info.h = max(iz.h, dr.h) + 1;// guardo la altura si es par
		info.lm = (iz.h + dr.h + 1);//calculo diametro si es par
	}
	//guardo la lm maxima, comparando con lm actual
	//con las anteriores(iz.lm y la dr.lm)
	info.lm = max(info.lm,max(iz.lm, dr.lm));
	return info;
}

// resuelve un caso de prueba
void resuelveCaso() {
	bintree<int> arbol;
	arbol = leerArbol(-1);
	tInfo info = longitudMaxima(arbol);
	cout << info.lm << "\n";
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