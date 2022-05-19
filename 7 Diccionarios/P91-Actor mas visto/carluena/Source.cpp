#include <iostream>
#include "hashmap_eda.h"
#include "stack_eda.h"
#include "treemap_eda.h"
using namespace std;

bool resuelveCaso() {
	struct casting {
		int val; //nº veces vista
		map <string, int> actors;

	};

	unordered_map<string, casting> movies;
	map <string, int> actors;
	std::stack <string> pila_movies;

	int n, k, tam, mins, max_mins, max_emision, veces;
	string mov_aux, act_aux;
	int* value;

	cin >> n;
	if (n == 0)
		return false;

	max_mins = 0;
	max_emision = 0;

	//obtencion de las peliculas
	//cargo las pelis con sus actores, es un bucle doble, for for, 
	// for para cda peli y for para los acotrres de cada peli
	for (int i = 0; i < n; ++i) {
		cin >> mov_aux >> k; //cojo el nombre de la peli y actores;
		map <string, int> cast;
		for (int j = 0; j < k; ++j) {
			cin >> act_aux >> mins;
			cast.insert({ act_aux,mins });
		}
		movies.insert({ mov_aux, {0,cast} });
	}

	cin >> k; //Nºtotal de visiones
	//cada vez que aparece pelio nueva, cojo su nombre, subo el contador, 
	//miro numero emisiones y meto en pila, miro actors

	for (int i = 0; i < k; ++i) {
		cin >> mov_aux;
		veces = ++movies[mov_aux].val;
		if (veces >= max_emision) {
			max_emision = veces;
			pila_movies.push(mov_aux);
		}
		tam = movies[mov_aux].actors.size();
		auto it = movies[mov_aux].actors.begin();
		for (int i = 0; i < tam; ++i){
		
			value = &actors[it->clave];
			*value += it->valor;
			if (*value > max_mins)
				max_mins = *value;
			++it;
		
		}


	}

	while (movies[pila_movies.top()].val != max_emision)
		pila_movies.pop();

	cout << max_emision << " " << pila_movies.top() << "\n";
	cout << max_mins << " ";

	for (auto it : actors) {
		if (it.valor == max_mins) {
			cout << it.clave << " ";
		}	
	}

	cout << "\n";

	return true;
}

int main() {

	while (resuelveCaso() {}

	return 0;
}