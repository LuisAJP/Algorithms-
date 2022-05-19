
#include <iostream>
#include <fstream>
#include <string>
#include "ConsultorioMedico.h"
using namespace std;


bool resuelveCaso() {

	int numOperaciones;
	cin >> numOperaciones;

	if (!cin) return false;

	string comando,m,p;
	Fecha f;
	char c;
	Consultorio consultorio;

	for (int i = 0; i < numOperaciones; i++){
		try {
			cin >> comando;
			if (comando == "nuevoMedico") {
				cin >> m;
				consultorio.nuevoMedico(m);
			}
			else if (comando == "pideConsulta") {
				int dia, hora, minuto;
				cin >> p >> m >> dia >> hora >>c>>minuto;
				f = Fecha(dia, hora, minuto);
				consultorio.pideConsulta(p, m, f);
			}
			else if (comando == "listaPacientes") {
				int dia;
				cin >> m>>dia;
		
				vector<tCita> l = consultorio.listaPacientes(m, dia);
				cout << "Doctor " << m << " " << "dia " << dia << "\n";
				for (auto &x : l){
					cout << x.p << " ";
					x.f.display();
					cout << "\n";
				}
			
			}
			else if (comando == "siguientePaciente") {
				cin >> m;
				p = consultorio.siguientePaciente(m);
				cout << "Siguiente paciente doctor " << m << "\n";
				cout<< p << "\n";
			
			}
			else if (comando == "atiendeConsulta"){
				cin >> m;
				consultorio.atiendeConsulta(m);
			}
		}
		catch (exception & e) {
			cout << e.what() << "\n";
		}
	}

	cout << "---\n";

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

}
