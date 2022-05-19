
/*
Tema:9
Problema 84
Autor: Luis Alberto Jaramillo Pulido
team: F33
*/


#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "bintree_eda.h"
#include <iostream>
#include <sstream>
using namespace std;


bintree<int> reconstruccion(const vector<int> &preorder, int i, int j, const vector<int> &inorder, int x, int y){
	if (j - i == 0)
		return bintree<int>();
	int p;
	for (p = 0; p + x<y && inorder[p + x] != preorder[i]; p++); 
	bintree<int> iz = reconstruccion(preorder, i + 1, i + p + 1, inorder, x, x + p);
	bintree<int> dr = reconstruccion(preorder, i + p + 1, j, inorder, x + p + 1, y);
	
	return bintree<int>(iz, preorder[i], dr);
}

// resuelve un caso de prueba
bool resuelveCaso() {
	string n;
	getline(cin, n);
	
	if (!cin)return false;
	
	
	vector<int>preorder;
	vector<int>inorder;
	
	int valor;
	stringstream ss1(n);

	while (ss1 >> valor)
		preorder.push_back(valor);


	getline(cin, n);
	stringstream ss2(n);
	while (ss2 >> valor)
		inorder.push_back(valor);

	bintree<int>postorder = reconstruccion(preorder,0,inorder);
	return true;
	
}

int main() {


	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;

}
