#include "Profesor.h"

Profesor::Profesor(string nombre, string id, int telefono, int edad, string email, string grado_academico) : Persona(nombre, id, telefono, edad, email) {
	this->grado_academico = grado_academico;
}
Profesor::Profesor() : Persona ("disponible","indef",-1,-1,"indef") {
	this->grado_academico = "indef";
}
Profesor::~Profesor() {}

void Profesor::set_gradoAcademico(string grado_academico) { this->grado_academico = grado_academico; }
string Profesor::get_gradoAcademico() { return grado_academico; }

string Profesor::toString() {
	stringstream s;
	s << "Nombre profesor: " << nombre << endl;
	s << "ID profesor: " << id << endl;
	s << "Telefono profesor: " << numTelefono << endl;
	s << "Edad profesor: " << edad << endl;
	s << "Email profesor: " << email << endl;
	s << "Grado academico: " << grado_academico << endl;
	return s.str();
}
//void Profesor::matricularProfeEnGrupo(Grupo* grupos) {
//	listaGrupos->insertarInicio(grupos);
// NO ERA COMO DECIA, grupos van en profesores
//}