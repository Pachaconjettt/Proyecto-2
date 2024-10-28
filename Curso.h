#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Grupo.h"
using namespace std;

class Curso {
private:
	string nombre;
	string id;
	int horas;
	int precio;
	bool estado;
	Grupo* group;
	
public:
	Curso();
	Curso(string, string, int, int, bool,Grupo*);
	Curso(Curso*);
	virtual ~Curso();

	void set_nombre(string);
	void set_id(string);
	void set_horas(int);
	void set_precio(int);
	void set_estado(bool);
	void setGrupo(Grupo*);

	string get_nombre();
	string get_id();
	int get_horas();
	int get_precio();
	bool get_estado();
	Grupo* getGrupo();

	string toString();
};