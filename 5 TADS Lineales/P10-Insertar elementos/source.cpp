#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

/*
Tema:8
Problema 10
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

template <class T>
class queue_insertar : public queue<T> {
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
	void insertar(queue_insertar<int> &l, int p){
		Nodo *miNodo = this->prim;
		Nodo *aux = nullptr;
		int cont = 1;
		
		while (miNodo != nullptr && p!=0){
			aux = miNodo;
			miNodo = miNodo->sig;
			if (cont == p ){
				aux->sig = l.prim;
				l.ult->sig = miNodo;
				if (miNodo == nullptr)
					this->ult = l.ult;
			}
			cont++;
		}

		if (p == 0){
			l.ult->sig = this->prim;
			this->prim = l.prim;
		}
		
		this->nelems += l.nelems;
		l.prim = nullptr;
		l.ult = nullptr;
		l.nelems = 0;
		
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, queue_insertar<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int N, n,p;
	cin >> N;
	if (!cin) return false;
	queue_insertar<int> lista1;
	queue_insertar<int> lista2;
	for (int i = 0; i < N; i++){
		cin >> n;
		lista1.push(n);
	}
	cin >> N>>p;
	for (int i = 0; i < N; i++){
		cin >> n;
		lista2.push(n);
	}
	
	lista1.insertar(lista2,p);
	cout << lista1 << "\n";
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
