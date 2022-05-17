
/*
Tema:Recursion
Problema CF14
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
int menor(vector<int> v, int fin, int pos);


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
	int numElem;
	cin >> numElem;
	vector<int> v(numElem);
	for (int i = 0; i < numElem;i++){
		cin >> v[i];
	}
	cout << menor(v, numElem - 2, numElem - 1) << endl;
}

int menor(vector<int> v, int fin, int pos){
	int r;

	if (fin < 0)
		r = v[pos];
	else
	if (v[fin] < v[pos]) // para hacer el mayor cambiar por '>'
		r = menor(v, fin - 1, fin);
	else
		r = menor(v, fin - 1, pos);

	return r;
}


