
#include "hashmap_eda.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

using DNI = string;

class carnet_puntos{

	unordered_map <DNI, int> mapa;

//vector puntos, cada elemento contiene numero conductores con esos puntos
	vector<int> v;

public:

	carnet_puntos() : v(16){}

	void nuevo(DNI dni){
		if (mapa.count(dni) == 1)
			throw domain_error("Conductor duplicado");

		mapa.insert({ dni, 15 });

		++v[15];//actualiza numero conductores con 15 puntos
	}

	int consultar(DNI dni){
		if (mapa.count(dni) == 0)
			throw domain_error("Conductor inexistente");

		return mapa[dni];
	}

	void quitar(DNI dni,int puntos){
		
		if (mapa.count(dni) == 0)
			throw domain_error("Conductor inexistente");

		
		v[mapa[dni]]--;//resta numero de conductores con esos puntos
		mapa[dni] -= puntos;//actualiza puntos conductor

		//conductor no puede tener puntos negativos
		mapa[dni] = max(0, mapa[dni]);

		v[mapa[dni]]++;//actualizamos numero conductores con esos puntos
			
		
	}

	int cuantos_con_puntos(int puntos){
		if (puntos <0 || puntos >15)
			throw domain_error("Puntos no validos");
		return v[puntos];
	}
};