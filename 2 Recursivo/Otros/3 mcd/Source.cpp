
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
int mcd(int a, int b);

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
	int a, b;
	cin >> a >> b;
	cout << mcd(a,b)<<"\n";
}



int mcd(int a, int b) {
	int m;
	//Caso base
	if (a == b)
		m = a;
	else{
		if (a > b)
			m = mcd(a - b, b);
		else // a < b
			m = mcd(a, b - a);
	}
	return m;
}



