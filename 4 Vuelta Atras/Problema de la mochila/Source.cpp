/*
Tema:Recursion
Problema CF20
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;




void resuelveCaso();
void inicializar(vector<bool> &solucion);
void inicializar(vector<int> &solucionMejor);
void mochila(const vector<float> &P, const vector<float> &V, vector<bool> &solucion, int k, int n, int m,
	float &peso, float &beneficio, vector <int> &solucionMejor, int &valorMejor);

void copiarSolucion(vector <bool> &solucion, vector <int> &solucionMejor);


int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
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
	int n=0,m=0;
	cin >> n>>m;
	vector<float> P(n);
	vector<float> V(n);
	vector<bool> solucion(n);
	vector<int> solucionMejor(n);
	int valorMejor = 0;
	float peso = 0;
	float beneficio=0;
	for (int i = 0; i < n; i++){
		cin >> P[i];
	}
	for (int i = 0; i < n; i++){
		cin >> V[i];
	}
	inicializar(solucion);
	inicializar(solucionMejor);
	mochila(P,V,solucion,0,n,m,peso,beneficio,solucionMejor,valorMejor);

	for (int i = 0; i < solucionMejor.size();i++){
		if (solucionMejor[i] != -1)
			cout << solucionMejor[i]<<" ";
	}
	cout << "\n";
}
void inicializar(vector<bool> &solucion){

	for (int i = 0; i < solucion.size(); i++){
		solucion[i]=false;
	}
}

void inicializar(vector<int> &solucionMejor){

	for (int i = 0; i < solucionMejor.size(); i++){
		solucionMejor[i] = -1;
	}
}

void mochila(const vector<float> &P, const vector<float> &V, vector<bool> &solucion, int k, int n, int m,
	float &peso, float &beneficio,vector <int> &solucionMejor, int &valorMejor){
	// hijo izquierdo[cogemos el objeto]
	solucion[k] = true;
	peso = peso + P[k];
	beneficio = beneficio + V[k];
	if (peso <= m){
		if (k == n - 1){//si estamos ultimo nivel
			if (valorMejor < beneficio){
				valorMejor = beneficio;
				copiarSolucion(solucion, solucionMejor);
			}
		}
		else
			mochila(P, V, solucion, k + 1, n, m, peso, beneficio,
				solucionMejor, valorMejor);
	}
	peso = peso - P[k]; // desmarcamos peso y b e n e f i c i o
	beneficio = beneficio - V[k];
	//hijo derecho[no cogemos el objeto]
	solucion[k] = false;
	if (k == n - 1){//si estamos ultimo nivel
		if (valorMejor < beneficio){
			valorMejor = beneficio;
			copiarSolucion(solucion, solucionMejor);
		}
	}
	else{
		mochila(P, V, solucion, k + 1, n, m, peso, beneficio,
			solucionMejor, valorMejor);
	}
}


void copiarSolucion(vector <bool> &solucion,vector <int> &solucionMejor){
	for (int i = 0; i < solucion.size(); i++){
		if (solucion[i])
			solucionMejor[i] = i+1;
		else
			solucionMejor[i] = -1;
	}

}