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



//El coste es O(log2^n) en base 2, la implementacion es mediante un arbol binario
//donde n es el numero de nodos del arbol, es de orden O(log2^n)en base 2 porque 
//tiene que recorrer todos los nodos para encontrar el camino de pares
//con mayor longitud

template<typename T>
tInfo longitudMaxima(bintree<T> const& a) {
	if (a.empty())
		return{ 0,0 };

	tInfo iz = longitudMaxima(a.left());
	tInfo dr = longitudMaxima(a.right());
	
	int maxLongitud = 0;
	int altura = 0;

	if (a.root() % 2 == 0) {
		altura = max(iz.h, dr.h) + 1;//si es par, guardo la altura
		maxLongitud = max((iz.h + dr.h + 1), (max(iz.lm, dr.lm)));//maximo(longitud actual, maximo(longitudMax iz, longitudMax dr))
	}
	else 
		maxLongitud = max(iz.lm, dr.lm);

	return {altura,maxLongitud };
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