/*
* ---------------------------------------------------
*                ESTRUCTURAS DE DATOS
* ---------------------------------------------------
*/

/*
* Nombre y apellidos: Luis Alberto Jaramillo Pulido
Team:F33
___________________________________________
*/

#include <iostream>
#include <fstream>
#include "deque_eda.h"

template<typename T>
class deque_invertir : public deque<T> {
protected:
	using Nodo = typename deque<T>::Nodo;

private:


public:
	//Coste es O(n) donde n es el numero de elementos de la lista
	void invertir() {
		Nodo * miNodo = this->fantasma->sig;
		Nodo * nuevo = nullptr;
		Nodo * aux = nullptr;
		while (miNodo != nullptr && miNodo != this->fantasma){
			aux = miNodo;
			miNodo = miNodo->sig;
			if (nuevo == nullptr){
				nuevo = aux;
				nuevo->sig = this->fantasma;
			}
			else{
				aux->sig = nuevo;
				nuevo->ant = aux;
				nuevo = aux;
			}
		}
		nuevo->ant = this->fantasma;
		this->fantasma->ant = this->fantasma->sig;
		this->fantasma->sig = nuevo;
	}

	// Método para imprimir una doble cola por pantalla
	void display(std::ostream& out) const {
		if (this->fantasma->sig != this->fantasma) {
			out << this->fantasma->sig->elem;
			Nodo* cur = this->fantasma->sig->sig;
			while (cur != this->fantasma) {
				out << " " << cur->elem;
				cur = cur->sig;
			}
		}
	}
};


// Sobrecarga del operador << para dobles colas.
// Si quieres imprimir una doble cola 'dq' puedes hacer: cout << dq << "\n";
template<typename T>
std::ostream& operator<<(std::ostream& out, const deque_invertir<T> deque) {
	deque.display(out);
	return out;
}

using namespace std;



// Función para leer los casos de entrada y llamar la método
// partition sobre cada uno de ellos.
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!cin) return false;
	deque_invertir<int> lista;
	// creamos la lista
	while (n != 0) {
		lista.push_back(n);
		cin >> n;
	}
	if (!lista.empty())
		lista.invertir();
	// y la mostramos
	cout << lista << '\n';
	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// Descomentar si se trabaja en Windows
	system("PAUSE");
#endif
	return 0;
}