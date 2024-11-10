#include "Lista_Cursos.h"

Nodo_Cursos::Nodo_Cursos(Curso* cursos, Nodo_Cursos* next) {
    this->theCursos = cursos;
    this->next = next;
}

Nodo_Cursos::~Nodo_Cursos() {
    delete theCursos;
}

void Nodo_Cursos::setTheCurso(Curso* course) {
    this->theCursos = course;
}

void Nodo_Cursos::setNext(Nodo_Cursos* next) {
    this->next = next;
}

Curso* Nodo_Cursos::getTheCurso() {
    return this->theCursos;
}

Nodo_Cursos* Nodo_Cursos::getNext() {
    return this->next;
}

string Nodo_Cursos::toStringNode() {
    return this->theCursos->toString();
}

//---------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------//

Lista_Cursos::Lista_Cursos() {
    this->first = nullptr;
    this->quantCourses = 0;
}

Lista_Cursos::~Lista_Cursos() {
    Nodo_Cursos* aux;
    while (first != nullptr) {
        aux = first;
        first = first->getNext();
        delete aux;
    }
}

void Lista_Cursos::insertarInicio(Curso* course) {
    first = new Nodo_Cursos(course, first);
    quantCourses++;
}

void Lista_Cursos::eliminarFinal() {
    if (first == nullptr) return;

    Nodo_Cursos* aux = first;
    if (first->getNext() == nullptr) {
        delete first;
        first = nullptr;
    }
    else {
        while (aux->getNext()->getNext() != nullptr) {
            aux = aux->getNext();
        }
        delete aux->getNext();
        aux->setNext(nullptr);
    }
    quantCourses--;
}

void Lista_Cursos::eliminarPrimero() {
    if (first == nullptr) return;

    Nodo_Cursos* aux = first;
    if (first->getNext() == nullptr) {
        delete first;
        first = nullptr;
    }
    else {
        first = first->getNext();
        delete aux;
    }
    quantCourses--;
}

int Lista_Cursos::getQuantNodes() {
    return quantCourses;
}

Nodo_Cursos* Lista_Cursos::getPrimero() {
    return this->first;
}

string Lista_Cursos::toStringCursos() {
    stringstream s;
    Nodo_Cursos* aux = first;
    int so = 1;
    while (aux != nullptr) {
        s << "---------------------------" << so << "----------------------------" << endl;
        s << aux->toStringNode() << endl;
        aux = aux->getNext();
        so++;
    }
    return s.str();
}

Curso* Lista_Cursos::cursoXId(string id) {
    Nodo_Cursos* aux = first;
    while (aux != nullptr) {
        if (aux->getTheCurso()->get_id() == id) {
            return aux->getTheCurso();
        }
        aux = aux->getNext();
    }
    return nullptr;
}

int Lista_Cursos::PrecioTotal(string id) {
    int precio = 0;
    Nodo_Cursos* aux = first;
    while (aux != nullptr) {
        Nodo_Grupos* nodoGrupo = aux->getTheCurso()->getGrupoLista()->getPrimero();
        while (nodoGrupo != nullptr) {
            if (nodoGrupo->getGrupo()->getEstudiante(id) != nullptr) {
                precio += aux->getTheCurso()->get_precio();
                break; // Salir del bucle de grupos si el estudiante está matriculado en este curso
            }
            nodoGrupo = nodoGrupo->getNext();
        }
        aux = aux->getNext();
    }
    return precio;
}

float Lista_Cursos::PrecioConDescuento(string id) {
    float precioTotal = PrecioTotal(id);
    int numCursos = 0;
    Nodo_Cursos* aux = first;

    while (aux != nullptr) {
        Nodo_Grupos* nodoGrupo = aux->getTheCurso()->getGrupoLista()->getPrimero();
        while (nodoGrupo != nullptr) {
            if (nodoGrupo->getGrupo()->getEstudiante(id) != nullptr) {
                numCursos++;
                break;
            }
            nodoGrupo = nodoGrupo->getNext();
        }
        aux = aux->getNext();
    }

    float descuento = 0.0;
    if (numCursos >= 2) {
        descuento += precioTotal * 0.15;
    }
    if (numCursos >= 4) {
        descuento += precioTotal * 0.25;
    }

    return precioTotal - descuento;
}
string Lista_Cursos::ListaCursosEstudiante(string id) {
    stringstream s;
    Nodo_Cursos* aux = first;
    while (aux != nullptr) {
        Nodo_Grupos* nodoGrupo = aux->getTheCurso()->getGrupoLista()->getPrimero();
        while (nodoGrupo != nullptr) {
            if (nodoGrupo->getGrupo()->getEstudiante(id) != nullptr) {
                s << aux->toStringNode() << endl;
                s << aux->getTheCurso()->getGrupoLista()->toString() << endl; 
                s << endl; 
            }
            nodoGrupo = nodoGrupo->getNext();
        }
        aux = aux->getNext();
    }
    return s.str();
}
string Lista_Cursos::ListaCursosProfesor(string _id) {
    stringstream s;
    Nodo_Cursos* aux = first;
    while (aux != nullptr) {
        if (aux->getTheCurso()->getGrupoLista()->getGrupoXProfesorID(_id) != nullptr) {
            s << aux->toStringNode() << endl;
            s << aux->getTheCurso()->getGrupoLista()->getGrupoXProfesorID(_id)->toString() << endl;
        }
        aux = aux->getNext();
    }
    return s.str();
}