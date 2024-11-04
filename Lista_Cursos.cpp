#include "Lista_Cursos.h"
Nodo_Cursos::Nodo_Cursos(Curso* cursos, Nodo_Cursos* next) {
	this->theCursos = cursos; 
	this->next = next;
}
Nodo_Cursos::~Nodo_Cursos() {
	delete theCursos;
}
void Nodo_Cursos::setTheCurso(Curso* course) { this->theCursos = course; }
void Nodo_Cursos::setNext(Nodo_Cursos* next) { this->next = next; }
Curso* Nodo_Cursos::getTheCurso() { return this->theCursos; }
Nodo_Cursos* Nodo_Cursos::getNext() { return this->next; }
string Nodo_Cursos::toStringNode() {
	return this->theCursos->toString();
}

//---------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------//


Lista_Cursos::Lista_Cursos() {
	this->first = nullptr; 
	this->quantCourses = 0;
}
Lista_Cursos::~Lista_Cursos() {
	Nodo_Cursos* aux;
	while (first != nullptr) {
		aux = first; 
		first = first->getNext();
		delete aux; 
	}
}
void Lista_Cursos::insertarInicio(Curso* course) {
	first = new Nodo_Cursos(course, nullptr);
	quantCourses++;
}
void Lista_Cursos::eliminarFinal() {
	Nodo_Cursos* aux = first; 
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
	quantCourses--;
}
void Lista_Cursos::eliminarPrimero() {
	Nodo_Cursos* aux = first; 
	if (first->getNext() == nullptr) {
		delete first; 
		first = nullptr;
	}
	else
	{
		aux = aux->getNext(); 
		first = aux;
	}
	quantCourses--;
}
int Lista_Cursos::getQuantNodes() {
	return quantCourses;
}
Nodo_Cursos* Lista_Cursos::getPrimero() {
	return this->first;
}
string Lista_Cursos::toStringCursos() {
	stringstream s; 
	Nodo_Cursos* aux = first;
	 int so = 1;
	while (aux != nullptr) {
		s << "---------------------------" << so << "----------------------------" << endl; 
		s << aux->getTheCurso()->toString() << endl;
		aux = aux->getNext();
		so++;
	}
	return s.str();
}