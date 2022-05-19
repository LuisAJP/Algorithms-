/*
Tema:11
Problema 34 Carnet por puntos 2
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "carnet_puntos.h"
using namespace std;


bool resuelveCaso() {
	string cadena, dni;
	int puntos;
	cin >> cadena;
	if (!cin) return false;
	carnet_puntos carnet;
	while (cadena != "FIN") {
		try {
			if (cadena == "nuevo") {
				cin >> dni;
				carnet.nuevo(dni);
			}
			else if (cadena == "consultar") {
				cin >> dni;
				puntos = carnet.consultar(dni);
				cout << "Puntos de " << dni << ": " << puntos << '\n';
			}
			
			else if (cadena == "quitar") {
				cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}

			else if (cadena == "cuantos_con_puntos") {
				cin >> puntos;
				int n = carnet.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << n << '\n';
			}

			else if (cadena == "recuperar") {
				cin >> dni >> puntos;
				carnet.recuperar(dni, puntos);
			}

			else if (cadena == "lista_por_puntos") {
				cin >> puntos;
				list<string> l = carnet.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos:";
				for (auto dni : l)
					cout << ' ' << dni;
				cout << '\n';
			}

		}
		catch (domain_error e) {
			cout << "ERROR: " << e.what() << '\n';
		}
		cin >> cadena;
	}
	cout << "---\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ifstream in("casos.txt");
	auto cinbuf =cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}