#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

/*
Tema:8
Problema 12 Invertir una lista
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

template <class T>
class ListaInvertir : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aquí
public:
	void print(std::ostream & o = std::cout) const {
		if (!this->empty()) {
			// la lista no está vacía
			Nodo *miNodo = this->prim;
			while (miNodo != nullptr) {
				cout << miNodo->elem << " ";
				miNodo = miNodo->sig;
			}
		}
		else
			cout << " " << "\n";
	}

	//Coste es O(n), donde n son todos los elementos de la cola, 
	//se tiene que recorrer todos los elementos e ir insertandolo 
	//inversamente a orden que tenian.
	void invertir(){
		Nodo *miNodo = this->prim;
		Nodo *aux = nullptr;
		Nodo *nuevo = nullptr;
		while (miNodo != nullptr){
			aux = miNodo;
			miNodo = miNodo->sig;
			aux->sig = nullptr;
			if (nuevo == nullptr)
				nuevo = aux;
			else{
				aux->sig = nuevo;
				nuevo = aux;
			}	
		}
		this->ult = this->prim;
		this->prim = nuevo;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaInvertir<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!cin) return false;
	ListaInvertir<int> lista;
	// creamos la lista
	while (n != 0) {
		lista.push(n);
		std::cin >> n;
	}
	if (!lista.empty())
		lista.invertir();
	// y la mostramos
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
