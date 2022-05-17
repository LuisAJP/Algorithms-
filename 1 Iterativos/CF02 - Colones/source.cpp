//NOMBRE y APELLIDOS Luis Alberto Jaramillo Pulido Grupo F



#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelve(vector<int>  v);
void resuelveCaso();

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


int colones(const vector<int> &v){
	int cont = 0;
	int i = v.size() - 2;
	int j = v.size() - 1;
	while (i >= 0) {
		if (v[i] < v[j]) 
			j = i;
		else  
			cont++;
		i--;
	}
	return cont;
}

void resuelveCaso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	int numColones=colones(v);
	cout << numColones << "\n";
}



