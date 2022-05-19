#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Autoescuela {

private:
	struct InfoAlumno {
		int puntos;
		string profesor;
	};

	// Para cada alumno, indica su puntuación y su profesor
	unordered_map<string, InfoAlumno> hmapAlumnos;

	// Para cada profesor, indica su lista de alumnos
	unordered_map<string, set<string>> hmapProfesores;
public:

	// O(1)
	Autoescuela() {}

	// O(log A)
	void alta(string alumno, string profesor) {
		try {
			if (hmapAlumnos.count(alumno)==0)
				throw domain_error("El alumno " + alumno + " no está matriculado");

			InfoAlumno  &info = hmapAlumnos[alumno];
			hmapProfesores[info.profesor].erase(alumno);  // O(log A)
			info.profesor = profesor;
			hmapProfesores[profesor].insert(alumno);      // O(log A)
		}
		catch (domain_error &e) {
			InfoAlumno info = { 0, profesor };
			hmapAlumnos.insert({ alumno, info });       // O(1)
			hmapProfesores[profesor].insert(alumno);  // O(log A)
		}
	}

	// O(1)
	bool es_alumno(string alumno, string profesor)  {
		try {
			if (hmapAlumnos.count(alumno) == 0)
				throw domain_error("El alumno " + alumno + " no está matriculado");

			InfoAlumno  &info = hmapAlumnos[alumno];
			return info.profesor == profesor;
		}
		catch (domain_error &e) {
			return false;
		}
	}

	// O(1)
	int puntuacion(string alumno)  {
		if (hmapAlumnos.count(alumno) == 0)
			throw domain_error("El alumno " + alumno + " no está matriculado");
		
		return hmapAlumnos[alumno].puntos;
	}

	// O(1)
	void actualizar( string alumno, int puntos) {
		if (hmapAlumnos.count(alumno) == 0)
			throw domain_error("El alumno " + alumno + " no está matriculado");

		hmapAlumnos[alumno].puntos += puntos;
		
	}

	// O(log A)
	void aprobar( string alumno) {
		if (hmapAlumnos.count(alumno) == 0)
			throw domain_error("El alumno " + alumno + " no está matriculado");

		InfoAlumno &info = hmapAlumnos[alumno];     // O(1)
		hmapProfesores[info.profesor].erase(alumno);    // O(log A)
		hmapAlumnos.erase(alumno);              // O(1)
	}

	// O(A)
	vector<string> examen(string profesor, int N) const {
		vector<string> result;

		auto it_profesor = hmapProfesores.find(profesor);
		if (it_profesor != hmapProfesores.end()) {
			for (const string &alumno : it_profesor->second) {    // A iteraciones
				const InfoAlumno &info = hmapAlumnos.at(alumno);
				if (info.puntos >= N) {
					result.push_back(alumno);
				}
			}
		}
		return result;
	}
};
