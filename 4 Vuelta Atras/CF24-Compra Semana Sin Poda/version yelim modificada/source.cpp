#include <iostream>
#include <vector>
#include <fstream>
using namespace std;




/*
sol contiene de que mercado es el producto i
numProductosComprado contiene el numero de productos comprados en el mercado i
*/

bool esValido(vector<int> &numProductosComprado, int i) {
	return numProductosComprado[i] < 3; //no quiere comprar mas de tres productos en cada uno de los supermercados
}

bool esSolucion(int k, int p) {
	return k == p - 1;
}

void tratarSolucion(int coste, int &costeMinimo, vector<int> &sol, vector<int> &solMejor, int n) {
	if (coste < costeMinimo || costeMinimo == -1) {
		costeMinimo = coste;
		solMejor = sol;
	}
}

void compraMinimo(const vector<vector<int>> &v, const int &m, const int &n, vector<int> &sol, 
	vector<int> &solMejor, vector<int> &s, int k, int &costeMinimo, int &costeActual) {

	for (int i = 0; i < m; i++){
		if (esValido(s, i)) {
			sol[k] = i;
			costeActual += v[i][k];
			s[i]++;
			if (esSolucion(k, n)) {
				tratarSolucion(costeActual, costeMinimo, sol, solMejor, n);
			}
			else {
				compraMinimo(v, m, n, sol, solMejor, s, k + 1, costeMinimo, costeActual);
			}
			costeActual -= v[i][k];
			s[i]--;
		}
	}
}


void resuelveCaso() {
	int n;//numero de productos
	int m;//numero de supermercados
	cin >> m >> n; //m fila p columna
	vector<vector<int>> v(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> v[i][j];	
	}
	vector<int> sol(n), solMejor(n);
	vector<int> s(m);
	int costeMinimo = -1, coste = 0;
	compraMinimo(v, m, n, sol, solMejor, s, 0, costeMinimo, coste);
	if (costeMinimo == -1) 
		cout << "Sin solucion factible\n";
	else 
		cout << costeMinimo << "\n";

}



int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		resuelveCaso();
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE

	return 0;
}