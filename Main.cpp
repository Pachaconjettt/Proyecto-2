#include <iostream>
#include "Interfaz.h"
#include "Horario.h"
#include "Grupo.h"
#include "Periodo.h"
// Efrain Retana & Christopher Blanco
using namespace std;

int main() {
	//Interfaz* UI = new Interfaz();
	//UI->menu_principal();
	Horario* horario = new Horario();
	horario->ingresar_evento(1, 1, "Calculo 1");

	Curso* curso_1 = new Curso("calculo", "123", 2, 1000, true);
	Profesor* profe = new Profesor("Juan de dios", "987", 076543, 40, "chrisblanco.2004@gmail.com", "Doctorado");
	Estudiante* estudiante_1 = new Estudiante("josu", "567", 076543, 20, "josuhernandez.2004@gmail.com", "Ingenieria");
	Grupo* grupo_1 = new Grupo(curso_1, 2001);
	grupo_1->asingar_profesor(profe);
	grupo_1->agregar_estudiante(estudiante_1);
	/*
	Periodo* periodo_1 = new Periodo("Enero-Marzo");
	Periodo* periodo_2 = new Periodo("Abril-Junio");
	Periodo* periodo_3 = new Periodo("Julio-Setiembre");
	Periodo* periodo_4 = new Periodo("Octubre-Diciembre");
	periodo_1->ingresar_curso(grupo_1);
	periodo_2->ingresar_curso(grupo_1);
	periodo_3->ingresar_curso(grupo_1);
	periodo_4->ingresar_curso(grupo_1);
	cout << periodo_1->toString() << endl;
	cout << periodo_2->toString() << endl;
	cout << periodo_3->toString() << endl;
	cout << periodo_4->toString() << endl;
	*/
	//cout << grupo_1->toString() << endl;
	cout << grupo_1->imprimir_listaEstudiantes() << endl;
	return 0;
}