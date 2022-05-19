/*
Tema:11
Problema 32 Eligiendo deporte
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

#include <iostream>
#include <string>
#include "hashmap_eda.h"
#include <fstream>
using namespace std;

struct tInfo{
	string deporte;
	int n;
};

bool operator> (tInfo a, tInfo b){
	return a.n > b.n || a.n == b.n && a.deporte < b.deporte;
}

bool resuelveCaso() {
	string cadena,deporte;
	unordered_map<string,int> mapa;
	unordered_map<string, string> mapaJ;
	cin >> cadena;
	if (!cin) return false;
	while (cadena != "_FIN_"){
		if (cadena[0] >= 'A' && cadena[0] <= 'Z') {//es deporte
			if (mapa.count(cadena) == 0){
				mapa.insert({ cadena, 0 });
				deporte = cadena;
			}	
		}
		else{//es jugador
			if (mapaJ.count(cadena) == 0){//todavia no existe el jugador
				mapaJ.insert({ cadena, deporte });
				mapa[deporte] += 1;
			}
			else{ //si jugador ya existe
				//si deporte del jugador inscrito antes es distinto al deporte inscrito actual
				if (mapaJ[cadena] != deporte ){
					if (mapaJ[cadena] != "despistado"){
						string borrar;
						borrar = mapaJ[cadena];//disminuir numero de jugadores del deporte
						mapaJ[cadena] = "despistado";
						mapa[borrar] -= 1;
					}
				}
			}	
		}
		cin >> cadena;
	}
	
	vector<tInfo>v;
	for (auto x : mapa)
		v.push_back({x.clave,x.valor});

	sort(v.begin(), v.end(),greater<tInfo>());

	for (auto x:v)
		cout << x.deporte << " " << x.n<< "\n";

	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	
	ifstream in("casos.txt");
	auto cinbuf =cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}