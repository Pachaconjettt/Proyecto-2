#include "Persona.h"

Persona::Persona() {
	nombre = " ";
	id = " ";
	numTelefono = 0;
	edad = 0;
	email = " ";
	/*horario = new Horario();*/
}
Persona::Persona(string nombre, string id, int numTelefono, int edad, string email) {
	this->nombre = nombre;
	this->id = id;
	this->numTelefono = numTelefono;
	this->edad = edad;
	this->email = email;
	/*horario = new Horario();*/
}
Persona::~Persona() {}

void Persona::set_nombre(string nombre) { this->nombre = nombre; }
void Persona::set_id(string id) { this->id = id; }
void Persona::set_numTelefono(int numTelefono) { this->numTelefono = numTelefono; }
void Persona::set_edad(int edad) { this->edad = edad; }
void Persona::set_email(string email) { this->email = email; }

string Persona::get_nombre() { return nombre; }
string Persona::get_id() { return id; }
int Persona::get_numTelefono() { return numTelefono; }
int Persona::get_edad() { return edad; }
string Persona::get_email() { return email; }
//Horario* Persona::get_horario() { return horario; }