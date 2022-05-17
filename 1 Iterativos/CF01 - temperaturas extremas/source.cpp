//NOMBRE y APELLIDOS Luis Alberto Jaramillo Pulido Grupo F


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;




void temperaturasExtremas(vector<int> v, int &nPico, int &nValle){

	int n = v.size() - 1;
	while (n > 1){
		if (v[n]<v[n - 1] && v[n - 1]> v[n - 2])
			nPico++;
		else if (v[n] > v[n - 1] && v[n - 1] < v[n - 2])
			nValle++;
		n--;
	}
	
}

void resuelveCaso() {
	int numElem;
	bool salir = false;
	cin >> numElem;
	vector<int> v(numElem);
	for (int i = 0; i < numElem; ++i)
		cin >> v[i];
	int nPico=0,  nValle = 0;
	temperaturasExtremas(v,nPico,nValle);
	cout << nPico << " " << nValle << "\n";
}

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
