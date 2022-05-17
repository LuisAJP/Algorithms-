#include <iostream>
#include <fstream>
using namespace std;

const int N=50;
float precio[N][N];
//Prototipos

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	

#endif

	

	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");

#endif

	return 0;
}


void compra(int sol[], int k, int solOpt[],float &costeAct, float &costeMin, int marcas[]){

	for (int i = 0; i < N; i++){
		sol[k] = i;
		costeAct = costeAct + precio[k][i];
		marcas[i]++;
		if (marcas[i]<=3){
			if (k == N - 1){
				if (costeAct < costeMin){
					costeMin = costeAct;
					copiaSol(solOpt, sol);
				}
			}
			else
				compra(sol,k+1,solOpt,costeAct,costeMin,marcas);
		
		}
		costeAct = costeAct - precio[k][i];
		marcas[i]--;
	}
}