#pragma once
#include <iostream>
//#include "Profesor.h"
//#include "Estudiante.h"
using namespace std;

class Interfaz {
public:
	Interfaz();

	void menu_principal();

	void submenu_administarcion();
	void ingresar_profesor();
	void ingresar_estudiante();
	void ingresar_Periodo();
	void ingresar_curso();
	void ingresar_grupo();
	void asignar_ProfesorAGrupo();

	void submenu_matricula();
	void matricular_estudiante();
	void desmatricular_estudiante();

	void submenu_busquedaInformes();
	void informe_ProfesoresRegistrados();
	void informe_EstudiantesRegistrados();
	void informe_CursosMatriculados_PorEstudiante();
	void informe_ProfesorEspecifico();
	void informe_PeriodosHabilitados_ParaAnio();
	void informe_GrupoEspecifico();

	void guardar_datos();
};