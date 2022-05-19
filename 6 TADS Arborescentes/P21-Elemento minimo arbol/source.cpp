
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;



template <class T>
T metasolve(bintree<T> &tree){
	typename bintree<T>::const_iterator it = tree.begin();
	T minimum;
	minimum = *it;
	for (++it; it != tree.end(); ++it)
		minimum = min(minimum, *it);
	return minimum;
}

template <class T>
void metaIO(const T &empty)
{
	bintree<T> tree;
	tree = leerArbol(empty);
	cout << metasolve(tree) << endl;
}


bool resuelveCaso(){
	char C;
	cin >> C;
	if (!cin)return false;
	
	if (C == 'N') 
		metaIO<int>(-1);
	else  
		metaIO<string>("#");
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
