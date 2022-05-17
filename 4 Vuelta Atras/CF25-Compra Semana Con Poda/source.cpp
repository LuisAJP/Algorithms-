#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 100000000;

bool esValida(const vector<int> &sol, const vector<int> &s, int k){
	if (s[sol[k]] > 3)
		return false;
	return true;
}


bool esPrometedor(int k, int &costeMinimo, int &coste, const vector<int> &minimos, int n) {
	int costeAux = coste;
	for (int i = k + 1; i < n; i++)//recorre todos los productos
		costeAux += minimos[i];
	return costeAux < costeMinimo;
}

void compra(const vector<vector<int>> &v, vector<int> sol, vector<int>&solMejor,
int k, int n, int m, int coste, int &costeMinimo, vector<int>s,const vector<int> &minimos){

	for (int i = 0; i < m; i++){
		sol[k] = i;//supermercado
		coste += v[i][k];
		s[i]++;
		if (esValida(sol, s, k)){
			if (k == n - 1){//es solucion
				if (coste<costeMinimo){
					solMejor = sol;
					costeMinimo = coste;
				}
			}
			else if (esPrometedor(k,costeMinimo,coste,minimos,n))
				compra(v, sol, solMejor, k + 1, n, m, coste, costeMinimo, s,minimos);
		}
		s[i]--;
		coste -= v[i][k];
	}
}

void leerPreciosMinimos(vector<vector<int>> v, vector<int> &minimos, int m, int n){
	for (int j = 0; j < n; j++)
	for (int i = 0; i < m; i++)
		minimos[j] = min(minimos[j], v[i][j]);
}

void resuelveCaso() {
	int m;//m(numero de supermercados)
	int n;//n(numero de productos)
	cin >> m >> n;

	vector<vector<int>> v(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		cin >> v[i][j];

	vector<int> minimos(n,INF);//precios mas bajos de los productos
	leerPreciosMinimos(v,minimos,m,n);
	vector<int>sol(n, -1);
	vector<int>solMejor(n, -1);
	vector<int>s(m, 0);//vector de supermercados
	int coste = 0;
	int costeMinimo = INF;

	compra(v, sol, solMejor, 0, n, m, coste, costeMinimo, s,minimos);
	cout << costeMinimo << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}