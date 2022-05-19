//Ejercicio 39
//Mauricio Abbati Loureiro - EDA 2ยบE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include "Amazon.h"
using namespace std;

bool resuelveCaso() {

	Amazon miAmazon;

	int n, f;
	std::cin >> n;
	if (!std::cin) return false;
	std::string orden;
	string l;

	for (int i = 0; i < n; ++i) {
		try {
			std::cin >> orden;
			if (orden == "nuevoLibro") {
				std::cin >> f;
				std::cin.ignore();
				getline(std::cin, l);
				miAmazon.nuevoLibro(f, l);
			}
			else if (orden == "comprar") {
				std::cin.ignore();
				getline(std::cin, l);
				miAmazon.comprar(l);
			}
			else if (orden == "estaLibro") {
				std::cin.ignore();
				getline(std::cin, l);
				if (miAmazon.estaLibro(l)) std::cout << "El libro " << l << " esta en el sistema\n";
				else  std::cout << "No existe el libro " << l << " en el sistema\n";
	
			}
			else if (orden == "numEjemplares") {
				std::cin.ignore();
				getline(std::cin, l);
				try {
					int p = miAmazon.numEjemplares(l);
					std::cout << "Existen " << p << " ejemplares del libro " << l << "\n";
				}
				catch (std::exception){
					std::cout << "No existe el libro " << l << " en el sistema\n";
				}
			
			}
			else if (orden == "elimLibro"){
				std::cin.ignore();
				getline(std::cin, l);
				miAmazon.elimLibro(l);
			}
			else if (orden == "top10"){
				std::cout << "TOP10"<< "\n";
				std::list<string> sol = miAmazon.top10();
				for (auto const & lib : sol)
					std::cout << "    "<<lib << "\n";
			}
		}
		catch (std::exception &e) {
			std::cout << e.what() << "\n";

		}
	}
	std::cout << "---\n";

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
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
