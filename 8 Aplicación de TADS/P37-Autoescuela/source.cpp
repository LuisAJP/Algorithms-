#include <iostream>
#include <fstream>
#include <string>
#include "Autoescuela.h"
using namespace std;

bool resuelveCaso() {

	string comando;
	cin >> comando;

	if (!cin)return false;

	Autoescuela autoescuela;
	string alumno, profesor;
	
	while (comando != "FIN") {
		try {
			if (comando == "alta") {
				cin >> alumno >> profesor;
				autoescuela.alta(alumno, profesor);
			}
			else if (comando == "es_alumno") {
				cin >> alumno >> profesor;
				bool es_alumno = autoescuela.es_alumno(alumno, profesor);
				cout << alumno << (es_alumno ? " es alumno de " : " no es alumno de ") << profesor << "\n";
			}
			else if (comando == "puntuacion") {
				cin >> alumno;
				int punt = autoescuela.puntuacion(alumno);
				cout << "Puntuacion de " << alumno << ": " << punt << "\n";
			}
			else if (comando == "actualizar") {
				int puntos;
				cin >> alumno >> puntos;
				autoescuela.actualizar(alumno, puntos);
			}
			else if (comando == "examen") {
				int puntos;
				cin >> profesor >> puntos;
				vector<string> alumnos = autoescuela.examen(profesor, puntos);
				cout << "Alumnos de " << profesor << " a examen:\n";
				for (const string &s : alumnos) {
					cout << s << "\n";
				}
			}
			else if (comando == "aprobar") {
				cin >> alumno;
				autoescuela.aprobar(alumno);
			}
		}
		catch (exception &e) {
			cout << "ERROR\n";
		}
		cin >> comando;
	}

	cout << "---\n";

	return true;}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

}
