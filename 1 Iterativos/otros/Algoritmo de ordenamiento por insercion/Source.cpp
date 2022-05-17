//NOMBRE y APELLIDOS Luis Alberto Jaramillo Pulido Grupo F


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void ordenarIns(vector<int>  &v, int n);
void resuelveCaso();

void resuelveCaso();
void ordenarIns(vector<int>  &v, int n);

int main() {
	// Para la entrada por fichero.
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

void resuelveCaso() {
	int numElem;
	cin >> numElem;
	vector<int> v(numElem);
	for (int i = 0; i < numElem; ++i)
		cin >> v[i];
	ordenarIns(v, numElem);
	for (int i = 0; i < numElem; ++i)
		cout<< v[i]<<" ";
	cout << "\n";
}


//ordena un vector de menor a mayor
void ordenarIns(vector<int>  &v, int n){
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = v[i];
		j = i - 1;
		while ((j >= 0) && (v[j] > x)){
			v[j + 1] = v[j];
			j = j - 1;
		}
		 v[j + 1] = x;
	}
}



