#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "list_eda.h"
#include "persona.h"

/*
Tema:8
Problema 10
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/

template <class T>
class list_remove : public list<T> {
	using Nodo = typename list<T>::Nodo;  // para poder usar Nodo aquí
public:
	template <class Predicate>
	void remove_if(Predicate pred){
		Nodo *miNodo = this->fantasma->sig;
		Nodo *aux = nullptr;
		Nodo *ant = nullptr;
		while (miNodo != nullptr && miNodo != this->fantasma){
			aux = miNodo;
			miNodo = miNodo->sig;
			if (ant == nullptr)
				ant = this->fantasma;

			if (!pred(aux->elem)){
				ant->sig = miNodo;
				miNodo->ant = ant;
				this->nelems--;
			}
			else
				ant = aux;
		}

	}

	// Método para imprimir una doble cola por pantalla
	void display(std::ostream& out) const {
		if (this->fantasma->sig != this->fantasma) {
			out << this->fantasma->sig->elem;
			Nodo* cur = this->fantasma->sig->sig;
			while (cur != this->fantasma) {
				out << cur->elem;
				cur = cur->sig;
			}
		}
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const list_remove<T> deque) {
	deque.display(out);
	return out;
}

bool resuelveCaso() {
	int N, a, b, n;
	cin >> N;
	if (N == 0) return false;
	cin >> a >> b;
	persona p;
	string nombre,apellido;
	list_remove<persona> l;
	for (int i = 0; i < N; i++){
		cin >> n >> nombre;
		getline(cin,apellido);
		p.setNombre(nombre);
		p.setApellido(apellido);
		p.setEdad(n);
		l.push_back(p);
	}
	//paso un predicado, que devuelve true si el elemento a evaluar
	//esta en el rango de valores a y b y en caso contrario
	//devuelve false
	l.remove_if([a, b](persona p) { return (p.getEdad() >= a && p.getEdad() <= b); });
	cout << l;
	cout<<"---"<<"\n";
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
