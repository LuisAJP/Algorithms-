/*
Tema:Recursion
Problema CF17
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool resuelveCaso();
int minimo(const vector<int> &v, int n);
int minimo(const vector<int> &v, int i, int j);

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


bool resuelveCaso(){
	int numElem;
	cin >> numElem;
	if (!cin)
		return false;
	else {
		vector<int> v(numElem);
		for (int i = 0; i < numElem; i++){
			cin >> v[i];
		}
		cout << minimo(v,v.size()) << "\n";
		return true;
	}
}

int minimo(const vector<int> &v, int n){

	return minimo(v,n-2,n-1);
}


int minimo(const vector<int> &v,int i, int j){
	int r = 0;
	if (i<0)
		r = v[j];
	else{
		if (v[j] < v[i]){
			r = minimo(v, i - 1, j);
		}
		else
			r = minimo(v,i-1,i);
	}
	return r;
}



