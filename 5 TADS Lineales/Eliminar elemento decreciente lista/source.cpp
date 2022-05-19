/*
Tema:08
Problema Primera Evaluación continua grupo:F, Eliminar los elementos decrecientes de una lista enlazada simple
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "horas.h"
#include "queue_eda.h"
using namespace std;

using namespace std;

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
			// COMPLETAR
		}
		else
			cout << " " << "\n";
	}

	//Coste de la funcion eliminar es lineal O(n),donde n es el numero de elementos de la lista,
	//siempre tiene que recorrer todos los elementos de la cola
	//e ir eliminando los elementos que sean estrictamente menor que el anterior.

	void eliminar(){
		Nodo* primero = this->prim;
		Nodo* miNodo = this->prim;
		Nodo* ant = nullptr;
		Nodo* aux = nullptr;
		while (miNodo != nullptr){
			aux = miNodo;
			miNodo = miNodo->sig;
			if (ant==nullptr)//Si no es el primer elemento
				ant = aux;
			else{
				if (aux->elem < ant->elem){
					ant->sig = aux->sig;
					this->nelems--;
				}
				else
					ant = aux;
			}
		}
		this->prim = primero;
		this->ult = ant;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> const& a) {
	a.print(o);
	return o;
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)  // no hay más casos
		return false;
	ListaDuplica <horas> l;//cola de tipo horas con tamaño n
	int i = n;
	horas  h;
	// leemos las horas
	while (i != 0){
		cin >> h;
		l.push(h);
		i--;
	}
	l.eliminar();
	std::cout << l << "\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
