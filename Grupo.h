#pragma once
#include "Horario.h"
#include "Lista_Estudiante.h"
#include "Profesor.h"

class Grupo {

private:
	int num_grupo;
	int cantidad_estudiantes;
	int cupoMaximo;
	Horario* horario;
	Profesor* profesor;
	Lista_Estudiante* listaStudents;

public:
	Grupo(int,int);
	virtual ~Grupo();
	void set_numGrupo(int);
	void set_cantidadEstudiantes(int);
	void set_CupoMaximos(int);
	void setListaEstudiantes(Lista_Estudiante*);
	void matricularEstudiante(Estudiante*);
	void unirProfesorAGrupo(Profesor*); 
	int get_numGrupo();
	int get_cuposMaximos();
	int get_cantidadEstudiantes();
	Profesor* getProfesor();
	Horario* getHorario(); 
	string toString();
	Lista_Estudiante* getGrupoLista(); 
	Estudiante* getEstudiante(string id); 
	bool estudianteYaMatriculado(Estudiante* estudiante);
	void desmatricularEstudiante(Estudiante* estudiante); 

};