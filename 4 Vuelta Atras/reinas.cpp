
#include <iostream>
using namespace std;

void nReinas(int n);
void nReinas(int solucion[], int k, int n);
bool esValida(int solucion[], int k);
void tratarSolucion(int solucion[], int n);

int main()
{
	nReinas(8);
	system("pause");
	return 0;
}


void nReinas(int n){
	int solucion[8];
	nReinas(solucion, 0, n);
}

void nReinas(int solucion[], int k, int n){
	for (int i = 0; i < n; i++){
		solucion[k] = i;
		if (esValida(solucion, k)){
			if (k == n - 1){
				tratarSolucion(solucion, n);
			}
			else{
				nReinas(solucion, k + 1, n);
			}
		}
	}
}

bool esValida(int solucion[], int k) {
	bool correcto = true;
	int i = 0;
	while (i < k && correcto){
		if ( solucion[i] == solucion[k] || abs(solucion[k] - solucion[i]) == k - i)
			correcto = false;
		i++;
	}
	return correcto;
}

void tratarSolucion(int solucion[], int n){
	cout << "Solucion: ";
	for (int i = 0; i < n; i++)
		cout << solucion[i] << " ";
	cout << endl;
}