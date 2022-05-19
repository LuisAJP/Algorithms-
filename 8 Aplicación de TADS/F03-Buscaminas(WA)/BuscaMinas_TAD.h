#include "hashmap_eda.h"
#include <list>
#include<climits>
using namespace std;

class Buscaminas{
private:

	struct tInfoPosicion{//coordenadas
		int x;
		int y;
	};

	struct tArea{//coordenadas del rectángulo más pequeño que contiene todas las minas del tablero
		pair<int, int>maximo = { INT_MIN, INT_MIN };
		pair<int, int>minimo = { INT_MAX, INT_MAX };
	};
	
	//mapa de minas 
	//coordenadas(string) y coordenadas(tInfoPosicion) 
	unordered_map<string, tInfoPosicion>tablero;

	//mapa del jugador
	//nombre del jugador y puntuacion del jugador
	unordered_map<string, int>mapJugador;
	
	tArea area;//area de las minas 

public:
	int anyadir_mina(int x, int y){

		string str1 = to_string(x);//convierto int a string 
		string str2 = to_string(y);//convierto int a string 
		string coordenada = str1 + " " + str2;//obtengo clave de la coordenada(string)
		
		tablero[coordenada] = {x,y};

		//guardo la coordenada minima de la mina 
		if (x <= area.minimo.first && y <= area.minimo.second)
			area.minimo = {x,y};

		//guardo la coordenada maxima de la mina 
		if (x >= area.maximo.first &&  y >= area.maximo.second)
			area.maximo = { x, y };
		
		return tablero.size();
	}


	void anyadir_jugador(string jugador){

		if (mapJugador.count(jugador) == 1)
			throw invalid_argument("Jugador existente");

		mapJugador.insert({ jugador, { 0 } });

	}

	int explorar(string jugador, int x, int y){

		int colindantes=0;

		if (mapJugador.count(jugador) == 0)
			throw invalid_argument("Jugador no existente");

		string str1 = to_string(x);//convierto int a string 
		string str2 = to_string(y);//convierto int a string 
		string coordenada = str1 + " " + str2;//obtengo clave de la coordenada(string)

		//coordenadas jugador coincide con la coordenada de la mina
		if (tablero.count(coordenada)==1){
			mapJugador.erase(jugador);
			return -1;
		}
		else{
			for (auto u:tablero){//recorro todo el tablero
				//si es colindante la coordenada, la diferencia no debe exceder mas de 1
				if (abs(u.valor.x - x) <=1 && abs(u.valor.y - y) <=1)
					colindantes++;
			}
			return colindantes;
		}
	}

	bool bandera(string jugador, int x, int y){
		if (mapJugador.count(jugador) == 0)
			throw invalid_argument("Jugador no existente");
		string str1 = to_string(x);//convierto int a string 
		string str2 = to_string(y);//convierto int a string 
		string coordenada = str1 + " " + str2;//obtengo clave de la coordenada(string)

		//Si el jugador coloca la bandera donde hay una mina
		if (tablero.count(coordenada) == 1){
			mapJugador[jugador] += 1;//suma un punto al jugador
			return true;
		}
		else{
			mapJugador[jugador] -= 5;//se resta 5 puntos al jugador
			return false;
		}
	
	}

	void bordes_tablero(int &min_x, int &min_y, int &max_x, int &max_y){
		if (num_minas() == 0)
			throw domain_error("Tablero vacio");
		//obtengo la coordenada minima de la mina
		min_x = area.minimo.first;
		min_y = area.minimo.second;
		
		//obtengo la coordenada maxima de la mina
		max_x = area.maximo.first;
		max_y = area.maximo.second;
	}


	int puntuacion(string jugador){
		return mapJugador[jugador];
	}

	int num_minas(){
		return tablero.size();
	}
};



//void bordes_tablero(int &min_x, int &min_y,int &max_x, int &max_y){

//	for (auto u : tablero){
//		if (u.valor.x <= min_x  &&  u.valor.y <= min_x ){
//			min_x = u.valor.x;
//			min_y = u.valor.y;
//		}
//		if (u.valor.x >= max_x && u.valor.y >= max_y){
//			max_x = u.valor.x;
//			max_y = u.valor.y;
//		}
//			
//	}
//	
//}