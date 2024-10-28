#include "Horario.h" 

Horario::Horario() {
	horasOcupadas = 0;
	inicializar_horario();
}
Horario::~Horario() {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			delete horario[i][j];
		}
		delete[] horario[i];
	}
	delete[] horario;
}

bool Horario::ingresar_evento(int hora, int dia, string evento) { 
	if (hora > 0 && dia > 0 && evento != " " && evento != "Libre") {
		*horario[hora][dia] = evento; 
		return true;
	}
	return false;
}
bool Horario::eliminar_evento(int hora, int dia) { 
	if (hora > 0 && dia > 0) { 
		*horario[hora][dia] = "Libre";
		return true;
	} 
	return false;
}

string Horario::toString() {
	stringstream s;

	int espacio_columnas = 10;

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			s << left << setw(espacio_columnas) << *horario[i][j] << " ";
		}
		s << endl;
	}
	return s.str();
}