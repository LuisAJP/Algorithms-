#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//int resolver(const vector<int> &v, int j);

void abrigo(vector <int>solucion, vector <int>v, vector <int>w, int k, int &cont);
void inicializar(vector <int> &s);
bool esValida(vector <int>solucion, int k);

bool resuelve() {
   //int elementos[MAX];
	
   int numDias,numAbrigos,combinaciones;
   
   //lectura de los datos
   cin >> numDias>>numAbrigos;
   if (numDias != 0 & numAbrigos != 0){
	   vector<int>v(numDias);
	   for (int i = 0; i < numDias; i++) {
		   cin >> v[i];
	   }
	   vector<int>w(numAbrigos);
	   for (int i = 0; i < numAbrigos; i++) {
		   cin >> w[i];
	   }
	   
	   vector<int>solucion(numDias);
	   inicializar(solucion);
	   int cont = 0;
	   abrigo(solucion,v,w,0,cont);
	   cout << cont << "\n";
	   return true;
   }
   else
	   return false;
}

void inicializar(vector <int> &s){

	for (int i = 0; i < s.size();i++){
		s[i] = 0;
	}
}

void abrigo(vector <int>solucion,vector <int>v, vector <int>w, int k, int &cont){

	for (int i = 0; i < w.size();i++){
		solucion[k] = i;
		//funcion de poda
		if (esValida(solucion,k)){
			//Si es solucion  Completa
			if (k==w.size()-1){
				//tratarSolucion
				cont++;
			}
			//si no 
			//llamada recursiva
			else{
				abrigo(solucion,v,w,k+1,cont);
			}
		}
	}

}


bool esValida(vector <int>solucion, int k){
	int i = 0;
	//abrigos sin repetir 2 dias seguidos
	while (i <k && solucion[i]!=solucion[k])
		i++;
	return i == k;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
   #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
   #endif
    
    // Resolvemos
	while (resuelve()) {
       
	}
    
    
    // restablecimiento de cin
    
   #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
   #endif
    
	return 0;
}
