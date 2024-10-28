#pragma once
#include <iostream> 
#include <sstream> 
#include <string> 
#include "Grupo.h"
#define NUM_CURSOS 3
using namespace std;

class Periodo {
protected:
	string periodo;
	int cantidad_cursos;
	Grupo** lista_cursos;

	void inicializar_listaCursos() {
		lista_cursos = new Grupo * [NUM_CURSOS];

		for (int i = 0; i < NUM_CURSOS; i++) {
			lista_cursos[i] = nullptr;
		}
	}
public:
	Periodo(string);
	virtual ~Periodo();

	void set_periodo(string);
	bool ingresar_curso(Grupo*);
	bool eliminar_curso(string);

	string get_periodo();
	bool buscar_curso(string);
	Grupo* get_curso(string);

	string toString();
};
