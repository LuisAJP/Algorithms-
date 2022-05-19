/*
Tema:Divide y venceras
Problema Evaluacion continua Febrero E2
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

//a numero de llamadas recursivas, "b" factor de disminucion, "c*nk"
/*
T(n)    =           Co					Si n=0
T(n/2) + c			Si n>0


//Complejidad: a=1, b=2, k=0, estamos en el caso a = b^k =>O(n^k log n) = O(n^0 log n) = O(log n)

*/


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int numeroCeros(const vector<int> &v, int i, int j){
	if (i > j) return 0;
	if (i == j) {
		if (v[i] == 0)
			return 1;
		return 0;
	}
	int m = (i + j) / 2;
	if (v[m] == 1) // derecha
		return numeroCeros(v, m + 1, j);
	else //iz si v[m]<=0
		return numeroCeros(v, i, m) + (j - m);
}


int numeroCeros(const vector<int> &v,int N){
	int cont=0;
	return numeroCeros(v,0,N-1);

}
void resuelveCaso(){
	int numElementos = 0;
	int elem;
	cin >> numElementos;
	vector<int> v;
	for (int i = 0; i < numElementos;i++){
		cin >> elem;
		v.push_back(elem);
	}
	int numCeros = numeroCeros(v,numElementos);
	cout << numCeros<<"\n";
}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	//while (resuelveCaso());
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();

	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
