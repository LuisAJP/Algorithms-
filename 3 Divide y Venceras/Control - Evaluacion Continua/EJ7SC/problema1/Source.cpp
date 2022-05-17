/*
Tema:Divide y venceras
Problema Evaluacion continua EJ7SC
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
//a numero de llamadas recursivas, "b" factor de disminucion, "c*nk"
/*
T(n)    =           Co					Si n=0
					T(n/2) + c			Si n>0


//Complejidad: a=1, b=2, k=0, estamos en el caso a = b^k =>O(n^k log n) = O(n^0 log n) = O(log n) 

*/

int resuelve(const vector<int> &v, const vector<int> &w,int i, int j){
	//caso base
	if (i==j){
		return v[j];
	}
	int m = (i+j)/2;
	if (v[m]<w[m])
		resuelve(v,w,i,m);//izquierda
	else
		resuelve(v, w, m+1, j);//derecha

}

int resuelve(vector<int> v, vector<int> w, int N){
	
	int r = resuelve(v, w, 0, N - 1);
	return r;
}


void resuelveCaso(){
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> w(N - 1);
	for (int i = 0; i < N; i++){
		cin >> v[i];
	}

	for (int i = 0; i < N - 1; i++){
		cin >> w[i];
	}
	int r = resuelve(v, w, N);
	cout << r;
	cout << "\n";

}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	//while (resuelveCaso());
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();

	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


