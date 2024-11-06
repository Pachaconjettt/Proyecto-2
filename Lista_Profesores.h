#pragma once
#include "Profesor.h"

class Nodo_Profesor {
private: 
	Nodo_Profesor* next; 
	Profesor* theProfesor;
public: 
	Nodo_Profesor(Profesor*, Nodo_Profesor*);
	virtual ~Nodo_Profesor();
	void setProfesor(Profesor*); 
	void setNext(Nodo_Profesor*); 
	Profesor * getProfesor(); 
	Nodo_Profesor * getNext();
	string toString();
};

//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

class Lista_Profesores
{
private: 
	Nodo_Profesor* first; 
	int quantProfesor;
public: 
	Lista_Profesores(); 
	virtual ~Lista_Profesores();
	void InsertarInicio(Profesor*);
	void eliminarFinal(); 
	void eliminarPrimero(); 
	int getQuantProfesor(); 
	Nodo_Profesor* getPrimero(); 
	Profesor* getProfesorXId(string);
	string toString(); 
};

