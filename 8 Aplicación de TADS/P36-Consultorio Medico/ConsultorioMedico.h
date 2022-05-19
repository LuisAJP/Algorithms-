#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <vector>
#include "Fecha.h"
using namespace std;

using medico = string;
using paciente = string;

struct tCita {
	paciente p;
	Fecha f;
};

class Consultorio {

private:
	unordered_map <medico, map<Fecha, paciente>> hmapMedicos;

public:

	void nuevoMedico(medico m) {
		hmapMedicos[m];
	}

	void pideConsulta(const paciente &p, const medico &m, const Fecha &f) {
		if (hmapMedicos.count(m)==0)
			throw domain_error("Medico no existente");
		
		auto it = hmapMedicos[m].find(f);
		if (it != hmapMedicos[m].end())
			throw domain_error("Fecha ocupada");

		hmapMedicos[m][f] = p;//asigno a un medico, una fecha y paciente
		
	}

	paciente siguientePaciente(const medico &m) {
		if (hmapMedicos.count(m) == 0)
			throw domain_error("Medico no existente");
	
		if (hmapMedicos[m].empty())
			throw domain_error("No hay pacientes");
		
		return hmapMedicos[m].begin()->second;//nombre paciente que le toca
	}

	void atiendeConsulta(const medico &m) {

		if (hmapMedicos.count(m) == 0)
			throw domain_error("Medico no existente");
		
		if (hmapMedicos[m].empty())
			throw domain_error("No hay pacientes");
		
		hmapMedicos[m].erase(hmapMedicos[m].begin());
		
	}

	vector<tCita> listaPacientes(const medico &m, int d) {
		vector<tCita> lista;
		tCita elemento;
		if (hmapMedicos.count(m) == 0)
			throw domain_error("Medico no existente");
		
		if (hmapMedicos[m].empty())
			return lista;
			
		for (auto &p : hmapMedicos[m]){
			if (p.first.getDia() == d){
				elemento = { p.second, p.first };
				lista.push_back(elemento);
			}
		}		
		return lista;
	}

};


