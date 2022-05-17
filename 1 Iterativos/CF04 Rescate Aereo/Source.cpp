//Luis Alberto Jaramillo Pulido
//Problema Rescate Aereo
//team:F59


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelve(vector<int>  v);
void resuelveCaso();

typedef struct {
	int ini;
	int fin;
	int cont;

}tSecuencia;

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
	tSecuencia s;

	s.ini = 0;
	s.fin = 0;
	s.cont = - 1;

	int ini = 0;
	for (int fin = 0; fin < v.size(); fin++) {
		if (v[fin] <= p) {
			ini = fin + 1;
		}
		else if ((fin - ini) > s.cont) {
			s.cont = fin - ini;
			s.ini = ini;
			s.fin = fin;
		}
	}

	cout << s.ini << " " << s.fin << "\n";
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
