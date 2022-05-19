#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <algorithm>
using namespace std;

struct tInfoActor{
	string a;//actor
	int t;//tiempo
};

struct tInfo{
	int emitidas=0;
	list<string>::iterator itPelicula;//iterator apunta a peliculas
	list<tInfoActor> l;//lista actores
};

bool resuelveCaso(){
	int numPeliculas;
	cin >> numPeliculas;

	if (numPeliculas==0) return false;

	unordered_map<string, tInfo>hmap;//peliculas e info
	map<int, list<string>, greater<int>>tmapP;//nveces emitidas y lista peliculas
	map<string, int>tmap;//actores y tiempo 

	int numActores, t, numEmitidas, maximo = 0;
	string p,a;//peliculas y actores

	for (int i = 0; i <numPeliculas; i++){
		cin >> p;//leer pelicula
		hmap[p];//O(1) inserta pelicula en hmap
		cin >> numActores;
		for (int i = 0; i < numActores; i++){
			cin >> a>>t;//leer string actor y tiempo
			hmap[p].l.push_back({ a, t });//O(1) inserto infoActor en lista 
		}
	}
	
	cin >> numEmitidas;
	
	for (int i = 0; i < numEmitidas; i++){
		cin >> p;//leer pelicula
		hmap[p].emitidas+=1;//incremento num veces emitida pelicula
		int e = hmap[p].emitidas;//obtengo num veces emitida pelicula

		//insert[] nveces emitida pelicula en tmapP O(logN)
		//insert en lista peliculas p(pelicula),y obtengo iterator O(1)
		//inserto en orden de llegada las peliculas(push back)
		auto it = tmapP[e].insert(tmapP[e].end(), p); 
		hmap[p].itPelicula = it;//dejo apuntando itPelicula a la pelicula de tmapP

		auto itActor = hmap[p].l.begin();//obtengo it de tipo infoActor(actor y tiempo)
		for (itActor; itActor != hmap[p].l.end(); itActor++){
			string actor = itActor->a;
			tmap[actor] += itActor->t;//incremente tiempo del actor
			maximo = max(maximo, tmap[actor]);//almaceno solo el maximo tiempo del actor 
		}
	}
	//obtengo el mayor nveces emitida pelicula
	auto it = tmapP.begin();

	//muestro nveces emitida pelicula y la pelicula correspondiente 
	//si existieran varias peliculas con el mismo nveces, mostraria
	//la ult pelicula mas reciente/ultima (back)
	cout << it->clave<<" "<<it->valor.back()<<"\n";

	cout << maximo << " ";
	for (auto x : tmap){
		if (x.valor == maximo)
			cout << x.clave << " ";
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
