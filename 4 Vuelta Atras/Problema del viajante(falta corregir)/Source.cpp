#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int N = 4;
void tratarSolucion(int sol[], int m){
	for (int i = 0; i <= m;i++)
		cout << sol[i]<< " ";
	cout <<"\n";
}


bool hayArista(int distancias[N][N],int i, int j){
	return distancias[i][j] != -1;

}
bool esValida(int distancias[N][N], int solucion[], int k, bool usadas[]){
	return (hayArista(distancias, solucion[k - 1], solucion[k])
		&& !usadas[solucion[k]]);
}

void copiarSolucion(int solucion[],int solucionMejor[]){
	for (int i = 0; i < N;i++){
		solucionMejor[i] = solucion[i];
	}
}

void viajante(int distancias[N][N], int solucion[], int &coste, int k,
	int n, int solucionMejor[], int &costeMejor, bool usadas[]){
	// para evitar soluciones repetidas fijamos como ciudad de comienzo l a 0 ,
	// por lo que no se va a volver a considerar
	for (int i = 1; i < n; i++){
		solucion[k] = i;
		if (esValida(distancias, solucion, k, usadas)){
			coste += distancias[solucion[k - 1]][solucion[k]];
			usadas[i] = true;
			if (k == n - 1){
				if (hayArista(distancias, solucion[k], solucion[0])){
					if (coste + distancias[k][0]< costeMejor){
						costeMejor = coste + distancias[k][0];
						copiarSolucion(solucion, solucionMejor);
					}
				}
			}
			else 
				viajante(distancias, solucion, coste, k + 1, n,solucionMejor, costeMejor,usadas);
			usadas[i] = false;
			coste -= distancias[solucion[k - 1]][solucion[k]];
		}
	}
}

void leerDatos(int distancias[N][N], int N) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> distancias[i][j];
		}
	}
}

void resuelveCaso(){
	/*
	int costeEstimado = coste + (n - k + 1) * costeMinimo;
	if (costeEstimado < costeMejor)
		viajante(distancias, solucion, coste, k + 1, n, solucionMejor, costeMejor, usadas, costeMinimo);*/

	int solucion[N];
	int solucionMejor[N];
	bool usadas[N];
	int costeMinimo = 2;
	int distancias[N][N];
	solucion[0] = 0; usadas[0] = true;
	//costeMinimo = calcularMinimo(distancias);
	leerDatos(distancias,N);
	for (int i = 1; i<N; i++) 
		usadas[i] = false; 
	int coste = 0;
	int costeMejor = 0;
	//una cota superior , como por ejemplo la suma de todas las aristas del grafo
	viajante(distancias, solucion, coste, 1, N, solucionMejor, costeMejor, usadas);
	cout << "";
}


int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos;i++){
		resuelveCaso;
	}
	resuelveCaso();
	
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE
	return 0;
}

