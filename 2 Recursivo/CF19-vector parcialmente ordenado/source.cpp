/*
Tema:Recursion
Autor: Luis Alberto Jaramillo Pulido
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

typedef struct{
	int maximo;
	int minimo;
	bool ordenado;
}tInfo;

tInfo ordenado(const vector <int> &v, int i,int j){
	if (j == i + 1){
		if (v[i] <= v[j])
			return{ v[j], v[i], true};
		else
			return{ v[j], v[i], false };
	}
	tInfo iz, dr,r;
	int m = (i+j) / 2;
	iz=ordenado(v,i,m);//iz
	dr=ordenado(v, m+1, j);//dr
	r.minimo = iz.minimo;
	r.maximo = dr.maximo;
	r.ordenado =iz.ordenado && dr.ordenado && dr.maximo >= iz.maximo && iz.minimo <=dr.minimo;

	return r;
}
bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<int> v;

	while (n != 0) {
		v.push_back(n);
		cin >> n;
	}
	if (v.size() == 1) {
		cout << "SI\n";
		return true;
	}
	tInfo info = ordenado(v,0,v.size()-1);
	if (info.ordenado)
		cout << "SI\n";
	else
		cout << "NO\n";

	return true;
}


int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}









