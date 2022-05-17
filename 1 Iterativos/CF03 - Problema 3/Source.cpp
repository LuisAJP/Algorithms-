//Luis Alberto Jaramillo Pulido
//Problema Problema 3
//team:F59


#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

void resuelve(vector<int>  v,int p);
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


void resuelve(vector<int>  v, int p){
	int N = v.size();
	int maxIzq = INT_MIN;
	int minDr = INT_MAX;

	for (int i = 0; i < N;i++){
		if (i<=p){
			if (v[i]>maxIzq)
				maxIzq = v[i];
		}
		else{
			if (v[i]<minDr)
				minDr = v[i];
		}
	}
	if (maxIzq < minDr) cout << "SI" << "\n";
	else cout << "NO" << "\n";
	
}

void resuelveCaso() {
	int numElem;
	int p;
	bool salir = false;
	cin >> numElem>>p;
	vector<int> v(numElem);
	for (int i = 0; i < numElem; ++i)
		cin >> v[i];
	resuelve(v,p);	
}
