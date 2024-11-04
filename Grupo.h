#pragma once
#include "Horario.h"
#include "Lista_Estudiante.h"
#include "Profesor.h"
//#define CUPOS 30

//class Profesor;
//class Estudiante;

class Grupo {
private:
	//Curso* curso;
	int num_grupo;
	int cantidad_estudiantes;
	int cupoMaximo;
	Horario* horario;
	Profesor* profesor;
	Lista_Estudiante* listaStudents;
	//Profesor* profesor//
	/* Voy a quitar esto por que "Tener
		presente que todo profesor puede estar a cargo de n grupos" 
		osea es lo mismo que lo de cursos, profesor tiene n cantidad de grupos no grupos tiene n cantidad de profesores */
	//Pasar estudiantes_matriculados de vector a lista enlazada.
	/*Estudiante** estudiantes_matriculados; 
	
	void inicializar_lista() {
		estudiantes_matriculados = new Estudiante * [CUPOS];

		for (int i = 0; i < CUPOS; i++) {
			estudiantes_matriculados[i] = nullptr;
		}
	}*/
public:
	Grupo(int/*,int*/,int/*Horario*,Lista_Estudiante**/);
	virtual ~Grupo();
	void set_numGrupo(int);
	void set_cantidadEstudiantes(int);
	void set_CupoMaximos(int);
	void matricularEstudiante(Estudiante*);
	int get_numGrupo();
	int get_cuposMaximos();
	int get_cantidadEstudiantes();
	Horario* getHorario(); 
	string toString();
	Lista_Estudiante* getGrupoLista(); 
	Estudiante* getEstudiante(string id); 
	//void asingar_profesor(Profesor*);
	//bool eliminar_profesor();
	//bool agregar_estudiante(Estudiante*);
	//bool eliminar_estudiante(string);
	
	//Si quiere cuando vea esto los elimina y me avisa....
	//void set_curso(Curso*);
	/*Curso* get_curso();*/

	/*Profesor* get_profesor();
	bool buscar_estudiante(string);
	Estudiante* get_estudiante(string);

	string imprimir_listaEstudiantes();*/

};