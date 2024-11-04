#pragma once
#include <iostream> 
#include <sstream> 
#include <string> 
#include "Lista_Cursos.h"
using namespace std;

class Periodo {
private:
	Lista_Cursos* cursos;
	int Periodo_Seleccionado;
public:
	Periodo();
	Periodo(int);
	virtual ~Periodo();
	void setLista_Cursos(Lista_Cursos*);
	void setPeriodo(int);
	Lista_Cursos* getCursos();
	int getPeriodo();
	string toString();
};
