#pragma once
#include "Persona.h"
#include "Lista_Grupos.h"

class Profesor : public Persona {
private:
	string grado_academico;
	Lista_Grupos* listaGrupos; 
public:
	Profesor(string, string, int, int, string, string);
	virtual ~Profesor(); 
	void set_gradoAcademico(string);
	string get_gradoAcademico();
	string toString();
};

