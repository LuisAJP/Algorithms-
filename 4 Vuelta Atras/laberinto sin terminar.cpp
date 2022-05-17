#include <iostream>
using namespace std;

const int N = 5;
//Prototipo
void laberinto(bool lab[N][N], casilla solucion[], int k, int n, bool marcas[N][N], bool &exito);
bool esValida(bool lab[N][N], casilla c, int n, const bool marcas[N][N]);
casilla sigDireccion(int dir, casilla pos);
bool esSolucion(casilla pos, int n)

int main()
{
	
	bool Laberinto[N][N];
	InicializarLab(Laberinto, N);
	bool marcas[N][N];
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		marcas[i][j] = false;
	casilla sol[N*N];
	sol[0].fila = 0;
	sol[0].columna = 0;
	marcas[0][0] = true;
	bool exito = false;
	laberinto(Laberinto, sol, 1, N, marcas, exito);
	return 0;
}

void laberinto(bool lab[N][N], casilla solucion[], int k, int n,bool marcas[N][N], bool &exito){
	int dir = 0;
	while ((dir < 4) && !exito){
		solucion[k] = sigDireccion(dir, solucion[k - 1]);
		if (esValida(lab, solucion[k], n, marcas)){
			if (esSolucion(solucion[k], n)){
				tratarSolucion(solucion, k);
				exito = true;
			}
			else{
				// marcar
				marcas[solucion[k].fila][solucion[k].columna] = true;
				laberinto(lab, solucion, k + 1, n, marcas, exito);
				// de smar car
				//marcas [ s o l u c i o n [ k ] . f i l a ] [ s o l u c i o n [ k ] . columna ] = f a l s e ;
			}
		}
		dir++;
	}
}

bool esValida(bool lab[N][N], casilla c, int n, const bool marcas[N][N]){
	return c.fila >= 0 && c.columna >= 0 && c.fila < n && c.columna < n
		&& lab[c.fila][c.columna] && !marcas[c.fila][c.columna];
}


casilla sigDireccion(int dir, casilla pos){
	switch (dir) {
	case 0:
		++pos.columna;
		break;
	case 1:
		++pos.fila;
		break;
	case 2:
		--pos.columna;
		break;
	case 3:
		--pos.fila;
		break;
	default:
		break;
	}
	return pos;
}

bool esSolucion(casilla pos, int n){
	return pos.fila == n - 1 && pos.columna == n - 1;
}