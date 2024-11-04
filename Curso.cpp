#include "Curso.h"

Curso::Curso() {
    nombre = " ";
    id = " ";
    horas = 0;
    precio = 0;
    estado = false;
}
Curso::Curso(string nombre, string id, int horas, int precios, bool estado) {
    this->nombre = nombre;
    this->id = id;
    this->horas = horas;
    this->precio = precios;
    this->estado = estado;
    profes = new Lista_Profesores(); 
    grupos = new Lista_Grupos();
}
//Curso::Curso(Curso* curso) {
//    nombre = curso->get_nombre();
//    id = curso->get_id();
//    horas = curso->get_horas();
//    precio = curso->get_precio();
//    estado = curso->get_estado();
//}
Curso::~Curso() {}

void Curso::set_nombre(string nombre) { this->nombre = nombre; }
void Curso::set_id(string id) { this->id = id; }
void Curso::set_horas(int horas) { this->horas = horas; }
void Curso::set_precio(int precios) { this->precio = precios; }
void Curso::set_estado(bool estado) { this->estado = estado; }
void Curso::setProfeLista(Lista_Profesores* a) { this->profes = a; }
void Curso::setGrupoLista(Lista_Grupos* a) { this->grupos = a; }

string Curso::get_nombre() { return nombre; }
string Curso::get_id() { return id; }
int Curso::get_horas() { return horas; }
int Curso::get_precio() { return precio; }
bool Curso::get_estado() { return estado; }
Lista_Profesores* Curso::getProfeLista() { return this->profes; }
Lista_Grupos* Curso::getGrupoLista() { return this->grupos; }

string Curso::toString() {
    stringstream s;

    s << "Nombre del curso: " << nombre << endl;
    s << "ID del curso: " << id << endl;
    s << "Horas del curso: " << horas << endl;
    s << "Precios del curso: " << precio << endl;
    (estado == true) ? s << "Estado del curso: Disponible" << endl : s << "Estado del curso: No disponible" << endl;
    return s.str();
}