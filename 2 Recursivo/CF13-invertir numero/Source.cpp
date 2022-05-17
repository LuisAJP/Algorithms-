

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
Tema:Recursion
Problema CF13
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

/*El coste es O(logN) donde N es el numero a invertir, el coste es logaritmico porque en cada llamada recursiva se va dividiendo el numero entre 10 hasta llegar a 0 (Caso base)*/

void resuelve(int num, int acum);
int invertir(int num, int acum);
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
	int numero;
	bool salir = false;
	do{
		cin >> numero;
		if (!cin) salir = true;
		else{
			
			resuelve(numero,0);
		}
	} while (!salir);
}

void resuelve(int num, int acum){
	cout << invertir(num, acum) << "\n";
}
int invertir(int num, int acum){
	int r=0;
	if (num == 0){
		r = acum;
	}
	else
		r = invertir(num / 10, acum * 10 + (num % 10));
	return r;
}





