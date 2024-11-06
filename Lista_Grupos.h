#pragma once
#include "Grupo.h"

class Nodo_Grupos {
private: 
	Nodo_Grupos* next; 
	Grupo* theGroup;
public:
	Nodo_Grupos(Grupo* ,Nodo_Grupos*);
	virtual ~Nodo_Grupos();
	void setNext(Nodo_Grupos*); 
	void setGroup(Grupo*); 
	Nodo_Grupos* getNext(); 
	Grupo* getGrupo(); 
	string toString_NodeGroup(); 
};

//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//

class Lista_Grupos
{
private:
	Nodo_Grupos* first;
	int quantGroups; 
public: 
	Lista_Grupos(); 
	virtual ~Lista_Grupos();
	void insertarInicio(Grupo*);
	void eliminarFinal(); 
	void eliminarPrimero(); 
	int getQuantGroups(); 
	Nodo_Grupos* getPrimero(); 
	string toString(); 
	Grupo* getGrupoXNumero(int); 
};

