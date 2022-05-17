#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelve(vector<int>  v);
void resuelveCaso();
int numeroMiradores(vector<int>  v,int N);

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

void resuelveCaso() {
	int numElem;
	bool salir = false;
	do{
		cin >> numElem;
		if (!cin) salir = true;
		else{
			vector<int> v(numElem);
			for (int i = 0; i < numElem; ++i)
				cin >> v[i];
			resuelve(v);
		}
	} while (!salir);
}


void resuelve(vector<int>  v){
	
	//cout << colado << "\n";
	cout << numeroMiradores(v, v.size()) << "\n";
}



int numeroMiradores(vector<int>  v, int N){
	
	int k=N-1;
	int x=1;
	int p=v[N-1];
	while (k!=0){
		if (v[k - 1] > p){
			x++;
			p = v[k - 1];
		}
		k--;
	}
	return x;
}

