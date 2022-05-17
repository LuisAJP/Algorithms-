
//Luis Alberto Jaramillo Pulido

/*
{0 <= num < longitud(v) ^ ord(v, num)}
fun buscaBin (TElem v[], int num, TElem x) return int pos
{(existe u : 0 <= u < num: v[u] <= x ^ pos = max k : (0 <= k <= num − 1) ^ v[k] <= x : k)
||(forall z : 0 <= z < num: x < v[z] ^ pos = −1)}

pos = max k : (0 <= k <= num − 1) ^ v[k] <= x : k//Esto quiere que en el caso de que haya elementos repetidos
pos tomara la posicion de mayor valor
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//dr,si hay elementos repetidos buscamos la aparicion mas a la derecha
int buscaBin(vector<int> v, int x, int a, int b) {
	int p, m;
	if (a == b + 1)//caso base
		p = a - 1;
	else { //Caso Recursivo a <= b
		m = (a + b) / 2;
		if (v[m] <= x)
			p = buscaBin(v, x, m + 1, b);
		else//iz
			p = buscaBin(v, x, a, m - 1);
	}
	return p;
}

void resuelveCaso(){
	int N, x;
	cin >> N>> x;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	int pos = buscaBin(v, x,0,N-1);
	if (pos==-1 || v[pos] != x )
		cout << "-1\n";
	else
		cout << pos << "\n";
}


int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}






