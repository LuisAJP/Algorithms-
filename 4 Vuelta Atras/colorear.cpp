
//Luis Alberto Jaramillo Pulido



//Problema de n letras seleccionadas de m en m con marcaje
#include <iostream>
using namespace std;
const int N = 3;

bool esSolucion(int k, int m);
void tratarSolucion(int solucion[], int m);
void variaciones1(int n, int m);
void variaciones(int solucion[], int k, int n, int m, bool marcas[]);
void inicializarMarcas(bool marcas[], int m);

int main()
{
	variaciones1(3, 3);
	return 0;
}

void inicializarMarcas(bool marcas[], int m){
	for (int i = 0; i < m; i++){
		marcas[i] = false;
	}
}

void variaciones1(int n, int m){
	int solucion[3];//deberia ser int solucion[m] pero no me deja
	bool marcas[3];//
	inicializarMarcas(marcas, m);
	variaciones(solucion, 0, n, m, marcas);
}

bool esSolucion(int k, int m){
	return k == (m - 1);
}

void tratarSolucion(int solucion[], int m){
	cout << "Solucion: ";
	for (int i = 0; i < m; i++)
		cout << solucion[i] << " ";
	cout << endl;
}

bool esValida(int solucion[], int k) {
	int i = 0; bool valida = true;
	while (i < k && valida) {
		if (M.hayFrontera(i, k) && solucion[k] == solucion[i])
			valida = false;
		i++;
	}
	return valida;
}

void colorear(int solucion[], int k, int n, int m){
	for (int c = 0; c < n; c++){
		solucion[k] = c;
		if (esValida(solucion, k)){
			if (esSolucion(k, m)){
				tratarSolucion(solucion, m);
			}
			else{
				colorear(solucion, k + 1, n, m);
			}
		}
	}
}
