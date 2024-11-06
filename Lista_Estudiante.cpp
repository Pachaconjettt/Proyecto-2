#include "Lista_Estudiante.h"
Nodo_Estudiante::Nodo_Estudiante(Estudiante* student, Nodo_Estudiante* next) {
	this->theStudent = student; 
	this->next = next;
 }
Nodo_Estudiante::~Nodo_Estudiante() {
	delete this->theStudent;
}
void Nodo_Estudiante::setEstudiante(Estudiante* student) { this->theStudent = student;  }
void Nodo_Estudiante::setNext(Nodo_Estudiante* next) { this->next = next; }
Estudiante* Nodo_Estudiante::getTheStudent() { return this->theStudent; }
Nodo_Estudiante* Nodo_Estudiante::getNext() { return this->next; }
string Nodo_Estudiante::toString() {
	return theStudent->toString();
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Lista_Estudiante::Lista_Estudiante() {
	this->first = nullptr; 
	this->quantEstudiantes = 0;
}
Lista_Estudiante::~Lista_Estudiante() {
	Nodo_Estudiante* aux; 
	while (first != nullptr) {
		aux = first; 
		first = first->getNext();
		delete aux;
	}
}
void Lista_Estudiante::insertarInicio(Estudiante* student) {
	first = new Nodo_Estudiante(student, first);
	quantEstudiantes++;
}
void Lista_Estudiante::eliminarFinal() {
	Nodo_Estudiante* aux = first; 
	if (first->getNext() == nullptr) {
		delete first; 
		first = nullptr;
	}
	else
	{
		while (aux->getNext()->getNext() != nullptr) {
			aux = aux->getNext();
	}
		delete aux->getNext();
		aux->setNext(nullptr); 
	}
	quantEstudiantes--;
}
void Lista_Estudiante::eliminarPrimero() {
	Nodo_Estudiante* aux = first; 
	if (first->getNext() == nullptr) {
		delete first; 
		first = nullptr; 
	}
	else
	{
		aux = aux->getNext();
		first = aux;
	}
	quantEstudiantes--; 
}
int Lista_Estudiante::getQuantStudents() {
	return this->quantEstudiantes; 
}
Nodo_Estudiante* Lista_Estudiante::getFirst() {
	return first;
}
string Lista_Estudiante::toString() {
	stringstream s;
	int so = 1;
	Nodo_Estudiante* aux = first; 
	while (aux != nullptr) {
		s << "---------------------" << so << "-----------------------" << endl; 
		s << aux->toString() << endl; 
		aux = aux->getNext();
		so++;
	}
	return s.str(); 
}
Estudiante* Lista_Estudiante::buscarEstudianteXID(string id){
	Nodo_Estudiante* aux = first; 
	while (aux != nullptr) {
		if (aux->getTheStudent()->get_id() == id) {
			return aux->getTheStudent();
		}
		aux = aux->getNext();
	}
	return nullptr; 
}