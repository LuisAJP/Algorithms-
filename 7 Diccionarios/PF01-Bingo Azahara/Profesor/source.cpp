#include <fstream>
#include <iostream>
#include <string>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <list>
#include "set_eda.h"
#include <sstream>
using namespace std;


bool resuelveCaso(){
	int numJugadores;
	cin >> numJugadores;
	if (numJugadores == 0) return false;
	
	unordered_map<string, int>contadores;//jugador y aciertos
	unordered_map<int, vector<string>>numeros;//numero y vector de jugadores

	for (int i = 0; i < numJugadores;i++){
		string nombre;
		cin >> nombre;
		int numero;
		cin >> numero;
		while (numero != 0){
			numeros[numero].push_back(nombre);//inserta numero y lista jugadores con ese numero 
			contadores[nombre]++;//icrementa cantidad numeros del carton
			cin >> numero;
		}
	}

	set<string> bingo;
	while (bingo.empty()){
		int bola;
		cin >> bola;
		for (const string &s : numeros[bola]){//recorre lista de jugadores
			contadores[s]--;//decrementa numero del jugador
			if (contadores[s] == 0){//es bingo tiene todos numeros ha salido
				bingo.insert(s);
			}
		}
	}
	for (auto x : bingo)
		cout << x << " ";
	

	/*auto it = bingo.begin();
	cout << *it;
	it++;
	while (it != bingo.end()){
		cout << " " << *it;
		it++;
	}*/
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