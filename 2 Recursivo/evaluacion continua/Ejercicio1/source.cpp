//Nombre y apellidos
//Carlos Luengo Heras
//Luis Alberto Jaramillo Pulido
//Problema 1

//Coste O(N) donde N es el tamaño del vector, el coste es lineal, en el caso peor tendria que ir 
//comparar el elemento actual con el primer elemento
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int resolver(const vector<int> &v, int j);


const unsigned int MAX=100000;

//Define aqui tu funcion recursiva

//...
int resolver(const vector<int> &v, int j) {
	if (j == 0) {
		return j;
	}
	else {
		if (v[j] == v[j - 1]) {
			resolver(v, j - 2);
		}
		else {
			return j;
		}
	}
}

//Analisis y justificacion del coste
//Coste O(N) donde N es el tamaño del vector, el coste es lineal, en el caso peor tendria que ir 
//comparar el elemento actual con el primer elemento

void resuelve() {
   //int elementos[MAX];
	
   int numElems;
   
     //lectura de los datos, numElems>=1
   cin >> numElems;
   vector<int>v(numElems);
   for (int i=0;i<numElems;i++) {
	   cin >> v[i];
   }
  
    
    //Calcula el resultado en la variable pos
   int pos = resolver(v,v.size()-1);
    
    //Llama aqui a tu funcion recursiva
    
    cout << pos << endl;
}



int main() {
    // ajuste para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
   #endif
    
    unsigned int numCasos;
    cin >> numCasos;
    // Resolvemos
    while (numCasos--) {
       resuelve();
	}
    
    
    // restablecimiento de cin
    
   #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
   #endif
    
	return 0;
}
