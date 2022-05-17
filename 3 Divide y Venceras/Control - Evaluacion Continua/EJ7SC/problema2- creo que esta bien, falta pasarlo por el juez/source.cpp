
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int cercano(const vector<int> &v, int x, int i, int j){
	if (i == j)
		return i;
	if (j == i + 1){
		if (abs(v[i] - x) > abs(v[j] - x))
			return j;
		else
			return i;
	}
	int m = (i + j) / 2;
	if (abs(v[m] - x) <= abs(v[m - 1] - x))//dr
		return cercano(v, x, m, j);
	else//iz
		return cercano(v, x, i, m-1);
}


void resuelveCaso() {
	int N,x;
	cin >> x >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	int numero = cercano(v,x,0,N-1);
	cout << v[numero]<<"\n";
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}