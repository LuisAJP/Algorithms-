/*
Tema:Iterativos
Problema CF10
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;
bool resuelveCaso();


// COSTE O(n) donde n son los elementos del vector v

typedef struct {
	int racha;
	int repite;
	int jugados;

}tEstadistica;
void inicializar(tEstadistica &e);
bool resuelveCaso();
tEstadistica seleccion(const vector<int> &v);
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
	int n;
	cin >> n;
	if (!cin) 
		return false;
	else{
	
		vector<int>v(n);
		for (int i = 0; i < n;i++){
			cin >> v[i];
		}
		tEstadistica e = seleccion(v);
		cout << e.racha << " " << e.repite << " " << e.jugados << "\n";
		
		return true;
	}
}

void inicializar(tEstadistica &e){
	e.racha = 0;
	e.repite = 0;
	e.jugados = 0;
}

tEstadistica seleccion(const vector<int> &v){
	tEstadistica e;
	inicializar(e);
	int cont = 0;
	int i = 0;
	while (i<v.size()){
		e.jugados++;
		if (v[i]>0){
			cont++;
			if (cont > e.racha){
				e.racha = cont;
				e.repite = 1;
				e.jugados = 0;
			
			}
			else if (cont == e.racha){
				e.repite++;
				e.jugados = 0;
			}
		}
		else{
			cont = 0;
		}
		i++;
	}
	return  e;

}