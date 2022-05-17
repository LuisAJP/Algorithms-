
/*
Tema:Recursion
maximo comun divisor
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
int fib(int n);

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++){
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


void resuelveCaso(){
	int n;
	cin >> n;
	cout << fib(n)<<"\n";
}



int fib(int n) {
	int r;
	if (n == 0) 
		r = 0;

	else if (n == 1)
		r = 1;

	else{
		r = fib(n - 1) + fib(n-2);
	}

	return r;
}



