#include <iostream>
#include <fstream>
using namespace std;
const int N=50;

//Prototipos
void leerMatriz(int M[N][N], unsigned int n);
void resuelveCaso( int S[N][N],  int B[N][N], unsigned int n);
void distribucion(const int S[N][N], const int B[N][N], int k, int sol[N], int solMejor[N], int &benef, int &benefMejor, bool tareas[N], int n);
bool esValida(const int S[N][N], int k, int i, int sol[N]);
void inicializarTareas(bool tareas[N], unsigned int n);

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	

#endif

	unsigned int casos,n;
	int S[N][N];//satisfaciones
	 int B[N][N];//beneficios
	cin >> casos;
	for (int i = 0; i < casos;i++){
		cin >> n;
		leerMatriz(S,n);
		leerMatriz(B,n);
		resuelveCaso(S,B,n);


	}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");

#endif

	return 0;
}


void leerMatriz( int M[N][N], unsigned int n){
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> M[i][j];
}

void inicializarTareas(bool tareas[N], unsigned int n){
	for (int j = 0; j < n; ++j){
		tareas[j] = false;
	}
}
void resuelveCaso(int S[N][N],  int B[N][N], unsigned int n){
	int Beneficio[N];
	int benefMejor = 0;
	int benef = 0;
	int sol[N], solMejor[N];
	bool tareas[N];
	inicializarTareas(tareas,n);
	

	distribucion(S, B, 0, sol, solMejor, benef, benefMejor, tareas, n);
	if (benefMejor != 0)
		cout << benefMejor << endl;

	else
		cout << "Sin solucion factible" << endl;


}

void distribucion(const int S[N][N], const int B[N][N], int k, int sol[N], int solMejor[N], int &benef, int &benefMejor, bool tareas[N], int n) {

	for (int i = 0; i < n; i++) {
		if (!tareas[i]){
			tareas[i] = true;
			sol[k] = i;
			benef += B[k][i];
			if (esValida(S, k, i, sol)) {
				if (k == n - 1) {
					if (benef > benefMejor) {
						benefMejor = benef;
						for (int i = 0; i < n; i++)
							solMejor[i] = sol[i];
					}
				}
				else {
					distribucion(S, B, k + 1, sol, solMejor, benef, benefMejor, tareas, n);
				}
			}
			benef -= B[k][i];
			tareas[i] = false;
		}
	}

}

bool esValida(const int S[N][N], int k, int i, int sol[N]) {

	bool b = true;
	int j = 0;

	// el que estas recorriendo no tenga el doble de satisfaccion ni viceversa
	while (j < k && b) {
		if ((S[j][sol[j]] >= (2 * S[k][i])) || ((S[j][sol[j]] * 2) <= S[k][i]))
			b = false;
		++j;
	}

	return b;
}