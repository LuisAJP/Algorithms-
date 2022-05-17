/*
Tema:Recursion
Problema Quicksort
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();

void quickSort(vector<float> &v, int a, int b);
void quickSort(vector<float> &v, int n);
void particion(vector<float> &v, int a, int b, int & p);


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
	for (int i = 0; i < numElem;i++){
		cin >> v[i];
	}
	quickSort(v,v.size());
}

void quickSort(vector<float> &v, int n) {
	quickSort(v, 0, n-1 );
	for (int i = 0; i < v.size(); i++) {
		cout<< v[i]<<" ";
	}
	cout << "\n";
}

//Procedimiento auxiliar con los parametros a y b
void quickSort(vector<float> &v, int a, int b) {
	int p=0;
	if (a <= b) {
		particion(v, a, b, p);
		quickSort(v, a, p - 1);
		quickSort(v, p + 1, b);
	}
}

void particion(vector<float> &v, int a, int b, int & p) {
	int i, j;
	float aux;
	i = a + 1;
	j = b;
	while (i <= j) {
		if ((v[i] > v[a]) && (v[j] < v[a])) {
			aux = v[i]; 
			v[i] = v[j];
			v[j] = aux;
			i = i + 1; 
			j = j - 1;
		}
		else {
			if (v[i] <= v[a]) 
				i = i + 1;
			if (v[j] >= v[a]) 
				j = j - 1;
		}
	}
	p = j;
	aux = v[a];
	v[a] = v[p]; 
	v[p] = aux;
}







