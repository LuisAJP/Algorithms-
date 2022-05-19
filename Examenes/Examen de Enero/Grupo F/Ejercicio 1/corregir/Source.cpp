/*
Tema:Iterativos
Problema Ejercicio 1 del examen de Febrero
Autor: Luis Alberto Jaramillo Pulido
team: F59
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


/*
1)ESPECIFICACION

P={ N>=0 && long(v)=N}
fun (v:vector<int>, int N) return maximo:int

Q={maximo= max p,q: 0<=p<q < N && consecutivos(v,p,q): q-p}
consecutivos(v,p,q) = Forall i: p <= i < q: (|v[i]-v[i+1]|=1)

3)INVARIANTE    (r es igual a maximo en el codigo)

Invariante = {0<=i<=N && r = max p,q: 0<=p<q< i && consecutivos(v,p,q): q-p &&  maximo= max u:0<=p<q< i: consecutivos(v,p,q)
&& contador = #w::0<=p<q< i: consecutivos v,p,q)}

4) COSTE Y FUNCION DE COTA

El coste es lineal O(n) , en todos los casos recorre el vector completo. El bucle da N vueltas cada una de ellas de coste constante y por tanto el coste está en O(N).


Funcion de cota = N - i
*/

int resuelve(const vector<int> &v, int N){
	int i = 0;
	int cont = 0;
	int maximo = 0;
	while (i < N){
		if (i==0 || abs(v[i - 1] - v[i]) == 1)
			cont++;
		else
			cont = 1;
		maximo = max(maximo, cont);
		i++;
	}
	return maximo;
}


void resuelveCaso(){
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++){
		cin >> v[i];
	}

	int longitud = resuelve(v, N);
	cout << longitud;
	cout << "\n";

}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	//while (resuelveCaso());
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();

	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


