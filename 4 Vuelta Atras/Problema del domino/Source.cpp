#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int NUM_VAL = 7;
void tratarSolucion(int sol[], int m){
	for (int i = 0; i <= m;i++)
		cout << sol[i]<< " ";
	cout <<"\n";
}


void domino(int sol[], int k, int n, vector<vector<bool>> &marcas, bool &exito){
	int i = 0;
	int m = (n * n + n) / 2;
	while (i < n && !exito){
		if (!marcas[sol[k - 1]][i]){
			sol[k] = i;
			if (k == m) {
				if (sol[0] == sol[k]){
					tratarSolucion(sol, m);
					exito = true;
				}
			}
			else {
				marcas[sol[k - 1]][i] = true;
				marcas[i][sol[k - 1]] = true;
				domino(sol, k + 1, n, marcas, exito);
				marcas[sol[k - 1]][i] = false;
				marcas[i][sol[k - 1]] = false;
			}
		}
		i++;
	}
}



void resuelveCaso(){
	const int TAM_SOL = (NUM_VAL*NUM_VAL + NUM_VAL) / 2 + 1;
	int sol[TAM_SOL];
	vector<vector<bool>> marcas(NUM_VAL, vector<bool>(NUM_VAL));
	for (int i = 0; i < NUM_VAL; i++){
		for (int j = 0; j < NUM_VAL; j++)
			marcas[i][j] = false;
	}
	sol[0] = NUM_VAL - 1;
	sol[1] = NUM_VAL - 1;
	marcas[NUM_VAL - 1][NUM_VAL - 1] = true;
	bool exito = false;
	domino(sol, 2, NUM_VAL, marcas, exito);
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	resuelveCaso();
	
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE
	return 0;
}

