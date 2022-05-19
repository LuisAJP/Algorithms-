
#include "hashmap_eda.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "list_eda.h"
using namespace std;

using DNI = string;
struct tInfo{
	int puntos;
	list<DNI>::iterator itDNI;

};
class carnet_puntos{

	unordered_map <DNI, tInfo> mapa;

//vector puntos, cada elemento contiene numero conductores con esos puntos
	vector<list<DNI>> v;

public:

	carnet_puntos() : v(16){}

	void nuevo(DNI dni){
		if (mapa.count(dni) == 1)
			throw domain_error("Conductor duplicado");

		auto it = v[15].insert(v[15].end(),dni);//push back en lista v[15]
		mapa.insert({ dni, {15,it}});
	}

	int consultar(DNI dni){
		if (mapa.count(dni) == 0)
			throw domain_error("Conductor inexistente");

		return mapa[dni].puntos;
	}

	void quitar(DNI dni,int puntos){
		
		if (mapa.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		
		v[mapa[dni].puntos].erase(mapa[dni].itDNI);//elimino dni de la lista
		mapa[dni].puntos -= puntos;//actualizo puntos

		mapa[dni].puntos = max(mapa[dni].puntos, 0);//no puede ser negativo

		//inserto en la lista con puntos actualizados
		auto it=v[mapa[dni].puntos].insert(v[mapa[dni].puntos].end(), dni);
		mapa[dni].itDNI = it;
	}

	int cuantos_con_puntos(int puntos){
		if (puntos <0 || puntos >15)
			throw domain_error("Puntos no validos");
		return v[puntos].size();
	}


	void recuperar(DNI dni, int puntos){
		if (mapa.count(dni) == 0)
			throw domain_error("Conductor inexistente");

		if (mapa[dni].puntos < 15){
			v[mapa[dni].puntos].erase(mapa[dni].itDNI);//elimino dni de la lista
			mapa[dni].puntos += puntos;
			
			mapa[dni].puntos = min(mapa[dni].puntos, 15);//puntos no puede ser mayor de 15
			
			auto it = v[mapa[dni].puntos].insert(v[mapa[dni].puntos].end(), dni);
			mapa[dni].itDNI = it;

		}
	}

	list<DNI> lista_por_puntos(int punt){
		if (punt <0 || punt > 15)
			throw domain_error("Puntos no validos");

		list<DNI>l;
		for (auto x : v[punt]){
			l.push_front(x);
		}
		return l;
	}
};
