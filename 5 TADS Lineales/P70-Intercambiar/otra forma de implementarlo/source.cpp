#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"


/*
Team: F33
Alumno:Luis Alberto Jaramillo Pulido
Problema: Intercambiar los elementos de una lista de dos en dos
*/


/*Coste es de orden N, O(N) donde n es el numero de elementos de la lista,recorre todos los elementos de la lista
invirtiendo los elementos de 2 en 2, como recorre toda la lista, recorre los n elementos de la lista, por lo tanto
el coste es O(N)
*/
template <class T>
class queue_intercambiar : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
	void print(std::ostream& o = std::cout) const {
		if (!this->empty()) {// la lista no est� vac�a
			Nodo* nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}

		}
	}

	// Duplicar los nodos de una lista
	void intercambiar() {
		Nodo* miNodo = this->prim;
		Nodo* aux = nullptr;
		Nodo* ant = nullptr;
		Nodo* nuevo = nullptr;

		while (miNodo != nullptr ) {
			ant= miNodo;
			aux = miNodo->sig;
			if (aux != nullptr){
				miNodo = miNodo->sig->sig;
				if (nuevo == nullptr){
					aux->sig = ant;
					ant->sig = miNodo;
					nuevo = ant;
					this->prim = aux;
				}
				else{
					aux->sig = ant;
					ant->sig = miNodo;
					nuevo->sig = aux;
					nuevo = nuevo->sig->sig;
				}
			}
			else 
				miNodo = nullptr;
		}
		if (aux!=nullptr)
			this->ult = nuevo;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream& o, queue_intercambiar<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int N;
	int n;
	cin >> N;
	if (N == 0) return false;
	queue_intercambiar<int> l;

	for (int i = 0; i < N; i++) {
		cin >> n;
		l.push(n);
	}
	l.intercambiar();
	cout << l << '\n';
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