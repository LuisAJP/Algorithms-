#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool esValida(vector<int> &sol, int k, const vector<vector<int>> &v){
	//Si estamos en el primer nivel, es valido porque necesitamos avanzar en busca de una solucion
	if (k == 0) return true;
	if (v[sol[k]][sol[k - 1]] == 1) return true;
	return false;
}

void donaciones(const vector<vector<int>> &d, const vector<vector<int>> &v, vector<int> &sol, int k, int N,
	int &donacion, int &mejor, vector<int > &solMejor){

	for (int i = 0; i < N; i++){
		sol[k] = i;
		donacion += d[i][k];
		if (esValida(sol, k, v)) {
			if (k == N - 1) {//tratar solucion
				solMejor = sol;
				mejor = max(donacion, mejor);
			}//si no //llamada recursiva
			else
				donaciones(d, v, sol, k + 1,N, donacion, mejor,solMejor);
		}
		donacion -= d[i][k];
	}
}

void resuelveCaso(){
	int N = 0, a = 0;
	cin >> N;

	vector<vector<int>> d(N, vector<int>(N));//donaciones
	vector<vector<int>> v(N, vector<int>(N));//vetos
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> d[i][j];

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
			cin >> v[i][j];
	int k = 0;
	vector<int > sol(N,-1);
	vector<int > solMejor(N, -1);

	int donacion = 0;
	int mejor = -1;

	donaciones(d, v, sol, k, N, donacion, mejor,solMejor);
	if (mejor == -1) 
		cout << "NEGOCIA CON LOS ARTISTAS" << endl;
	else cout << mejor << endl;
}


int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		resuelveCaso();
	}

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE

	return 0;
}


