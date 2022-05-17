#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;
//using namespace std;

/*
Tema:3
Problema Lucesde Navidad
Autor: Luis Alberto Jaramillo Pulido
team: EDA
*/

//El coste de la funcion esValida es de orden O(1), el coste es constante
bool esValida(vector<int>&sol, vector<int>&colores, int k, int total, int capacidad, int C){
	if (k == 0)
		return true;
	//Me aseguro que haya 3 selecciones como minimo (k>1)
	//y compruebo que no haya mas de 2 luces seguidas
	if (k>1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2])
		return false;
	
	int resto = total - colores[sol[k]];
	//Unicamente compruebo que el numero de luces de la luz actual con la suma del resto numero de luces, no supere en mas de 1
	//pero puede ocurrir que el numero de luces de una luz anterior sea menor (por mas de 2) que la suma del resto de numero de luces
	//vease el 4 caso, en la solucion 1 0 1 2 1
	if (colores[sol[k]] - resto<= 1 && capacidad <=C) 
		return true;
	return false;
}


void lucesNavidad(const vector<int> &v, vector<int>&sol,int k, int n, int L, int C,
vector<int>&colores, int consumo, int total, int &combinaciones){

	for (int i = 0; i<n; i++){//numero de luces para seleccionar
		sol[k] = i;//luz seleccionada
		consumo += v[i];
		colores[i]++;
		total++;
		if (esValida(sol, colores,k,total,consumo,C)){
			if (k == L - 1)
				combinaciones++;
			else//Caso recursivo
				lucesNavidad(v,sol,k+1,n,L,C,colores,consumo,total,combinaciones);
		}
		consumo -= v[i];
		colores[i]--;
		total--;
	}
}

bool resuelveCaso() {
	int N, L, C;
	cin >> L >> N >> C;
	if (!cin)
		return false;
	vector<int> v(N);//vector que almacena numero colores
	for (int i = 0; i < N; ++i) 
		cin >> v[i];
	vector<int>sol(L, -1);
	vector<int>colores(L,0);
	int consumo=0,combinaciones=0,total=0;
	lucesNavidad(v, sol, 0, N,L,C,colores,consumo,total,combinaciones);
	cout << combinaciones << "\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
