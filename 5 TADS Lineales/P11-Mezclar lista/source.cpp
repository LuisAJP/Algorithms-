#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

/*
Tema:8
Problema 11 mezclar lista
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/


template <class T>
class ListaMezcla : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aquí
public:
	void print(std::ostream & o = std::cout) const {
		if (!this->empty()) {
			// la lista no está vacía
			Nodo *aux = this->prim;
			while (aux != nullptr) {
				cout << aux->elem << " ";
				aux = aux->sig;
			}
		}
		else
			cout << " ";
	}

	//Coste o(n) donde n son todos los elementos de la lista, es lineal porque tiene que recorrer toda
	//la lista e ir comparando con la lista "other", todo eso conlleva un coste lineal
	void mezclar(ListaMezcla<int> &other) {
		Nodo * miNodo = this->prim;
		Nodo *ant = nullptr;
		Nodo *otroNodo = other.prim;
		while (miNodo != nullptr && otroNodo != nullptr){
			if (miNodo->elem <= otroNodo->elem){
				ant = miNodo;
				miNodo = miNodo->sig;
			}
			else{
				if (ant == nullptr)//o tambien miNodo == this->prim
					this->prim = otroNodo;
				else
					ant->sig = otroNodo;
				ant = otroNodo;
				otroNodo = otroNodo->sig;
				ant->sig = miNodo;
			}
		}


		if (miNodo == nullptr){
			this->ult->sig = otroNodo;
			this->ult = other.ult;
		}
		this->nelems += other.nelems;
		other.prim = nullptr;
		other.ult = nullptr;
		other.nelems = 0;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaMezcla<T> const& a) {
	a.print(o);
	return o;
}

void resuelveCaso() {
	ListaMezcla<int> lista1;
	ListaMezcla<int> lista2;
	// creamos la lista
	int n;
	cin >> n;
	while (n != 0) {
		lista1.push(n);
		cin >> n;
	}
	cin >> n;
	while (n != 0) {
		lista2.push(n);
		cin >> n;
	}

	if (!lista1.empty() && !lista2.empty()){
		lista1.mezclar(lista2);
		cout << lista1 << "\n";
	}
	else if (lista2.empty())
		cout << lista1 << "\n";
	else
		cout << lista2 << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
