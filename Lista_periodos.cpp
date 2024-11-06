#include "Lista_periodos.h"
Nodo_Periodo::Nodo_Periodo(Periodo* periods, Nodo_Periodo* next){
	this->period = periods;
	this->next = next;
}
Nodo_Periodo::~Nodo_Periodo(){
	delete period;
}
void Nodo_Periodo::setPeriodo(Periodo* period) { this->period = period; }
void Nodo_Periodo::setNodoPeriodo(Nodo_Periodo* next) { this->next = next; }
Periodo* Nodo_Periodo::getPeriodo() { return this->period; }
Nodo_Periodo* Nodo_Periodo::getNext() { return this->next; }
string Nodo_Periodo::toString() {
	return this->period->toString(); 
}

//----------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------//

Lista_periodos::Lista_periodos() {
	this->first = nullptr; 
	this->quantPeriodos = 0; 
}
Lista_periodos::~Lista_periodos() {
	Nodo_Periodo* aux; 
	while (first != nullptr) {
		aux = first; 
		first = first->getNext();
		delete aux; 
	}
}
void Lista_periodos::ingresarPrimero(Periodo* period){
	first = new Nodo_Periodo(period, first);
	quantPeriodos++;
}
void Lista_periodos::eliminarFinal() {
	Nodo_Periodo* aux = first; 
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
		aux->setNodoPeriodo(nullptr);
	}
	quantPeriodos--;
}
void Lista_periodos::eliminarPrimero() {
	Nodo_Periodo* aux = first;
	if (first->getNext() == nullptr) {
		delete first;
		first = nullptr;
	}
	else
	{
		aux = aux->getNext();
		first = aux;
	}
	quantPeriodos--;
}
int Lista_periodos::getQuantPeriods() {
	return this->quantPeriodos;
}
Nodo_Periodo* Lista_periodos::getPrimero() { return this->first; }
Periodo* Lista_periodos::getPeriodoXNum(int num){
	Nodo_Periodo* aux = first; 
	while (aux != nullptr) {
		if (aux->getPeriodo()->getPeriodo() == num) {
			return aux->getPeriodo();
		}
		aux = aux->getNext();
	}
	return nullptr;
}
string Lista_periodos::toStringPeriodos() {
	stringstream s; 
	int so = 1; 
	Nodo_Periodo* aux = first; 
	while (aux != nullptr) {
		s << "----------------------------------" << so << "-----------------------------------------" << endl;
		s << aux->toString(); 
		aux = aux->getNext();
		so++;
	}
	return s.str(); 
}