#include "Lista_Grupos.h"
Nodo_Grupos::Nodo_Grupos(Grupo* group, Nodo_Grupos* next) {
	this->theGroup = group;
	this->next = next;
}
Nodo_Grupos::~Nodo_Grupos() {
	delete theGroup;
}
void Nodo_Grupos::setNext(Nodo_Grupos* next) { this->next = next; }
void Nodo_Grupos::setGroup(Grupo* grupo) { this->theGroup = grupo; }
Nodo_Grupos* Nodo_Grupos::getNext() { return this->next; }
Grupo* Nodo_Grupos::getGrupo() { return this->theGroup; }
string Nodo_Grupos::toString_NodeGroup() {
	return this->theGroup->toString();
}
//-----------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------//

Lista_Grupos::Lista_Grupos() {
	this->first = nullptr;
	this->quantGroups = 0;
}
Lista_Grupos::~Lista_Grupos() {
	Nodo_Grupos* aux; 
	while (first != nullptr) {
		aux = first;
		first = first->getNext(); 
		delete aux;
	}
}
void Lista_Grupos::insertarInicio(Grupo* group) {
	first = new Nodo_Grupos(group, first);
	quantGroups++;
}
void Lista_Grupos::eliminarFinal(){
	Nodo_Grupos* aux = first; 
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
	quantGroups--;
}
void Lista_Grupos::eliminarPrimero(){
	Nodo_Grupos* aux = first; 
	if (first->getNext() == nullptr) {
		delete first; 
		first = nullptr; 
	}
	else
	{
		aux = aux->getNext(); 
		first = aux; 
	}
	quantGroups--;
}
int Lista_Grupos::getQuantGroups() {
	return this->quantGroups;
}
Nodo_Grupos* Lista_Grupos::getPrimero() {
	return this->first; 
}
string Lista_Grupos::toString() {
	stringstream s;
	int so = 1;
	Nodo_Grupos* aux = first; 
	while (aux != nullptr) {
		s << "-----------------------" << so << "------------------------" << endl;
		s << aux->getGrupo()->toString() << endl; 
		aux = aux->getNext(); 
		so++;
	}
	return s.str(); 
}