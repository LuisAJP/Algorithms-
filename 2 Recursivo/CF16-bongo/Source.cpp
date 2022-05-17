/*
Tema:Recursion
Problema CF16
Autor: Luis Alberto Jaramillo Pulido
team: F59
 Coste O(logN) donde N es el tamaño del vector, El coste es logaritmico porque en cada llamda recursiva se divide el tamaño del vector en 2 mitades, y se va descartando una mitad segun se evalua la condición del caso recursivo
//Se ajusta al esquema teórico de disminución del tamaño del problema por división.
*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
int bongo(const vector<int> &v, int num, int n);
int bongo(const vector<int> &v, int num, int i, int j);


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
	int numero;
	cin >> numElem>>numero;
	vector<int> v(numElem);
	for (int i = 0; i < numElem;i++){
		cin >> v[i];
	}
	
	if (bongo(v, numero, v.size())==-1)
		cout << "NO"<<"\n";
	else
		cout << bongo(v, numero, v.size()) << "\n";
}


int bongo(const vector<int> &v, int num, int n){
	return bongo(v,num,0,n);
}


int bongo(const vector<int> &v, int num, int i, int j){
	int r = 0;
	int m = (i + j )/ 2;
	if (j <= i + 1){
		if (m + num == v[m]){
			r = v[m];
		}
		else
			r = -1;
	}
	else{
		if (m+num >=v[m]){//lado derecho
			r = bongo(v,num,m,j);
		
		}
		else //lado izquierdo
			r = bongo(v, num, i, m);
	}
	return r;
}



