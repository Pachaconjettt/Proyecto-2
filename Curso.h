#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Lista_Grupos.h"
#include  "Lista_Profesores.h"
using namespace std;

class Curso {
private:
	string nombre;
	string id;
	int horas;
	int precio;
	bool estado;
	Lista_Profesores* profes;
	Lista_Grupos* grupos; 
	
public:
	Curso();
	Curso(string, string, int, int, bool);
	virtual ~Curso();

	void set_nombre(string);
	void set_id(string);
	void set_horas(int);
	void set_precio(int);
	void set_estado(bool);
	void setProfeLista(Lista_Profesores*);
	void setGrupoLista(Lista_Grupos*);

	string get_nombre();
	string get_id();
	int get_horas();
	int get_precio();
	bool get_estado();
	Lista_Profesores* getProfeLista();
	Lista_Grupos* getGrupoLista();

	string toString();
};
