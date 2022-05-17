//Nombre y apellidos



#include <stdio.h>
#include <iostream>
using namespace std;



const unsigned int MAX=100000;

//Define aqui tu funcion recursiva

//...

//Analisis y justificacion del coste

void resuelve() {
   int elementos[MAX];
   int numElems;
     //lectura de los datos, numElems>=1
   cin >> numElems;
   for (int i=0;i<numElems;i++) {cin>>elementos[i];}
  
    
    //Calcula el resultado en la variable pos
    int pos;
    
    //Llama aqui a tu funcion recursiva
    
    cout << pos << endl;
}



int main() {
    // ajuste para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
    std::ifstream in("sample1.in");
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
