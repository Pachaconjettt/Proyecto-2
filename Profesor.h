#pragma once
#include "Persona.h"
//#include "Lista_Grupos.h"

class Profesor : public Persona {
private:
	string grado_academico;
	/*Lista_Grupos* listaGrupos; NO TOMAR EN CUENTO LO PUESTO EN COMENTARIOS*/
public:
	Profesor(string, string, int, int, string, string);
	Profesor(); 
	virtual ~Profesor(); 
	void set_gradoAcademico(string);
	//void matricularProfeEnGrupo(Grupo*);
	string get_gradoAcademico();
	string toString();
};

