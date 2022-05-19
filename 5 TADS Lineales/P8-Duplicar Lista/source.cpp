#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

/*
Tema:8
Problema 08 Duplicar una lista enlazada
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/


template <class T>
class ListaDuplica : public queue<T> {
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

	// Duplicar los nodos de una lista
	void duplicar() {
		Nodo *miNodo = this->prim;
		Nodo *aux = nullptr;
		Nodo *nuevo= nullptr;
		while (miNodo !=nullptr){
			aux = miNodo;
			miNodo = miNodo->sig;
			aux->sig = nullptr;
			Nodo *nodoDuplicado = new Nodo(aux->elem);//duplico el nodo 
			nuevo = nodoDuplicado;

			aux->sig = nodoDuplicado;
			nuevo->sig = miNodo;
		}
		this->ult = nuevo;	
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!cin) return false;
	ListaDuplica<int> lista;
	// creamos la lista
	while (n != 0) {
		lista.push(n);
		std::cin >> n;
	}
	lista.duplicar();
	std::cout << lista << '\n';
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}

