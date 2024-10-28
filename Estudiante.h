#pragma once
#include "Persona.h"

class Estudiante : public Persona {

private:
	string especialidad;
public:
	Estudiante(string, string, int, int, string, string);
	Estudiante(Estudiante*);
	virtual ~Estudiante();

	void set_especialidad(string);
	string get_especialidad();

	string toString();
};