#pragma once
#include "Curso.h"

class Nodo_Cursos {
private:
	Curso* theCursos; 
	Nodo_Cursos* next; 
public:
	Nodo_Cursos(Curso*, Nodo_Cursos*);
	virtual ~Nodo_Cursos();
	void setTheCurso(Curso*);
	void setNext(Nodo_Cursos*);
	Curso* getTheCurso();
	Nodo_Cursos* getNext();
	string toStringNode(); 
};



class Lista_Cursos
{
private: 
	Nodo_Cursos* first; 
	int quantCourses; 
public:
	Lista_Cursos();
	virtual ~Lista_Cursos(); 
	void insertarInicio(Curso*);
	void eliminarFinal();
	void eliminarPrimero();
	int getQuantNodes();
	Nodo_Cursos* getPrimero();
	string toStringCursos();
};
