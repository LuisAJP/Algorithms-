#include <fstream>
#include <iostream>
#include <string>
#include "hashmap_eda.h"
#include "set_eda.h"
#include <list>
#include <sstream>
using namespace std;

/*
Tema:10
Problema F01 Bingo de Azahara
Autor: Luis Alberto Jaramillo Pulido
team:F33
*/

struct tInfo{
	int tam=0;
	int aciertos=0;
};

bool resuelveCaso(){
	int numJugadores;
	cin >> numJugadores;
	if (numJugadores == 0) return false;

	unordered_map<int, list<string>> mapa;//numero y lista jugadores
	unordered_map<string , tInfo> mapJ;//jugadores e infoJugador
	set<string> bingo;// conjunto de ganadores, ordenados ascendentemente por nombre

	int numero;
	string jugador;

	for (int i = 0; i < numJugadores; i++){
		cin >> jugador;
		cin >> numero;
		while (numero != 0){
			//inserto numero al mapa, a la vez inserto jugador a la lista 
			mapa[numero].push_back(jugador);
			cin >> numero;
			mapJ[jugador].tam += 1;//incremento cantidad numeros del carton
		}
	}

	while (bingo.empty()){
		cin >> numero;
		for (auto x : mapa[numero]){//recorro lista
			mapJ[x].aciertos +=1;//incrementa acierto del numero del jugador 
			//si cantidad total numeros del jugador = aciertos entonces es bingo
			if (mapJ[x].tam == mapJ[x].aciertos){
				bingo.insert(x);//inserto jugador ganador al conjunto set
			}
		}
	}
		
	for (auto x : bingo)
		cout << x << " ";

	cout << "\n";
	return true;
}

int main(){
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto buffer = cin.rdbuf(in.rdbuf());
#endif 
	while (resuelveCaso());
	
#ifndef DOMJUDGE
	cin.rdbuf(buffer);
	system("pause");
#endif 
	return 0;
}

