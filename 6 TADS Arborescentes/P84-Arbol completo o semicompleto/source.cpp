/*
Tema:9
Problema 84 Arbol Binario Completo o semicompleto
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/




#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <iostream>
using namespace std;
struct tInfo{
	int h;
	int esCompleto;//tipo de arbol completo 
};

tInfo semiComplete(const bintree<char> &a){
	if (a.empty())
		return{ 0, 0 };

	tInfo iz, dr, info;
	iz = semiComplete(a.left());
	dr = semiComplete(a.right());

	info = { 0, 0 };
	info.h = max(iz.h, dr.h) + 1;//altura
	
	//es hoja es completo
	if (a.left().empty() && a.right().empty()){
		info.esCompleto = 0;//completo
		return info;
	}

	//iz completo y dr completo y alturas iguales, es arbol completo
	if ((iz.esCompleto == 0) && (dr.esCompleto == 0) && (iz.h == dr.h))
		info.esCompleto = 0;

	//iz completo y dr semicompleto y alturas distintas, es arbol semicompleto
	else if ((iz.esCompleto == 0) && (dr.esCompleto == 1) && (iz.h == dr.h))
		info.esCompleto = 1;

	//iz completo y dr completo y alturas distintas, es arbol semicompleto
	else if ((iz.esCompleto == 0) && (dr.esCompleto == 0) && (iz.h == dr.h + 1))
		info.esCompleto = 1;

	//iz semicompleto y dr completo y alturas distintas, es arbol semicompleto
	else if ((iz.esCompleto == 1) && (dr.esCompleto == 0) && (iz.h == dr.h + 1))
		info.esCompleto = 1;

	else//es arbol es nada, ni completo ni semicompleto
		info.esCompleto = 2;

	return info;
}


void resuelveCaso() {
	bintree<char> a;
	int h;
	a = leerArbol('.');
	switch (semiComplete(a).esCompleto){
	case 0: cout << "COMPLETO\n";
		break;
	case 1: cout << "SEMICOMPLETO\n";
		break;
	case 2: cout << "NADA\n";
		break;
	}
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