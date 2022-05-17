
/*
Tema:Recursion
MergeSort
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
void mezcla(vector<float> &v, int a, int m, int b);
void mergeSort(vector<float> &v, int n);
void mergeSort(vector<float> &v, int a, int b);

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
	vector<float> v(numElem);
	for (int i = 0; i < numElem; i++){
		cin >> v[i];
	}
	mergeSort(v, v.size());
}

void mergeSort(vector<float> &v, int n) {
	mergeSort(v, 0, n - 1);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void mergeSort(vector<float> &v, int a, int b) {
	int m;
	if (a < b) {
		m = (a + b) / 2;
		mergeSort(v, a, m);
		mergeSort(v, m + 1, b);
		mezcla(v, a, m, b);
	}
}

void mezcla(vector<float> &v, int a, int m, int b) {
	float *u = new float[b - a + 1];
	int i, j, k;
	for (k = a; k <= b; k++)
		u[k - a] = v[k];
	i = 0;
	j = m - a + 1;
	k = a;
	while ((i <= m - a) && (j <= b - a)) {
		if (u[i] <= u[j]){
			v[k] = u[i];
			i = i + 1;
		}
		else {
			v[k] = u[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while (i <= m - a) {
		v[k] = u[i];
		i = i + 1;
		k = k + 1;
	}
	while (j <= b - a) {
		v[k] = u[j];
		j = j + 1;
		k = k + 1;
	}
	delete[] u;
}

