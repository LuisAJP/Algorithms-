//NOMBRE y APELLIDOS Luis Alberto Jaramillo Pulido Grupo F


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int seleccion2(vector<int> &v, int a, int b, int k);
void particion2(vector<int> &v, int a, int b, int pivote, int& p, int& q);
void ordenarInsercion(vector<int>  &v, int a, int n);
void resuelveCaso();

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

	cout<<seleccion2(v, 0, v.size() - 1, 0);
	cout<< "\n";
}

int seleccion2(vector<int> &v, int a, int b, int k){
	int l, p, q, s, pm, t;
	int aux, mm;
	t = b - a + 1;
	if (t <= 12){
		ordenarInsercion(v, a, b);
		return v[k];
	}
	else
	{
		s = t / 5;
		for (l = 1; l <= s; l++){
			ordenarInsercion(v, a + 5 * (l - 1), a + 5 * l - 1);
			pm = a + 5 * (l - 1) + (5 / 2);
			aux = v[a + l - 1];
			v[a + l - 1] = v[pm];
			v[pm] = aux;
		}
		mm = seleccion2(v, a, a + s - 1, a + (s - 1) / 2);
		particion2(v, a, b, mm, p, q);
		if ((k >= p) && (k <= q))  
			return mm;
		else if (k<p) 
			return seleccion2(v, a, p - 1, k);
		else 
			return seleccion2(v, q + 1, b, k);
	}
}

void particion2(vector<int> &v, int a, int b, int pivote, int& p, int& q){
	int k;
	int aux;
	p = a; k = a; q = b;
	while (k <= q)
	{
		if (v[k] == pivote) { k = k + 1; }
		else if (v[k] < pivote)
		{
			aux = v[p]; v[p] = v[k]; v[k] = aux;
			p = p + 1; k = k + 1;
		}
		else {
			aux = v[q]; v[q] = v[k]; v[k] = aux;
			q = q - 1;
		}
	}
}

void ordenarInsercion(vector<int>  &v,int a, int n){
	int i, j, x;
	for (i = a; i < n; i++) {
		x = v[i];
		j = i - 1;
		while ((j >= 0) && (v[j] > x)){
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = x;
	}
}
