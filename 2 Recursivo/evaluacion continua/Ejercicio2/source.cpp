//Nombre y apellidos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>



//...

//Analisis y justificacion del coste
// O(logN) El coste es linela, donde N es el tamaño del vector, tengo que ir comprobando las 2 mitades, la mitad izquierda y la derecha si son dispersas
//Define aqui tu funcion recursiva


bool disperso(int k, int i, int j);

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelve(std::vector<int> v, int k, int i, int j);
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (!std::cin) return false;
    int K;
    std::cin >> K;
    std::vector<int> v(num);
    for (int & n: v) std::cin >> n;
    
    bool b;
	b = resuelve(v, K, 0, v.size()-1);
	//b = resuelve(v, 0, v.size());
    //Llama aqui a tu funcion recursiva 
    if (b) std::cout << "SI\n";
    else std::cout << "NO\n";
    return true;
}



bool resuelve(std::vector<int> v, int k, int i, int j) {
	bool r=false;
	int m = (i + j) / 2;
	if (v.size() == 1){
		if (v[0]>=k){
			r = true;
			return r;
		}
		else
			return r;		
	}
	if (j == i + 1) {
		if (disperso(k, v[i], v[j]))
			r = true;
		else
			r = false;
	}
	else
		r = disperso(k,v[i],v[j]) && resuelve(v, k,i, m) && resuelve(v, k,m+1, j);
	return r;

}

bool disperso(int k,int i, int j){
	bool r = false;
	int a = abs(i - j);
	if (a>=k){
		r = true;
	}
	return r;
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
    system("PAUSE");
#endif

    return 0;
}
