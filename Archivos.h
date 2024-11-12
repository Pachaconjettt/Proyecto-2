#pragma once
#include "Lista_periodos.h"
#include "ConversionDatos.h"
#include <fstream>
class Archivos
{
private:
	ifstream entrada; 
	ofstream salida; 
	ifstream entradaAux; 
	ofstream salidaAux; 
	ifstream entradaAux2; 
	ofstream salidaAux2;
	ifstream entrada2;
	ofstream salida2;
	ConversionDatos convDatos; 
public: 
	Archivos();
	void guardarEstudiantes(Lista_Estudiante*); 
	void guardarProfesores(Lista_Profesores*);
	void guardarEstudiantesGrupo(Lista_Estudiante*, int); 
	void guardarProfesoresGrupo(Lista_Profesores*, string);
	void guardarGrupos(Lista_Grupos*); 
	void guardarGruposNum(Lista_Grupos*, string);
	void guardarPeriodos(Lista_periodos*);
	void guardarCursos(Lista_Cursos*);
	void guardarCursosGrupos(Lista_Cursos*, int);
	Lista_Cursos* recuperarCursos(); 
	Lista_periodos* recuperarPeriodos(); 
	Lista_Estudiante * recuperarEstudiante();
	Lista_Profesores* recuperarProfesores(); 
	Lista_Estudiante* recuperarEstudiantesGrupos(int ); 
	Lista_Profesores* recuperarProfesoresGrupos(string ); 
	Lista_Grupos* recuperarGrupos(); 
	Lista_Grupos* recuperarGruposGrupos(string );
	Lista_Cursos* recuperarCursosGrupos(int); 
};

