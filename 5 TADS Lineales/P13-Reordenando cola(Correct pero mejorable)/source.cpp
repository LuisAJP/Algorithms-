
#include <iostream>
#include <fstream>
#include "list_eda.h"
using namespace std;


bool resuelveCaso() {

	int N, n;
	cin >> N;
	if (N == 0)return false;
	list<int> l;
	list<int> l2;
	for (int i = 0; i < N; i++){
		cin >> n;
		l.push_back(n);
	}
	int a=l.front();l.pop_front();
	l2.push_back(a);
	int b;
	for (int i = 1; i < N;i++){
		b=l.front();
		if (a>=b && a<0 || b<0){
			l.pop_front(); l2.push_front(b);
		}	
		else {
			l.pop_front(); l2.push_back(b);
		}
			
		a = b; 
	}
	for (int a:l2){
		cout << a << " ";
	}
	cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	
#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

}
