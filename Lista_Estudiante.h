#pragma once
#include "Estudiante.h"

class Nodo_Estudiante {
private: 
	Estudiante* theStudent; 
	Nodo_Estudiante* next; 
public:
	Nodo_Estudiante(Estudiante*, Nodo_Estudiante*); 
	virtual ~Nodo_Estudiante();
	void setEstudiante(Estudiante*); 
	void setNext(Nodo_Estudiante*);
	Estudiante* getTheStudent();
	Nodo_Estudiante* getNext();
	string toString();
};

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

class Lista_Estudiante
{
private:
	Nodo_Estudiante* first; 
	int quantEstudiantes; 
public: 
	Lista_Estudiante();
	virtual ~Lista_Estudiante();
	void insertarInicio(Estudiante*); 
	void eliminarFinal(); 
	void eliminarPrimero();
	Estudiante* buscarEstudianteXID(string);
	void quitarEstudiantePorID(string id);
	int getQuantStudents();
	string toString(); 
	Nodo_Estudiante* getFirst();
};

