#pragma once
#include <iostream> 
#include <sstream> 
#include <string> 
#include "Horario.h"
using namespace std;

class Persona {
protected:
	string nombre;
	string id;
	int numTelefono;
	int edad;
	string email;
	Horario* horario;
public:
	Persona();
	Persona(string, string, int, int, string);
	virtual ~Persona();

	void set_nombre(string);
	void set_id(string);
	void set_numTelefono(int);
	void set_edad(int);
	void set_email(string);

	string get_nombre();
	string get_id();
	int get_numTelefono();
	int get_edad();
	string get_email();
	Horario* get_horario();

	string virtual toString() = 0;
};