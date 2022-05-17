/*
Tema:Recursion
Autor: Luis Alberto Jaramillo Pulido
Problema:CF15
team: F59

Coste de algoritmo lineal
t(n) pertenece O(N),donde N es el tamaño del vector, el coste es lineal en el caso peor porque tendria que recorrer todos los elementos del vector hasta el final, mientras que en el caso mejor es constante solo bastaria
con comprobar el ultimo elemento, el vector se recorre de derecha a izquierda
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;
void resuelveCaso();

char fuga(const vector <char> &v, char a, char b, int n);

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
	char a, b,elem;
	int numElem;
	cin>>a>>b;
	numElem = int(b) - int(a);
	vector<char>v(numElem);
	
	for (int i = 0; i < numElem;i++){
		cin >> v[i];
	}
	cout << fuga(v,a,b,v.size()-1) << "\n";
}



char fuga(const vector <char> &v, char a,char b, int n) {
	char r=' ';
	//Caso base 
	if (v[v.size()-1] != b)//si el ultimo elemento es distinto de b, entonces es la letra que falta
		r = b;
	//Caso base 
	else if (n == 0){//si el primer elemento es distinto de a, entonces es la letra que falta
		if (v[n] != a)
			r = a;
	}
	else  {
		//se calcula la letra que deberia seguir, si es distinto que la letra esperada entonces es la letra que falta
		if (int(v[n] - 1) != int(v[n - 1])){
			int x = int(v[n] - 1);
			r = char(x);
		}
		else
			r = fuga(v,a,b,n-1);
	}
	return r;
}






