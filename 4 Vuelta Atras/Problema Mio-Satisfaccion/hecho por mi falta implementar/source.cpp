#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool esValida(const vector<vector<int>> &S, vector<int> &sol, int k){
	if (k == 0)
		return true;
	//no esta bien, solo comparo el actual con el anterior, 
	//puede ocurrir que entre las soluciones haya un elemento mucho mas anterior que sea el doble
	//luego tampoco evaluo viceversa
	//if (S[sol[k]][k] < 2 * S[sol[k - 1]][k - 1]) return true;
	int j = 0;
	//evaluas todas las satisfaciones de los empleados seleccionados en la solucion con la satisfacion del empleado actual,
	//puede ocurrir que el empleado actual seleccionado tenga una satisfacion menor que el resto de empleados
	//por eso es necesario tener en cuenta que se cumpla tambien de forma viceversa
	while (j<k){
		if (S[sol[k]][k] >= 2 * S[sol[j]][j] || S[sol[j]][j] >= 2 * S[sol[k]][k])
			return false;
		j++;
	}
	return true;
}

void satisfaccion(const vector<vector<int>> &S, const vector<vector<int>> B, vector<int> sol,
	vector<int> &solMejor, int k, int N, vector<bool> marcas, int &beneficio, int &mejor){

	for (int i = 0; i < N; i++){
		if (!marcas[i]){
			marcas[i] = true;
			sol[k] = i;
			beneficio += B[i][k];
			if (esValida(S, sol, k)){
				if (k == N - 1){
					if (beneficio>mejor){
						solMejor = sol;
						mejor = max(beneficio, mejor);
					}
				}
				else
					satisfaccion(S, B, sol, solMejor, k + 1, N, marcas, beneficio, mejor);

			}
			marcas[i] = false;
			beneficio -= B[i][k];
		}
	}
}

void resuelveCaso(){
	int N;
	cin >> N;
	vector<vector<int>> S(N, vector<int>(N));
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> S[i][j];

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> B[i][j];
	vector<int> sol(N);
	vector<int> solMejor(N);
	vector<bool> marcas(N, false);
	int beneficio = 0;
	int mejor = 0;
	satisfaccion(S, B, sol, solMejor, 0, N, marcas, beneficio, mejor);
	if (mejor !=0)
		cout << mejor<<"\n";
	else
		cout << "Sin solucion factible\n";

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