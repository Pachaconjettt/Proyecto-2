#include "Lista_Profesores.h"
Nodo_Profesor::Nodo_Profesor(Profesor* profesor,Nodo_Profesor* next){
	this->theProfesor = profesor;
	this->next = next;
}
Nodo_Profesor::~Nodo_Profesor() {
	delete theProfesor;
}
void Nodo_Profesor::setProfesor(Profesor* profesor) { this->theProfesor = profesor; }
void Nodo_Profesor::setNext(Nodo_Profesor* next) { this->next = next; }
Profesor * Nodo_Profesor::getProfesor() { return this->theProfesor; }
Nodo_Profesor* Nodo_Profesor::getNext() { return this->next; }
string Nodo_Profesor::toString() {
	return theProfesor->toString();
}
//--------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------//

Lista_Profesores::Lista_Profesores() {
	this->first = nullptr;
	this->quantProfesor = 0;
}
Lista_Profesores::~Lista_Profesores() {
	Nodo_Profesor* aux; 
	while (first != nullptr) {
		aux = first; 
		first = first->getNext();
		delete aux;
	}
}
void Lista_Profesores::InsertarInicio(Profesor* profesor) {
	first = new Nodo_Profesor(profesor, first);
	quantProfesor++;
}
void Lista_Profesores::eliminarFinal() {
	Nodo_Profesor* aux = first;
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
	quantProfesor--;
}
void Lista_Profesores::eliminarPrimero() {
	Nodo_Profesor* aux = first; 
	if (first->getNext() == nullptr) {
		delete first; 
		first = nullptr; 
	}
	else
	{
		aux = aux->getNext();
		first = aux; 
	}
	quantProfesor--;
}
int Lista_Profesores::getQuantProfesor() {
	return this->quantProfesor;
}
Nodo_Profesor* Lista_Profesores::getPrimero() {
	return this->first;
}
string Lista_Profesores::toString() {
	stringstream s; 
	int so = 1; 
	Nodo_Profesor* aux = first; 
	while (aux != nullptr) {
		s << "----------------------" << so << "-----------------------" << endl; 
		s << aux->toString(); 
		aux = aux->getNext();
		so++;
	}
	return s.str();
}
Profesor* Lista_Profesores::getProfesorXId(string id) {
	Nodo_Profesor* aux = first;
	while (aux != nullptr) {
		if (aux->getProfesor()->get_id() == id) {
			return aux->getProfesor();
		}
		aux = aux->getNext();
	}
	return nullptr; 
}