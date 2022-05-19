#ifndef persona_h
#define persona_h

#include<string>
#include <iostream>
using namespace std;

class persona{

private:
	int edad;
	string nombre;
	string apellido;
	
public:
	string getNombre() const {
		return this->nombre;
	}

	void setNombre(string nombre){
		this->nombre = nombre;
	}


	string getApellido() const {
		return this->apellido;
	}

	void setApellido(string apellido){
		this->apellido = apellido;
	}


	int getEdad(){

		return edad;
	}

	void setEdad(int edad){
		this->edad = edad;
	}


};

inline std::ostream& operator <<(std::ostream &out, persona const & p) {
	out << p.getNombre()<<""<<p.getApellido()<<"\n";
	return out;
}


#endif /* Persona_h */