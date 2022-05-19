#include <iostream>
#include <string>
#include "Supermercado.h";
#include <fstream>
using namespace std;
/*
Tema:11
Problema F04 Supermercado
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

bool resuelveCaso() {
	string cadena, cod_cliente;//
	int num_cola,N;
	cin >> N;
	if (!cin)return false;
	cin >> cadena;
	supermercado super(N);
	while (cadena != "FIN") {
		try {
			if (cadena == "nuevo_cliente") {
				cin >> cod_cliente >> num_cola;
				super.nuevo_cliente(cod_cliente,num_cola);
			}
			else if (cadena == "cambiar_cola") {
				cin >> cod_cliente >> num_cola;
				super.cambiar_cola(cod_cliente,num_cola);
			}
			else if (cadena == "cuantos_en_cola") {
				cin  >> num_cola;
				int numero = super.cuantos_en_cola(num_cola);
				cout << "En la cola " << num_cola << " hay " << numero << " clientes\n";
			}
			else if (cadena == "clientes_en_cola") {
				cin >> num_cola;
				list<string>l= super.clientes_en_cola(num_cola);
				cout << "En la cola " << num_cola << " estan: ";
				for (string x : l)
					cout << x << " ";
				cout << "\n";
			}
			else if (cadena == "consultar_cliente") {
				cin >> cod_cliente;
				int n = super.consultar_cliente(cod_cliente);
				cout << "El cliente " << cod_cliente << " esta en la cola " << n << "\n";
			}
			else
				cout << "Comando Desconocido\n";
			cin >> cadena;
		}
		catch (exception& e) {
			cout << "ERROR: " << e.what() << "\n";
			cin >> cadena;
		}
	}
	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
