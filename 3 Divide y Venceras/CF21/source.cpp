
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct{
	bool ok;
	int suma;
}tInfo;

tInfo degradado(const vector<int> &v,int i,int j){
	if (j == i+1)
		return{ v[i] < v[j], v[i] + v[j] };
	int m = (i + j) / 2;
	tInfo iz,dr,r;
	iz = degradado(v, i, m);
	dr = degradado(v, m + 1, j);
	r.suma = iz.suma+ dr.suma;
	r.ok = iz.ok&& dr.ok && iz.suma < dr.suma;
	return r;
}



bool resuelveCaso() {

	//leer datos
	int f, c;
	cin >> f;
	if (!cin)
		return false;
	else cin >> c;
	vector<vector<int>> v(f, vector<int>(c));

	for (int i = 0; i < f; i++)
	for (int j = 0; j < c; j++)
		cin >> v[i][j];

	tInfo info;
	info.ok = true;
	info.suma = 0;
	int i = 0;
	while (i < f && info.ok){
		info=degradado(v[i],0,c-1);
		i++;
	}
	if (info.ok)
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