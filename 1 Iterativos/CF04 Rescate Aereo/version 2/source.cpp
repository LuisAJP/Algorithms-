//Luis Alberto Jaramillo Pulido
//Problema Rescate Aereo
//team:F31


#include <iostream>
#include <fstream>
#include <vector>
//algorithm 
#include <algorithm>
using namespace std;

typedef struct{
	int ini;
	int fin;
}tInfo;


tInfo rescateAereo(const vector<int> &v, int N,int A){
	tInfo info;
	int maximo = 0, pos = 0, cont = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] > A) {
			if (cont == 0)
				pos = i;
			cont++;
		}
		else
			cont = 0;
		if (cont > maximo) {
			maximo = cont;
			info.ini = pos;
			info.fin = i;
		}
	}
	return info;
}

void resuelveCaso() {
	int N, A;
	tInfo info;
	cin >> N >> A;
	vector<int>v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	info = rescateAereo(v,N,A);
	cout << info.ini << " " << info.fin << "\n";
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N;
	cin >> N;
	// Resolvemos
	for (int i = 0; i < N; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}