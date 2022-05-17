
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


bool degradadoImagen(const vector<int> &v,int i,int j, int &suma){
	if (j == i+1){
		suma = v[i] + v[j];
		return v[i] < v[j];
	}
	int m = (i + j) / 2;
	bool d1,d2;
	int iz=0, dr=0;
	d1 = degradadoImagen(v, i, m,iz);
	d2 = degradadoImagen(v, m + 1, j, dr);
	suma = iz + dr;
	return d1 && d2 && iz < dr;
}



bool resuelveCaso() {
	int f, c;
	cin >> f;
	if (!cin)
		return false;
	else cin >> c;
	vector<vector<int>> v(f, vector<int>(c));
	bool degradado = true;
	int i = 0, suma = 0;
	for (int i = 0; i < f; i++)
	for (int j = 0; j < c; j++)
		cin >> v[i][j];

	while (i < f && degradado){
		degradado = degradadoImagen(v[i], 0, c - 1, suma);
		i++;
	}
	if (degradado)
		cout << "SI\n";
	else
		cout << "NO\n";
	
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