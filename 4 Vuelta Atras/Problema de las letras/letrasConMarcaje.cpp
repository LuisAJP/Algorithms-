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

void inicializarMarcas(bool marcas[],int m){
	for (int i = 0; i < m;i++){
		marcas[i] = false;
	}
}
void variaciones1(int n, int m){
	int solucion[3];//deberia ser int solucion[m] pero no me deja
	bool marcas[3];//
	inicializarMarcas(marcas,m);
	variaciones(solucion, 0, n, m,marcas);
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

void variaciones(int solucion[], int k, int n, int m, bool marcas[]){
	for (int letra = 0; letra < n; letra++){
		if (!marcas[letra]){
			solucion[k] = letra;
			if (k == m - 1){//tamaño de una solucion completa se trata solucion
				tratarSolucion(solucion, m);
			}
			else{
				marcas[letra] = true; //marcar
				variaciones(solucion, k + 1, n, m, marcas);
				marcas[letra] = false; // desmarcar
			}
		}
	}
}