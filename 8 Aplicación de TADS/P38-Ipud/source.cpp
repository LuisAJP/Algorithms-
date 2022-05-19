#include <iostream>
#include <string>
#include "Ipud.h"
#include <fstream>
using namespace std;

/*
Tema:11
Problema 38 Ipud
Autor: Luis Alberto Jaramillo Pulido
team:F33
*/

bool resuelveCaso() {
	iPud ipud;
	string cadena, C, A;//cadena,cancion,artista
	int D;//duracion
	cin >> cadena;
	if (!cin)return false;
	while (cadena != "FIN") {
		try {
			if (cadena == "addSong") {
				cin >> C >> A >> D;
				ipud.addSong(C, A, D);
			}
			else if (cadena == "addToPlaylist") {
				cin >> C;
				ipud.addToPlaylist(C);
			}
			else if (cadena == "current")
				ipud.current();

			else if (cadena == "play") {
				string C = ipud.play();
				if (C != "")
					cout << "Sonando " << C << "\n";
				else
					cout << "No hay canciones en la lista\n";
			}
			else if (cadena == "totalTime")
				cout << "Tiempo total " << ipud.totalTime() << "\n";

			else if (cadena == "recent") {
				int N = 0;
				cin >> N;
				list<string> lista = ipud.recent(N);
				if (lista.empty())
					cout << "No hay canciones recientes\n";
				else{
					cout << "Las " << lista.size() << " mas recientes\n";
 					for (string C : lista)
						cout << "    " << C << "\n";
				}
			}
			else if (cadena == "deleteSong") {
				cin >> C;
				ipud.deleteSong(C);
			}
			else
				cout << "Comando Desconocido\n";
			cin >> cadena;
		}
		catch (exception& e) {
			cout << "ERROR " << e.what() << "\n";
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
