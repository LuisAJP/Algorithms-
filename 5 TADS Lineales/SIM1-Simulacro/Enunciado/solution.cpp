/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * Nombre y apellidos: ___________________________________________
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

    // Implementa aquí el método pedido
    void partition(int pivot) {
      
    }

    // Método para imprimir una doble cola por pantalla
    void display(std::ostream &out) const {
      if (this->fantasma->sig != this->fantasma) {
        out << this->fantasma->sig->elem;
        Nodo *cur = this->fantasma->sig->sig;
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
std::ostream & operator<<(std::ostream &out, const deque_partition<T> deque) {
  deque.display(out);
  return out;
}

using namespace std;



// Función para leer los casos de entrada y llamar la método
// partition sobre cada uno de ellos.
void tratar_caso() {

  // Implementar

}


int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
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
  // system("PAUSE");
#endif
  return 0;
}