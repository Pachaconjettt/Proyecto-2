#include "Estudiante.h"

Estudiante::Estudiante(string nombre, string id, int telefono, int edad, string email, string especialidad) : Persona(nombre, id, telefono, edad, email) {
	this->especialidad = especialidad;
}
Estudiante::Estudiante(Estudiante* estudiante) : Persona(estudiante->get_nombre(), estudiante->get_id(), estudiante->get_numTelefono(), estudiante->get_edad(), estudiante->get_email()) {
	this->especialidad = estudiante->especialidad;
}
Estudiante::~Estudiante() {}

void Estudiante::set_especialidad(string especialidad) { this->especialidad = especialidad; }
string Estudiante::get_especialidad() { return especialidad; }

string Estudiante::toString() {
	stringstream s;

	s << "Nombre estudiante: " << nombre << endl;
	s << "ID estudiante: " << id << endl;
	s << "Telefono estudiante: " << numTelefono << endl;
	s << "Edad estudiante: " << edad << endl;
	s << "Email estudiante: " << email << endl;
	s << "Especialidad: " << especialidad << endl;

	return s.str();
}