#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "hashmap_eda.h"
using namespace std;

struct tInfoProblema{
	bool resuelto = false;
	int fallos = 0;
};

struct tInfoEquipo{
	int resueltos=0;//envios correctos
	int t=0;
	unordered_map<string, tInfoProblema>mapa;// mapa de problemas  
};

struct tInfoResultado{
	string e;// equipo
	int n=0;//numero de problemas resueltos
	int t=0;//tiempo

	bool operator <(tInfoResultado const& r) const{
		return n > r.n ||
			(n == r.n && t < r.t) ||
			(n == r.n && t == r.t && e < r.e);
	}
};

void resuelveCaso(){
	string equipo, problema, veredicto;
	int minuto;

	unordered_map<string, tInfoEquipo> mapa;//equipo e info equipo

	while (cin >> equipo, equipo != "FIN"){
		cin >> problema >> minuto >> veredicto;// lee problema, tiempo y veredicto
		// si el problema todavia no ha sido resuelto
		if (!mapa[equipo].mapa[problema].resuelto){
			if (veredicto == "AC"){
				mapa[equipo].mapa[problema].resuelto = true;
				++mapa[equipo].resueltos;
				//actualiza el tiempo del equipo 
				//tiempo equipo(minutos) + tiempo problema(minuto) + tiempo penalizacion(minutos)
				mapa[equipo].t += minuto + mapa[equipo].mapa[problema].fallos * 20;
			}
			else
				++mapa[equipo].mapa[problema].fallos;
		}
		//en caso contrario si el problema ha sido resuelto envios posteriores se ignoran
	}

	vector<tInfoResultado> resultados;
	tInfoResultado re;

	for (auto const& x : mapa){
		re.e = x.clave; re.n = x.valor.resueltos; re.t = x.valor.t;
		resultados.push_back(re);
	}

	sort(resultados.begin(),resultados.end());//ordena el vector menor a mayor

	for (auto const & r : resultados)
		cout << r.e << " " << r.n << " " << r.t << "\n";
	
	cout << "---\n";
}

int main(){
#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto buffer = cin.rdbuf(in.rdbuf());
#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	cin.rdbuf(buffer);
	system("pause");
#endif
	return 0;

}
