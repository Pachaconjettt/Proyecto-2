	#include "Grupo.h"

Grupo::Grupo(int numGroup,int cupoMaximo) {
	this->num_grupo = numGroup; 
	this->cantidad_estudiantes = 0;
	this->cupoMaximo = cupoMaximo; 
	this->horario = new Horario();
	this->listaStudents = new Lista_Estudiante(); 
	this->profesor = new Profesor();
}

Grupo::~Grupo() {
	delete horario;
}

void Grupo::set_numGrupo(int numGrupo) { this->num_grupo = numGrupo; }
void Grupo::set_cantidadEstudiantes(int numEstudiantes) { this->cantidad_estudiantes = numEstudiantes; }
void Grupo::set_CupoMaximos(int cupos) { this->cupoMaximo = cupos; }
void Grupo::setListaEstudiantes(Lista_Estudiante* lista) { this->listaStudents = lista;  }
void Grupo::unirProfesorAGrupo(Profesor* profesor1) { 
		this->profesor = profesor1;
}
void Grupo::matricularEstudiante(Estudiante* estudiante) {
	listaStudents->insertarInicio(estudiante);
	cantidad_estudiantes++;
}

bool Grupo::estudianteYaMatriculado(Estudiante* estudiante) {
	Nodo_Estudiante* actual = listaStudents->getFirst();
	while (actual != nullptr) {
		if (actual->getTheStudent()->get_id() == estudiante->get_id()) {
			return true;
		}
		actual = actual->getNext();
	}
	return false;
}

int Grupo::get_numGrupo() { return num_grupo; }
int Grupo::get_cuposMaximos() { return cupoMaximo; }
int Grupo::get_cantidadEstudiantes() { return cantidad_estudiantes; }
Lista_Estudiante* Grupo::getGrupoLista() { return this->listaStudents; }
Estudiante * Grupo::getEstudiante(string id) {
	Lista_Estudiante * aux = listaStudents;
	while (aux->getFirst()) {
		if (aux->getFirst()->getTheStudent()->get_id() == id)
			return aux->getFirst()->getTheStudent();
		else
			aux->eliminarPrimero();
	}
	return nullptr;
}

string Grupo::toString() {
	stringstream s;
	s << "Numero del grupo : " << num_grupo << endl;
	s << "Cupo maximo : " << cupoMaximo << endl;
	s << "Cantidad de matriculados en el grupo " << cantidad_estudiantes << endl;
	s << "Horario del grupo : " << endl;
	s << horario->toString() << endl;
	s << "Profesor : " << profesor->get_nombre() << endl; 
	return s.str();
}

Profesor* Grupo::getProfesor() { return this->profesor; }
Horario* Grupo::getHorario() { return this->horario;  }
void Grupo::desmatricularEstudiante(Estudiante* estudiante) {
	listaStudents->quitarEstudiantePorID(estudiante->get_id());
	cantidad_estudiantes--;
}
