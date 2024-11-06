#pragma once
#include "Periodo.h"

class Nodo_Periodo {
private: 
	Periodo* period; 
	Nodo_Periodo* next; 
public: 
	Nodo_Periodo(Periodo*, Nodo_Periodo*); 
	virtual ~Nodo_Periodo(); 
	void setPeriodo(Periodo*);
	void setNodoPeriodo(Nodo_Periodo*); 
	Periodo* getPeriodo(); 
	Nodo_Periodo* getNext(); 
	string toString(); 
};
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
class Lista_periodos
{
private:
	Nodo_Periodo* first; 
	int quantPeriodos;
public: 
	Lista_periodos(); 
	virtual ~Lista_periodos(); 
	void ingresarPrimero(Periodo*); 
	void eliminarFinal(); 
	void eliminarPrimero(); 
	int getQuantPeriods();
	Nodo_Periodo* getPrimero(); 
	Periodo* getPeriodoXNum(int);
	string toStringPeriodos();
};

