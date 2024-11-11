#pragma once
#include "Persona.h"

class Profesor : public Persona {
private:
	string grado_academico;
public:
	Profesor(string, string, int, int, string, string);
	Profesor(); 
	virtual ~Profesor(); 
	void set_gradoAcademico(string);
	string get_gradoAcademico();
	string toString();
};

