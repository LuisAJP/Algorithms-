#ifndef fecha_h
#define fecha_h
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Fecha{
	int dia;
	int hora;
	int min;

public:
	Fecha(int d, int h, int m) : dia(d), hora(h), min(m) {
		if (d<1 || d > 30) 
			throw domain_error("Dia no valido");

		else if (h<0 || h > 23) 
			throw domain_error("Dia no valido");

		else if (m<0 || m > 59) 
			throw domain_error("Dia no valido");
	}

	Fecha() {};

	~Fecha() {};

	bool operator<(Fecha f) const {

		if (dia< f.dia) 
			return true;
		else if (dia > f.dia) 
			return false;
		else{
			if (hora< f.hora) 
				return true;
			else if (hora > f.hora) 
				return false;
			else{
				if (min < f.min) 
					return true;
				else 
					return false;
			}
		}
	}

	int getDia() const { 
		return dia; 
	}

	int getMin() const {
		return hora;
	}

	int getHora() const { 
		return min; 
	}

	void display() {
		cout << setw(2) << setfill('0');
		cout<< hora << ":" << setw(2) << setfill('0') << min;
	}

};
#endif
