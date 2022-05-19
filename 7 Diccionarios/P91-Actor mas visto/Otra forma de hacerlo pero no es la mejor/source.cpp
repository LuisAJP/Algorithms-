#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <algorithm>
using namespace std;



/*
Tema:10
Problema 91 Actor mas visto
Autor: Luis Alberto Jaramillo Pulido
Team:F33
*/

typedef struct  {
	string a;//actor
	int t;//tiempo actuacion
}tInfo;


typedef struct {
	string pelicula;
	int veces;
}tEmision;


//Coste es O(N*A), donde N es el numero de peliculas y A es el numero de actores
//el coste es O(N*A), porque al leer una secuencia de peliculas de tamaño N, tengo que acceder 
//a una lista de actores de tamaño A, para obtener el maximo numero de veces que se ha emitido una pelicula
// y  el maximo tiempo que ha aparecido un actor en pantalla
//tanto el coste del del insert del hasmap, push_back de la lista y push de la pila es O(1)
bool resuelveCaso() {

	int P, A, maxActor = 0, maxPel = 0, aux = 0;
	string c;
	unordered_map<string, pair< tEmision, list<tInfo>>>  hmap;
	map <string, int> tmap;
	tInfo info;
	int* value;
	stack<string>pila;

	cin >> P;//numero peliculas
	if (P == 0) return false;
	for (int i = 0; i < P; i++) {
		cin >> c >> A;
		list<tInfo> lista;
		for (int j = 0; j < A; j++) {
			cin >> info.a >> info.t;
			lista.push_back(info);//O(1)
		}
		hmap.insert({ c, { { c, 0 }, lista } });//O(1)
	}
	cin >> P;//numero secuencia de peliculas
	for (int i = 0; i < P; i++) {//Coste es O(N*A)
		cin >> c;//lee pelicula
		hmap[c].first.veces++;
		aux = hmap[c].first.veces;
		if (aux >= maxPel) {
			maxPel = aux;
			pila.push(c);
		}
		auto it = hmap[c].second.begin();//list tInfo(actor y tiempo)
		//Coste es O(A) donde A es numero de actores que participan en la pelicula
		for (auto& n : hmap[c].second) {
			//inserto[] el actor en tmap
			//value(puntero) guarda direccion del iterator tipo tInfo
			//*value tiene valor 0, pq tmap[it->a]=0
			value = &tmap[it->a];

			//se incrementa tiempo y tambien se actualiza tmap[it->a]
			*value += it->t;

			maxActor = max(*value, maxActor);//almaceno solo el maximo tiempo del actor 
			++it;
		}
	}
	cout << maxPel << " " << pila.top() << "\n";
	cout << maxActor << " ";
	for (auto& n : tmap) {//O(A)
		if (n.valor == maxActor)
			cout << n.clave << " ";
	}
	cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
