#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

//El coste de acceder a la matriz V es de orden constante O(1).
bool esValida(vector<vector<int>> V, vector<int> sol, int k){
	if (k == 0)
		return true;
	if (k > 0 && V[sol[k]][sol[k - 1]] == 1) return true;
	//if (k > 0 && V[sol[k]][k] == 1)return true; //falla porque estoy compararando el artista con el turno en vetos
	//la matriz veto relaciona tocar el artista despues de otro artista y no lo relaciona con el turno
	// para que sea correcto tengo que compararlo si puede tocar despues del artista anterior
	return false;
}


bool esPrometedor(int k,int N, const vector<int> &maximos, int donacion, int donacionMax){
	int costeAux = donacion;
	for (int i = k + 1; i < N; i++)
		costeAux = maximos[i];
	return costeAux>donacionMax;
}
void donaciones(const vector<vector<int>> &D, const vector<vector<int>> &V,
	vector<int> sol, vector<int> &solMejor, int k, int N, int &donacion, int &donacionMax, const vector<int> &maximos){

	for (int i = 0; i < N; i++){
		sol[k] = i;
		donacion += D[i][k];
		if (esValida(V, sol, k)){
			if (k == N - 1){//tratar solucion;
				if (donacion>donacionMax){
					solMejor = sol;
					donacionMax = donacion;
				}
			}

			else if (esPrometedor(k,N,maximos,donacion,donacionMax))
				donaciones(D, V, sol, solMejor, k + 1, N, donacion, donacionMax,maximos);
		}
		donacion -= D[i][k];
	}
}


void leerDonaciones(const vector<vector<int>> &D, vector<int> &maximos, int N){
	for (int j = 0; j < N; j++)
	for (int i = 0; i < N; i++)
		maximos[j] = max(maximos[j], D[i][j]);
}
void resuelveCaso(){
	int N;
	cin >> N;
	vector<vector<int>> D(N, vector<int>(N));//Donaciones
	vector<vector<int>> V(N, vector<int>(N));//Vetos

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> D[i][j];

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> V[i][j];

	vector<int> sol(N, -1);
	vector<int> solMejor(N, -1);
	int donacionMax = -1;
	int donacion = 0;
	vector<int> maximos(N, -1);//donaciones maximas de cada turno
	leerDonaciones(D,maximos, N);
	donaciones(D, V, sol, solMejor, 0, N, donacion, donacionMax,maximos);
	if (donacionMax != -1)
		cout << donacionMax << "\n";
	else
		cout << "NEGOCIA CON LOS ARTISTAS" << "\n";

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