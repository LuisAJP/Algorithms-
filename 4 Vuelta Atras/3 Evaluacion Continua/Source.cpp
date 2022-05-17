#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct tDato{
	int duracion;
	int puntuacion;
};

bool esValida(const vector<tDato> &v, const vector<int> &sol, vector<bool> &marcador, int &acumuladoCaraA, int &acumuladoCaraB, int duracionCaras, int k){
	if (k == 0) return true;
	if (marcador[sol[k]]) return false;
	if (acumuladoCaraA <= duracionCaras) return true;

	if (acumuladoCaraA > duracionCaras){
		acumuladoCaraB += v[sol[k]].duracion;
		if(acumuladoCaraB <= duracionCaras) return true;
		else{
			acumuladoCaraB -= v[sol[k]].duracion;
			return false;
		}
	}
	return false;
}

void cassete(const vector<tDato> &v, vector<int> sol, vector<bool> &marcador, int duracionCaras, int k, int &acumuladoCaraA, int &acumuladoCaraB, int &acumuladoPuntuacion, int &mejor){
	for (int i = 0; i < v.size();i++){
		sol[k] = i;
		
		acumuladoCaraA += v[sol[k]].duracion;
		acumuladoPuntuacion += v[sol[k]].puntuacion;

		if (esValida(v,sol,marcador,acumuladoCaraA,acumuladoCaraB,duracionCaras,k)){
			//if (k==v.size()-1){//es solucion
				mejor = max(mejor,acumuladoPuntuacion);
				//tratar solucion, mostrar
			//}
			//else
				if (k < v.size()) {
					marcador[sol[k]] = true;
					cassete(v,sol,marcador,duracionCaras,k+1,acumuladoCaraA,acumuladoCaraB,acumuladoPuntuacion,mejor);
					marcador[sol[k]] = false;
				}
		}
		acumuladoCaraA -= v[sol[k]].duracion;
		acumuladoPuntuacion -= v[sol[k]].puntuacion;
	}

}

bool resuelveCaso(){
	int numCanciones;
	int duracionCaras;
	cin >> numCanciones >> duracionCaras;
	if (numCanciones == 0) return false;
	vector<tDato> v;
	for (int i = 0; i < numCanciones;i++){
		tDato dato;
		cin >> dato.duracion;
		cin >> dato.puntuacion;
		v.push_back(dato);
	}
	vector<int> sol(numCanciones,-1);
	vector<bool> marcador(numCanciones, false);
	int k = 0;
	int acumuladoCaraA=0;
	int acumuladoCaraB = 0;
	int acumuladoPuntuacion = 0;
	int mejor = 0;
	cassete(v,sol,marcador,duracionCaras,k,acumuladoCaraA,acumuladoCaraB,acumuladoPuntuacion,mejor);
	cout << mejor<<"\n";
	return true;
}


int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE


	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE

	return 0;
}


