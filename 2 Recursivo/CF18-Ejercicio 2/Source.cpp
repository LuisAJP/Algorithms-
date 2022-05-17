/*
Tema:Recursion
Problema CF18
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/
/*
El coste es O(N) donde N es el tamaño del vector, el coste es lineal en el caso peor porque tendria que recorrer todo el vector si el elemento impar es el primer elemento. 
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool resuelveCaso();
int impar(const vector<int> &v, int n);
int impar(const vector<int> &v, int i, int j);

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
	if (numElem==0)
		return false;
	else {
		vector<int> v(numElem);
		for (int i = 0; i < numElem; i++){
			cin >> v[i];
		}
		cout << impar(v,v.size()-1) << "\n";
		return true;
	}
}

int impar(const vector<int> &v, int i){
	int r = 0;
	if (v[i] % 2 == 1){
		r = v[i];
	}
	else{
		r = impar(v, i - 1);
	}
	return r;
}




