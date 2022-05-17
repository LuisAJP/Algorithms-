#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelve(int num, int acum);
int potencia(int a, int n);
void resuelveCaso();


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

void resuelveCaso() {
	int numero,n;
	bool salir = false;
	do{
		cin >> numero;
		cin >> n;
		if (!cin) salir = true;
		else{

			resuelve(numero, n);
		}
	} while (!salir);
}

void resuelve(int a, int n){
	cout << potencia(a, n) << "\n";
}
int potencia(int a, int n){
	int p;
	if (n == 0)
		p = 1;
	else // n>0
		p = potencia(a, n - 1) * a;
	return p;
}
