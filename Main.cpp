#include <iostream>
#include "Interfaz.h"
#include "Horario.h"
#include "Grupo.h"
#include "Periodo.h"
// Efrain Retana & Christopher Blanco
using namespace std;

int main() {
	Interfaz* interfaz = new Interfaz(); 
	interfaz->menu_principal();	
	system("pause");
	return 0; 
}