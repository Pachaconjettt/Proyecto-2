	#include "Grupo.h"

Grupo::Grupo(int numGroup, /*int cantidadEst,*/ int cupoMaximo/*, Horario* calendar, Lista_Estudiante* list*/) {
	/*this->curso = new Curso(curso);*/
	this->num_grupo = numGroup; 
	this->cantidad_estudiantes = 0;
	this->cupoMaximo = cupoMaximo; 
	this->horario = new Horario();
	this->listaStudents = new Lista_Estudiante(); 
	this->profesor = new Profesor();
	//inicializar_lista();
}
Grupo::~Grupo() {
	/*delete curso;*/
	delete horario; 
	//delete profesor;
	//for (int i = 0; i < cantidad_estudiantes; i++) {
	//	delete estudiantes_matriculados[i];
	//}
	//delete[] estudiantes_matriculados;
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
//bool Grupo::buscar_estudiante(string id) {
//	for (int i = 0; i < cantidad_estudiantes; i++) {
//		if (estudiantes_matriculados[i]->get_id() == id) {
//			return true;
//		}
//	}
//	return false;
//}
//bool Grupo::eliminar_estudiante(string id) {
//	for (int i = 0; i < cantidad_estudiantes; i++) {
//		if (estudiantes_matriculados[i] != nullptr && estudiantes_matriculados[i]->get_id() == id) {  
//			estudiantes_matriculados[i] = nullptr;  
//
//			for (int j = i; j < cantidad_estudiantes - 1; j++) {
//				estudiantes_matriculados[j] = estudiantes_matriculados[j + 1]; 
//			}
//			estudiantes_matriculados[cantidad_estudiantes - 1] = nullptr;
//			cantidad_estudiantes--; 
//			return true;  
//		}
//	}
//	return false;
//}
//bool Grupo::agregar_estudiante(Estudiante* estudiante) {
//	if (estudiante != nullptr && cantidad_estudiantes < CUPOS && buscar_estudiante(estudiante->get_id()) == false) {
//		estudiantes_matriculados[cantidad_estudiantes] = estudiante;
//		cantidad_estudiantes++;
//		return true;
//	}
//	return false;
//}
//bool Grupo::eliminar_profesor() {
//	if (profesor != nullptr) {
//		profesor = nullptr;
//		return true;
//	}
//	return false;
//}
//void Grupo::asingar_profesor(Profesor* profesor) { this->profesor = profesor; }
//Curso* Grupo::get_curso() { return curso; }
//void Grupo::set_curso(Curso* curso) { this->curso = curso; }
//Profesor* Grupo::get_profesor() { return profesor; }
//Estudiante* Grupo::get_estudiante(string id) {
//	for (int i = 0; i < cantidad_estudiantes; i++) {
//		if (estudiantes_matriculados[i]->get_id() == id) {
//			return estudiantes_matriculados[i];
//		}
//	}
//	return nullptr;
//}
//
//string Grupo::imprimir_listaEstudiantes() {
//	stringstream s;
//	
//	for (int i = 0; i < cantidad_estudiantes; i++) {
//		s << estudiantes_matriculados[i]->toString() << endl;
//	}
//	return s.str();
//}
