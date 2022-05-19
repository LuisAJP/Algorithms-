/*
Tema:11
Problema 39 Venta Libros
Autor: Luis Alberto Jaramillo Pulido
team:F33
*/



#include<iostream>
#include<fstream>
#include "ventaLibros.h"
using namespace std;

	
bool resuelveCaso(){
	int N;
	cin >> N;
	if (!cin)return false;
	string cadena,x;
	int n;
	ventaLibros venta;
	for (int i = 0; i < N; i++){
		try{
			cin >> cadena;
			if (cadena == "nuevoLibro"){
				cin >> n;
				getline(cin, x);
				venta.nuevoLibro(n, x);
			}
			else if (cadena == "comprar"){
				getline(cin, x);
				venta.comprar(x);
			}
			else if (cadena == "estaLibro"){
				getline(cin, x);
				if (venta.estaLibro(x) == 1)
					cout << "El libro" << x << " esta en el sistema\n";
				else
					cout << "No existe el libro " << x << " en el sistema\n";
			}
			else if (cadena == "elimLibro"){
				getline(cin, x);
				venta.elimLibro(x);
			}
			else if (cadena == "numEjemplares"){
				getline(cin, x);
				try{
					int m = venta.numEjemplares(x);
					cout << "Existen " << m << " ejemplares del libro" << x<<"\n";
				}
				catch (exception& e){
					cout << "No existe el libro " << x << " en el sistema\n";
				}
			}
			else if (cadena == "top10"){
				cout << "TOP10\n";
				list<string>l=venta.top10();
				for (auto y : l)
					cout << "    "<<y<<"\n";
			}
		}
		catch (exception& e){
			cout << e.what() << "\n";
		}
	}
	cout << "---\n";
	return true;
}


int main(){
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto buf = cin.rdbuf(in.rdbuf());//establece el puntero al objeto del buffer fichero

#endif
	
	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(buf);//devuelve el puntero al objeto del buffer
	system("pause");
#endif
	return 0;

}