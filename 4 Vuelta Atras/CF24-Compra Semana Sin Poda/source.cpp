#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool esValida(const vector<int> &sol, const vector<int> &s, int k){
	if (s[sol[k]] > 3)
		return false;
	return true;
}

void compra(const vector<vector<int>> &v, vector<int> sol, vector<int>&solMejor,
int k, int n, int m,int coste, int &costeMinimo, vector<int>s){

	for (int i = 0; i < m;i++){
		sol[k] = i;//supermercado
		coste += v[i][k];
		s[i]++;
		if (esValida(sol,s,k)){
			if (k==n-1){//es solucion
				if (coste<costeMinimo){
					solMejor = sol;
					costeMinimo = coste;
				}
			}
			else
				compra(v, sol, solMejor, k+1, n, m, coste, costeMinimo,s);
		}
		s[i]--;
		coste -= v[i][k];
	}
}

void resuelveCaso() {
	int m;//m(numero de supermercados)
	int n;//n(numero de productos)
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int>(n));
	for (int i = 0; i < m;i++)
	for (int j = 0; j < n; j++)
		cin >> v[i][j];
	vector<int>sol(n,-1);
	vector<int>solMejor(n, -1);
	vector<int>s(m,0);//vector de supermercados
	int coste = 0;
	int costeMinimo = 1000000000;
	compra(v,sol,solMejor,0,n,m,coste,costeMinimo,s);
	cout << costeMinimo<<"\n";

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