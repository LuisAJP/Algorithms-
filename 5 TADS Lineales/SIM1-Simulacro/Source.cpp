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
class deque_partition : public deque<T> {
protected:
    using Nodo = typename deque<T>::Nodo;

private:
    // Declara aquí métodos auxiliaries, si
    // los necesitas

public:
    //Coste es O(n) donde n es el numero de elementos de la lista
    void partition(int pivot) {
        Nodo* miNodo = this->fantasma->sig;
        Nodo* primero = nullptr;
        Nodo* aux= nullptr;
        Nodo* mayores = nullptr;//nuevo1
        Nodo* menores = nullptr;//nuevo2
        while (miNodo != nullptr && miNodo != this->fantasma) {
            aux= miNodo;
            miNodo = miNodo->sig;
            if (aux->elem <= pivot) {
                if (menores == nullptr) 
                    menores = aux;
                else {
                    menores->sig = aux;//enlazo
                    aux->ant= menores;//enlazo
                    menores = menores->sig;//avanzo
                }
            }
            else {
                if (mayores == nullptr) {
                    mayores = aux;
                    primero = aux;//apunta al primer elemento de otro nodo
                }
                else {
                    mayores->sig = aux;//enlazo
                    aux->ant = mayores;//enlazo
                    mayores = mayores->sig;//avanzo
                }
            }
        }
        if (menores != nullptr) {
            if (primero != nullptr) {
                menores->sig = primero;
                primero->ant = menores;
                mayores->sig = this->fantasma;
                this->fantasma->ant = mayores;
            }

        }
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
std::ostream& operator<<(std::ostream& out, const deque_partition<T> deque) {
    deque.display(out);
    return out;
}

using namespace std;



// Función para leer los casos de entrada y llamar la método
// partition sobre cada uno de ellos.
void tratar_caso() {
    deque_partition <int> lista;
    int n = 0,p=0;
    // Implementar
    cin >> n;
    while (n != 0) {
        lista.push_back(n);
        cin >> n;
    }
    cin >> p;
    lista.partition(p);
    cout << lista<<"\n";
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int num_casos;
    std::cin >> num_casos;

    for (int i = 0; i < num_casos; i++) {
        tratar_caso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Windows
     system("PAUSE");
#endif
    return 0;
}