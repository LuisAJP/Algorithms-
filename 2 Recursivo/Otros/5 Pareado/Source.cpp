

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
void resuelveCaso();
bool pareado(vector<int> v, int num);
bool pareado(vector<int> v, int i, int j);
int contarPares(vector<int> v, int ind, int m);

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos;i++){
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}



void resuelveCaso(){

	int numElem;
	cin >> numElem;
	vector<int> v(numElem);
	for (int i = 0; i < numElem;i++){
		cin >> v[i];
	}
	if (pareado(v, numElem)) cout << "SI" << "\n";
	else 
		cout << "NO" << "\n";
}

bool pareado(vector<int> v, int num) {
	return pareado(v, 0, num);
}

bool pareado(vector<int>v, int i, int j) {
	bool b;
	int m;
	if (j <= i + 1) 
		b = true;
	else{
		m = (i + j) / 2;
		b = (abs(contarPares(v, i, m) - contarPares(v, m, j)) <= 1) && pareado(v, i, m) && pareado(v, m, j);
	}
		
	return b;

}




int contarPares(vector<int> v, int ind, int m){
	int cont = 0;
	for (int i = ind; i < m;i++){
		if (v[i]%2==0){
			cont++;
		}
	}
	return cont;
}