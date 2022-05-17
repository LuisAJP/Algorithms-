/*
Tema:Recursion
Autor: Luis Alberto Jaramillo Pulido
Problema:CF15
team: F59

Coste de algoritmo lineal
t(n) pertenece O(n),no hay caso mejor ni caso peor, porque tiene que recorrer todos los elementos del vector e ir comparando para saber si es la letra esperada.
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
	cin>>a>>b;
	cin.get(elem);
	vector<char>v;
	do{
		cin.get(elem);
		if (elem !='\n' && elem != ' '){
			v.push_back(elem);
		}
	} while (elem != '\n');
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






