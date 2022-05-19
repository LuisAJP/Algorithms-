
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


struct tInfo{
	int maximo;
	int minimo;
	bool ok;
};

tInfo esABB(const bintree<int> &a){
	if (a.empty())
		return{ 0, 0, true };
	tInfo iz, dr, info;
	info = {-1,-1,false};
	
	iz = esABB(a.left());
	dr = esABB(a.right());

	int r = a.root();

	//es hoja
	if (a.left().empty() && a.right().empty())
		return{r,r,true};

	if (r == 8){
		cout << "";
	}

	
	if (iz.ok && dr.ok){

		if (!a.left().empty() && !a.right().empty()){
			if (r > iz.minimo && r < dr.maximo){
				info.ok = true;

			}
			else
				info.ok = false;
		}
		else if (!a.left().empty() && a.right().empty()){
			if (r > iz.maximo){
				info.ok = true;
			}
			else{
				info.ok = false;
			}
				
		}

		else if (a.left().empty() && !a.right().empty()){
			if (r < dr.minimo){
				info.ok = true;
			}
			else{
				info.ok = false;
			}
				
		}
		info.minimo = max(iz.minimo, r);
		info.maximo = min(dr.maximo,r);
		
	}
	return info;
}

void resuelveCaso() {
	bintree<int>a;
	a = leerArbol(-1);
	tInfo info = esABB(a);
	if (info.ok)
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) 
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

}
