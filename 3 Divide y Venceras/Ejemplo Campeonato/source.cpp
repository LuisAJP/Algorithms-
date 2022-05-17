#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void rellena( vector<vector<int>> &v, int c, int f){
	int dim = f - c + 1;
	int m = dim / 2;

	if (dim == 2) { 
		v[c + 1][c] = 1; 
	}
	else if (dim>2){
		rellena(v, c, c + m - 1); // cuadrante superior iz
		rellena(v, c + m, f); //cuadrante inferior dr
		for (int i = c + m; i <= f; i++){ //cuadrante inferior iz
			for (int j = c; j <= c + m - 1; j++){
				v[i][j] = m + (i + j) % m;
			}
		}
	}
}

void imprimir(const vector<vector<int>> &v, int N){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (v[i][j] != -1)
				cout << v[i][j] << " ";
			else
				cout << "- ";
		}

		cout << "\n";
	}
}
bool resuelveCaso() {

	//leer datos
	int N;
	cin >> N;
	if (!cin)
		return false;

	vector<vector<int>> v(N, vector<int>(N,-1));
	rellena(v,0,N-1);
	//imprimir matriz
	imprimir(v,N);
	cout << "\n";
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}