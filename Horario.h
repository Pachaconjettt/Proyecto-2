#pragma once
#include <iostream> 
#include <sstream> 
#include <string> 
#include <iomanip>
#define TAM 6
using namespace std;

class Horario {
private:
	int horasOcupadas;
	string*** horario;

	void inicializar_horario() {
		int hora_inicio = 8;
		int hora_final = 10;
		string dias[] = { "Lun", "Mar", "Mie", "Jue", "Vie" };
		horario = new string * *[TAM];

		for (int i = 0; i < TAM; i++) {
			horario[i] = new string * [TAM];

			for (int j = 0; j < TAM; j++) {
				horario[i][j] = (i == 0 && j == 0) ? new string(" ") : new string("Libre");
			}
		}
		for (int i = 1; i < TAM; i++) {
			(hora_inicio > 12) ? hora_inicio - 12 : hora_inicio;
			(hora_final > 12) ? hora_final - 12 : hora_final;

			*(horario[i][0]) = to_string(hora_inicio) + "-" + to_string(hora_final);

			hora_inicio += 2;
			hora_final += 2;
		}
		for (int i = 1; i < TAM; i++) {
			*(horario[0][i]) = dias[i - 1];
		}
	}
public:
	Horario();
	virtual ~Horario();

	bool ingresar_evento(int, int, string);
	bool eliminar_evento(int, int);

	string  toString();
};

