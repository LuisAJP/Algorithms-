#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool esValido(vector<int> &numProductosComprado, int i) {
	return numProductosComprado[i] < 3;//no quiere comprar m¢?ás de tres productos en cada uno de los supermercados
}

bool esSolucion(int k, int p) {
	return k == p - 1;
}

void tratarSolucion(int costeActual, int &costeMinimo, vector<int> &sol, vector<int> &solMejor, int p) {
	if (costeActual < costeMinimo || costeMinimo == -1) {
		costeMinimo = costeActual;
		solMejor = sol;
	}
}

bool esPrometedor(int k, int &costeMinimo, int &coste, const vector<int> &minProductos, int n) {
	int costeAux = coste;
	for (int i = k + 1; i < n; i++) {//recorre todos los productos
		costeAux += minProductos[i];
	}
	return costeAux < costeMinimo || costeMinimo == -1;
}

/*
sol contiene de que mercado es el producto i
numProductosComprado contiene el numero de productos comprados en el mercado i
*/

void compraMinimo(const vector<vector<int>> &v, const int &m, const int &n, vector<int> &sol, vector<int> &solMejor, 
	vector<int> &numProductosComprado, int k, int &costeMinimo, int &coste, const vector<int> &minProductos) {
	for (int i = 0; i < m; i++){
		if (esValido(numProductosComprado, i)) {
			sol[k] = i;
			coste += v[i][k];
			numProductosComprado[i]++;
			if (esSolucion(k, n)) {
				tratarSolucion(coste, costeMinimo, sol, solMejor, n);
			}
			else if (esPrometedor(k, costeMinimo, coste, minProductos, n)) {
				compraMinimo(v, m, n, sol, solMejor, numProductosComprado, k + 1, costeMinimo, coste, minProductos);
			}
			coste -= v[i][k];
			numProductosComprado[i]--;
		}
	}
}
void leerDatos(vector<vector<int>> &v, int m, int p, vector<int> &minimoProducto) {
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p; j++){
			cin >> v[i][j];
			if (v[i][j] < minimoProducto[j] || minimoProducto[j] == -1)
				minimoProducto[j] = v[i][j];
		}
	}
}

void resuelveCaso() {
	int n, m;
	cin >> m >> n; //m fila n columna
	vector<vector<int>> v(m, vector<int>(n));
	vector<int> minProductos(n, -1);//guarda precios(elemento) mas bajo de cada producto(posicion)  
	
	leerDatos(v, m, n, minProductos);

	vector<int> sol(n), solMejor(n);
	vector<int> s(m);
	int costeMinimo = -1, coste = 0;

	compraMinimo(v, m, n, sol, solMejor, s, 0, costeMinimo, coste, minProductos);

	if (costeMinimo == -1) 
		cout << "Sin solucion factible\n" ;
	else 
		cout << costeMinimo <<"\n";

}


int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE

	return 0;
}
