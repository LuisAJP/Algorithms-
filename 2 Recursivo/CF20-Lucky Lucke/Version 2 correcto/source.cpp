
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//v[m] >= A, '>=' 2 elementos iguales, me interesa que vaya a la izq,
//pq estoy interesado en encontrar el elemento mas a la izquierda

int buscarIz(const vector<int> &v, int A, int i, int j){
	if (j == i)
		return i;
	
	int m = (i + j) / 2;
	if (v[m] < A)//derecha
		return buscarIz(v, A, m + 1, j);
	else
		return buscarIz(v, A, i, m);
}


int buscarDr(const vector<int> &v, int A, int i, int j){
	if (j == i){
		if (v[j] == A)
			return j;
		else
			return j - 1;
	}
	int m = (i + j) / 2;
	if (v[m] <= A)//dr
		return buscarDr(v, A, m + 1, j);
	else//iz
		return buscarDr(v, A, i, m);
}

bool resuelveCaso(){
	int N, A;
	cin >> N >> A;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	int iz = -1, dr = -1;
	iz = buscarIz(v, A, 0, N - 1);
	dr = buscarDr(v, A, 0, N - 1);

	if (v[iz] != A)
		cout << "NO EXISTE\n";
	else{
		if (dr == iz)
			cout << iz << "\n";
		else
			cout << iz << " "<<dr<<"\n";
	}
	return true;
}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
