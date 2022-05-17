//Luis Alberto Jaramillo Pulido
//Problema Curva concava
//team:F31
// Coste O(logN) donde N es el tamaño del vector, El coste es logaritmico porque en cada llamda recursiva se divide el tamaño del vector en 2 mitades, y se va descartando una mitad segun se evalua la condición del caso recursivo
//Se ajusta al esquema teórico de disminución del tamaño del problema por división.

#include <iostream>
#include <fstream>
#include <vector>
//#include <climits>
using namespace std;



int curvaConcava(const vector<int>  &v, int i, int j) {
	if (j == i)
		return i;
	if (j == i + 1) {
		if (v[i] < v[j]) 
			return i;
		else
			return j;
	}
	int m = (i + j) / 2;
	if (v[m] <= v[m - 1]) //lado derecho
		return curvaConcava(v, m , j);
	else// lado izquierdo	
		return curvaConcava(v, i, m-1);
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	int pos= curvaConcava(v, 0,N-1);
	cout <<v[pos]<< "\n";
	//cout << pos << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	// Resolvemos
	while (resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
