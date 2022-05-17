
/*
Tema:Recursion
Problema metodo de producto campesino ruso o egipcio??
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
int prod(int a, int b);

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
	cout << prod(a,b)<<"\n";
}



int prod(int a, int b) {
	int r;
	//_Caso base
	if (b == 0)
		r = 0;
	//Caso Base
	 if (b == 1)
		r = a;
	else {// b > 1
		if (b % 2 == 0)   //b es par
			r = prod(2 * a, b / 2);
		else  // ( b % 2 == 1)  b es impar
			r = prod(2 * a, b / 2) + a;
	}
	return r;
}



