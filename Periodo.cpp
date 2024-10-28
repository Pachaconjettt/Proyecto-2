#include "Periodo.h"

Periodo::Periodo(string periodo) {
	this->periodo = periodo;
	cantidad_cursos = 0;
	inicializar_listaCursos();
}
Periodo::~Periodo() { delete[] lista_cursos; }

void Periodo::set_periodo(string periodo) { this->periodo = periodo; }
bool Periodo::ingresar_curso(Grupo* curso) {
	if (curso != nullptr && cantidad_cursos < NUM_CURSOS && buscar_curso(curso->get_curso()->get_id()) == false) {
		lista_cursos[cantidad_cursos] = curso;
		cantidad_cursos++;
		return true;
	}
	return false;
}
bool Periodo::eliminar_curso(string id) {
	for (int i = 0; i < cantidad_cursos; i++) {
		if (lista_cursos[i] != nullptr && lista_cursos[i]->get_curso()->get_id() == id) {
			lista_cursos[i] = nullptr;

			for (int j = i; j < cantidad_cursos - 1; j++) {
				lista_cursos[j] = lista_cursos[j + 1];
			}
			lista_cursos[cantidad_cursos - 1] = nullptr;
			cantidad_cursos--;
			return true;
		}
	}
	return false;
}

string Periodo::get_periodo() { return periodo; }
bool Periodo::buscar_curso(string id) {
	for (int i = 0; i < cantidad_cursos; i++) {
		if (lista_cursos[i]->get_curso()->get_id() == id) {
			return true;
		}
	}
	return false;
}
Grupo* Periodo::get_curso(string id) {
	for (int i = 0; i < cantidad_cursos; i++) {
		if (lista_cursos[i]->get_curso()->get_id() == id) {
			return lista_cursos[i];
		}
	}
	return nullptr;
}

string Periodo::toString() {
	stringstream s;

	s << "-------------------Periodo-------------------" << endl;
	s << "Periodo :" << periodo << endl << endl;
	s << "Cursos: " << endl;
	for (int i = 0; i < cantidad_cursos; i++) {
		s << lista_cursos[i]->toString();
	}
	s << "----------------------------------------------" << endl;
	return s.str();
}