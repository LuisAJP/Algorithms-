#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct{
	int a;
	int r;
	int v;
}tInfo;


//El coste de la funcion valida es de orden O(1), el coste es constante
bool esValida(const vector<int> &sol, int k, const vector<int> &colores,int total, int N, tInfo info ){
	//Si la primera pieza de color no es roja
	if (k == 0 && sol[k]!=1)
		return false;
	if (k > 0){
		if (sol[k] == 2){//si la pieza de color es verde
			if (sol[k - 1] == 2)//no puede haber 2 piezas verde juntas
				return false;
			if (colores[sol[k]] > colores[0])//numero de piezas verdes supere al numero de azules
				return false;
		}
		if (k == N - 1){//si en la torre final
			int resto = total - colores[1];//numero resto de colores
			if (colores[1] <= resto)//el numero de piezas rojas debe ser mayor al resto
				return false;
		}
		
	}
	//el numero de colores de la solucion no debe ser mayor que la cantidad de numero de colores iniciales
	if (colores[0] > info.a || colores[1] >info.r || colores[2] > info.v)
		return false;
	return true;
}

//imprimir solucion
void imprimir(const vector<int> &sol,int N){
	for (int i = 0; i < N; i++){
		if (sol[i] == 0)
			cout << "azul" << " ";
		if (sol[i] == 1)
			cout << "rojo" << " ";
		if (sol[i] == 2)
			cout << "verde" << " ";
	}
	cout << "\n";
}
void torreColores(tInfo info, int k, int N, vector<int> sol, 
vector<int> colores, int total, bool &haySolucion){
	
	for (int i = 0; i < 3;i++){
		sol[k] = i;
		colores[i]++;
		total++;
		if (esValida(sol,k,colores,total,N,info)){
			if (k == N - 1) { //tratar solucion
				haySolucion = true;
				imprimir(sol,N);
			}
			else//caso recursivo
				torreColores(info, k + 1, N, sol,colores,total,haySolucion);
		}
		colores[i]--;
		total--;
	}
}

bool resuelveCaso(){
	int N;//Altura
	tInfo info;//azul,rojo,verde
	cin >> N >> info.a >> info.r >> info.v;
	if (N == 0)
		return false;
	vector<int> sol(N,-1);
	vector<int> colores(3,0);
	int total = 0;
	bool haySolucion=false;
	torreColores(info,0,N,sol,colores,total,haySolucion);
	if (!haySolucion)
		cout << "SIN SOLUCION\n";
	cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE

	while (resuelveCaso());
		

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif // !DOMJUDGE

	return 0;
}
