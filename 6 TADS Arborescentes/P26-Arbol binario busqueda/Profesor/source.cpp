
/*


Title: Es un arbol equilibrado

*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <iostream>
using namespace std;

struct tInfo{
	int min;
	int max;
	bool ok;
};

bool isBalancedG(const bintree<int> &a, int &maxM, int &minM)
{
	if (a.empty())
		return true;

	if (a.left().empty() && a.right().empty()){
		maxM = minM = a.root();
		return true;
	}

	if (a.right().empty() && !a.left().empty()){
		int maxL, minL;
		bool left = isBalancedG(a.left(), maxL, minL);
		maxM = a.root();
		minM = minL;
		return left && (maxL<a.root());
	}

	if (a.left().empty() && !a.right().empty()){
		int maxR, minR;
		bool right = isBalancedG(a.right(), maxR, minR);
		maxM = maxR;
		minM = a.root();
		return right && (minR>a.root());
	}

	if (!a.left().empty() && !a.right().empty()){
		int maxR, minR;
		bool right = isBalancedG(a.right(), maxR, minR);
		int maxL, minL;
		bool left = right && isBalancedG(a.left(), maxL, minL); 
		maxM = maxR;
		minM = minL;
		return right && left && (maxL< a.root()) && (minR > a.root());
	}
	return false; // never reached.
}

bool isBalanced(const bintree<int> &tree)
{
	int maxM, minM;
	return isBalancedG(tree, maxM, minM);
}



void resuelveCaso() {
	bintree<int> a;
	a = leerArbol(-1);
	bool ok;
	cout << (isBalanced(a) ? "SI" : "NO") << endl;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
