#include "Archivos.h"
#include <iostream>

Archivos::Archivos() {}

//1) guardar Estudiante
void Archivos::guardarEstudiantes(Lista_Estudiante* _lis) {
    salida.open("Archivos/Estudiantes.txt");
    if (salida.good()) {
        Nodo_Estudiante* aux = _lis->getFirst();
        while (aux) {
            salida << aux->getTheStudent()->get_nombre() << "\t";
            salida << aux->getTheStudent()->get_id() << "\t";
            salida << aux->getTheStudent()->get_numTelefono() << "\t";
            salida << aux->getTheStudent()->get_edad() << "\t";
            salida << aux->getTheStudent()->get_email() << "\t";
            salida << aux->getTheStudent()->get_especialidad() << "\n";
            aux = aux->getNext();
        }
    }
    salida.close();
}

//2)  guardo EstudiantesGrupos
void Archivos::guardarEstudiantesGrupo(Lista_Estudiante* lis_, int numeroGrupo) {
    if (salida.good()) {
        Nodo_Estudiante* aux = lis_->getFirst();
        while (aux) {
            salidaAux << numeroGrupo << "\t";
            salidaAux << aux->getTheStudent()->get_nombre() << "\t";
            salidaAux << aux->getTheStudent()->get_id() << "\t";
            salidaAux << aux->getTheStudent()->get_numTelefono() << "\t";
            salidaAux << aux->getTheStudent()->get_edad() << "\t";
            salidaAux << aux->getTheStudent()->get_email() << "\t";
            salidaAux << aux->getTheStudent()->get_especialidad() << "\n";
            aux = aux->getNext();
        }
    }
}

//3) guardo Profesores
void Archivos::guardarProfesores(Lista_Profesores* _lis) {
    salida.open("Archivos/Profesores.txt");
    if (salida.good()) {
        Nodo_Profesor* aux = _lis->getPrimero();
        while (aux) {
            salida << aux->getProfesor()->get_nombre() << "\t";
            salida << aux->getProfesor()->get_id() << "\t";
            salida << aux->getProfesor()->get_numTelefono() << "\t";
            salida << aux->getProfesor()->get_edad() << "\t";
            salida << aux->getProfesor()->get_email() << "\t";
            salida << aux->getProfesor()->get_gradoAcademico() << "\n";
            aux = aux->getNext();
        }
    }
    salida.close();
}

//4) Guardo Profesores grupos
void Archivos::guardarProfesoresGrupo(Lista_Profesores* lis_, string idCurso) {
    if (salida.good()) {
        Nodo_Profesor* aux = lis_->getPrimero();
        while (aux) {
            salidaAux << idCurso << "\t";
            salidaAux << aux->getProfesor()->get_nombre() << "\t";
            salidaAux << aux->getProfesor()->get_id() << "\t";
            salidaAux << aux->getProfesor()->get_numTelefono() << "\t";
            salidaAux << aux->getProfesor()->get_edad() << "\t";
            salidaAux << aux->getProfesor()->get_email() << "\t";
            salidaAux << aux->getProfesor()->get_gradoAcademico() << "\n";
            aux = aux->getNext();
        }
    }
}

//5) Guardo Grupo
void Archivos::guardarGrupos(Lista_Grupos* _lis) {
    salida.open("Archivos/grupos.txt");
    salidaAux.open("Archivos/EstudiantesGrupos.txt");
    if (salida.good() && salidaAux.good()) {
        Nodo_Grupos* aux = _lis->getPrimero();
        while (aux) {
            salida << aux->getGrupo()->get_numGrupo() << "\t";
            salida << aux->getGrupo()->get_cuposMaximos() << "\t";
            salida << aux->getGrupo()->get_cantidadEstudiantes() << "\n"; 
            guardarEstudiantesGrupo(aux->getGrupo()->getGrupoLista(), aux->getGrupo()->get_numGrupo());
            aux = aux->getNext();
        }
    }
    salida.close();
    salidaAux.close();
}

//6) Guardo Grupos de grupos jajajaajaj
void Archivos::guardarGruposNum(Lista_Grupos* lis_, string id) {
    if (salida.good()) {
        Nodo_Grupos* aux = lis_->getPrimero();
        while (aux) {
            salidaAux << id << "\t";
            salidaAux << aux->getGrupo()->get_numGrupo() << "\t";
            salidaAux << aux->getGrupo()->get_cuposMaximos() << "\n";
            guardarEstudiantesGrupo(aux->getGrupo()->getGrupoLista(), aux->getGrupo()->get_numGrupo());
            aux = aux->getNext();
        }
    }
}

//7) Guardo Cursos
void Archivos::guardarCursos(Lista_Cursos* _lis) {
    salida.open("Archivos/Cursos.txt");
    salidaAux.open("Archivos/gruposDeGrupos.txt");
    salidaAux2.open("Archivos/ProfesoresLista.txt");
    if (salidaAux.good() && salidaAux2.good()) {
        Nodo_Cursos* aux = _lis->getPrimero();
        Curso* curso = aux->getTheCurso();
        while (aux) {
            salida << curso->get_nombre() << "\t";
            salida << curso->get_id() << "\t";
            salida << curso->get_horas() << "\t";
            salida << curso->get_precio() << "\t";
            salida << curso->get_estado() << "\n";  
            guardarGruposNum(aux->getTheCurso()->getGrupoLista(), aux->getTheCurso()->get_id());
            guardarProfesoresGrupo(aux->getTheCurso()->getProfeLista(), aux->getTheCurso()->get_id());
            aux = aux->getNext();
        }
    }
    else {
        std::cerr << "Error al abrir los archivos para guardar los cursos." << std::endl;
    }
    salida.close();
    salidaAux.close();
    salidaAux2.close();
}
//8) Guardar Cursos de Cursos
void Archivos::guardarCursosGrupos(Lista_Cursos* _lis, int num){
    if (salida.good()) {
        Nodo_Cursos* aux = _lis->getPrimero(); 
        while (aux) {
            salidaAux << num << '\t'; 
            salidaAux << aux->getTheCurso()->get_nombre() << "\t";
            salidaAux << aux->getTheCurso()->get_id() << "\t";
            salidaAux << aux->getTheCurso()->get_horas() << "\t";
            salidaAux << aux->getTheCurso()->get_precio() << "\t";
            salidaAux << aux->getTheCurso()->get_estado() << "\n";
            guardarGruposNum(aux->getTheCurso()->getGrupoLista(), aux->getTheCurso()->get_id());
            guardarProfesoresGrupo(aux->getTheCurso()->getProfeLista(), aux->getTheCurso()->get_id());
            aux = aux->getNext(); 
        }
    }
}
//9) Guardo Periodos
void Archivos::guardarPeriodos(Lista_periodos* _lis) {
    salida.open("Archivos/Periodos.txt");
    salidaAux.open("Archivos/CursoGrupos.txt");
    if (salida.good()) {
        Nodo_Periodo* aux = _lis->getPrimero();
        while (aux) {
            salida << aux->toString() << "\n";
            guardarCursosGrupos(aux->getPeriodo()->getCursos(), aux->getPeriodo()->getPeriodo());
            aux = aux->getNext();   
        }
    }
    salida.close();
    salidaAux.close();
}

//1.1) Recupero Estudiante
Lista_Estudiante* Archivos::recuperarEstudiante() {
    Lista_Estudiante* listaAux = new Lista_Estudiante();
    entrada.open("Archivos/Estudiantes.txt");
    string cedula, nombre, email, especialidad;
    string edad, telefono;
    Estudiante* eldep = nullptr;
    while (entrada.good()) {
        getline(entrada, nombre, '\t');
        getline(entrada, cedula, '\t');
        getline(entrada, telefono, '\t');
        getline(entrada, edad, '\t');
        getline(entrada, email, '\t');
        getline(entrada, especialidad, '\n');
        if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !edad.empty() && !email.empty() && !especialidad.empty()) {
            eldep = new Estudiante(nombre, cedula, convDatos.conversionInt(telefono), convDatos.conversionInt(edad), email, especialidad);
        }
        if (entrada.good() && eldep)
            listaAux->insertarInicio(eldep);
    }
    entrada.close();
    return listaAux;
}
//1.2) Recupero grupo Estudiante
Lista_Estudiante* Archivos::recuperarEstudiantesGrupos(int numeroGrupo_) {
    Lista_Estudiante* listaAux = new Lista_Estudiante();
    entradaAux.open("Archivos/EstudiantesGrupos.txt");
    string cedula, nombre, telefono, edad, email, especialidad;
    string grupoNum;
    Estudiante* eldep = nullptr;
    while (entradaAux.good()) {
        getline(entradaAux, grupoNum,'\t');
        getline(entradaAux, nombre, '\t');
        getline(entradaAux, cedula, '\t');
        getline(entradaAux, telefono, '\t');
        getline(entradaAux, edad, '\t');
        getline(entradaAux, email, '\t');
        getline(entradaAux, especialidad, '\n');
        if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !edad.empty() && !email.empty() && !especialidad.empty()) {
            eldep = new Estudiante(nombre, nombre, convDatos.conversionInt(telefono), convDatos.conversionInt(edad), email, especialidad);
        }
        if (entrada.good() && eldep && (numeroGrupo_ == convDatos.conversionInt(grupoNum)))
            listaAux->insertarInicio(eldep);
    }
    entradaAux.close();
    return listaAux;    
}
//1.3) Recupero Profesores
Lista_Profesores* Archivos::recuperarProfesores() {
    Lista_Profesores* listaAux = new Lista_Profesores();
    entrada.open("Archivos/Profesores.txt");
    string cedula, nombre, email, grado_Academico;
    string edad, telefono;
    Profesor* eldep = nullptr;
    while (entrada.good()) {
        getline(entrada, nombre, '\t');
        getline(entrada, cedula, '\t');
        getline(entrada, telefono, '\t');
        getline(entrada, edad, '\t');
        getline(entrada, email, '\t');
        getline(entrada, grado_Academico, '\n');
        if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !edad.empty() && !email.empty() && !grado_Academico.empty()) {
            eldep = new Profesor(nombre, cedula, convDatos.conversionInt(telefono), convDatos.conversionInt(edad), email, grado_Academico);
        }
        if (entrada.good() && eldep)
            listaAux->InsertarInicio(eldep);
    }
    entrada.close();
    return listaAux;
}
//1.4) Recupero Profesores Grupos

Lista_Profesores* Archivos::recuperarProfesoresGrupos(string num) {

    Lista_Profesores* listaAux = new Lista_Profesores();
    entradaAux.open("Archivos/ProfesoresLista.txt");
    string cedula, nombre, telefono, edad, email, gradoAcademico;
    string id;
    Profesor* eldep = nullptr;
    while (entradaAux.good()) {
        getline(entradaAux, id, '\t');
        getline(entradaAux, nombre, '\t');
        getline(entradaAux, cedula, '\t');
        getline(entradaAux, telefono, '\t');
        getline(entradaAux, edad, '\t');
        getline(entradaAux, email, '\t');
        getline(entradaAux, gradoAcademico, '\n');
        if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !edad.empty() && !email.empty() && !gradoAcademico.empty()) {
            eldep = new Profesor(nombre, nombre, convDatos.conversionInt(telefono), convDatos.conversionInt(edad), email, gradoAcademico);
        }
        if (entrada.good() && eldep && (num == id))
            listaAux->InsertarInicio(eldep);
    }
    entradaAux.close();
    return listaAux;
}

//1.5) Recupero Grupos
Lista_Grupos* Archivos::recuperarGrupos() {
    Lista_Grupos* listaAux = new Lista_Grupos();
    string numeroCurso, cupoMaximo, cuposUsados;
    Lista_Estudiante* estudiantes;
    Grupo* grupoAux = nullptr;
    entrada.open("Archivos/grupos.txt");
    while (entrada.good()) {
        getline(entrada, numeroCurso, '\t');
        getline(entrada, cupoMaximo, '\t');
        getline(entrada, cuposUsados, '\n'); 
        estudiantes = recuperarEstudiantesGrupos(convDatos.conversionInt(numeroCurso));
        if (!numeroCurso.empty() && !cupoMaximo.empty() && !cuposUsados.empty()) {
            grupoAux = new Grupo(convDatos.conversionInt(numeroCurso), convDatos.conversionInt(cupoMaximo));
            grupoAux->set_numGrupo(convDatos.conversionInt(numeroCurso));
            grupoAux->set_cantidadEstudiantes(convDatos.conversionInt(cuposUsados));
            grupoAux->setListaEstudiantes(estudiantes);
        }
        if (entrada.good() && grupoAux) {
            listaAux->insertarInicio(grupoAux);
        }
    }
    entrada.close();
    return listaAux;
}
//1.6) Recuperar Grupos de grupo
Lista_Grupos* Archivos::recuperarGruposGrupos(string id) {
    Lista_Grupos* listagroups = new Lista_Grupos();
    string numeroCurso, cupoMaximo, cuposUsados;
    string grupoNum;
    Lista_Estudiante* estudiantes; 
    Grupo* grupoAux = nullptr;
    entradaAux.open("Archivos/gruposDeGrupos.txt");

        while (entradaAux.good()) {
            getline(entradaAux, id, '\t');
            getline(entradaAux, numeroCurso, '\t');
            getline(entradaAux, cupoMaximo, '\t');
            getline(entradaAux, cuposUsados, '\n');
            estudiantes = recuperarEstudiantesGrupos(convDatos.conversionInt(numeroCurso));
            if (!numeroCurso.empty() && !cupoMaximo.empty()) {
                grupoAux = new Grupo(convDatos.conversionInt(numeroCurso), convDatos.conversionInt(cupoMaximo));
                grupoAux->set_numGrupo(convDatos.conversionInt(numeroCurso));
                grupoAux->set_cantidadEstudiantes(convDatos.conversionInt(cuposUsados));
                grupoAux->setListaEstudiantes(estudiantes);
            }
            if (entrada.good() && grupoAux && (id == grupoNum))
                listagroups->insertarInicio(grupoAux);
            }
        entradaAux.close();
        return listagroups;
}

//1.7) Recuperar Cursos
Lista_Cursos* Archivos::recuperarCursos() {
    Lista_Cursos* listaAux =  new Lista_Cursos();
    string nombre, id, horas, precio, estado;
    Lista_Grupos* grupos; 
    Lista_Profesores* profes; 
    Curso* cursoAux = nullptr; 
    entrada.open("Archivos/Cursos.txt");
        while (entrada.good()) {
            getline(entrada, nombre, '\t');
            getline(entrada, id, '\t');
            getline(entrada, horas, '\t');
            getline(entrada, precio, '\t');
            getline(entrada, estado, '\n');
            grupos = recuperarGruposGrupos(id); 
            profes = recuperarProfesoresGrupos(id); 
            if (!nombre.empty() && !id.empty() && !horas.empty() && !precio.empty() && !estado.empty()) {
                cursoAux = new Curso(nombre, id, convDatos.conversionInt(horas), convDatos.conversionDouble(precio), convDatos.conversionBool(estado));
                cursoAux->set_id(id);
                cursoAux->setGrupoLista(grupos);
                cursoAux->setProfeLista(profes); 
            }
            if (entrada.good() && cursoAux) {
                listaAux->insertarInicio(cursoAux); 
            }
        }
        entrada.close();
        return listaAux;
    }       
////1.7) Recuperar cursosGrupos; 
Lista_Cursos* Archivos::recuperarCursosGrupos(int numero) {
    Lista_Cursos* listaAux = new Lista_Cursos();
    string nombre, id, horas, precio, estado, periodo;
    Lista_Grupos* grupos;
    Lista_Profesores* profes;
    Curso* cursoAux = nullptr;
    entradaAux.open("Archivos/CursoGrupos.txt");
    while (entradaAux.good()) {
        getline(entradaAux, periodo, '\t');
        getline(entradaAux, nombre, '\t');
        getline(entradaAux, id, '\t');
        getline(entradaAux, horas, '\t');
        getline(entradaAux, precio, '\t');
        getline(entradaAux, estado, '\n');
        grupos = recuperarGruposGrupos(id);
        profes = recuperarProfesoresGrupos(id);
        if (!nombre.empty() && !id.empty() && !horas.empty() && !precio.empty() && !estado.empty()) {
            cursoAux = new Curso(nombre, id, convDatos.conversionInt(horas), convDatos.conversionDouble(precio), convDatos.conversionBool(estado));
            cursoAux->set_id(id);
            cursoAux->setGrupoLista(grupos);
            cursoAux->setProfeLista(profes);
        }
        if (entrada.good() && cursoAux && (numero == convDatos.conversionInt(periodo)))
            listaAux->insertarInicio(cursoAux);
    }
    entradaAux.close();
    return listaAux;
}
//1.8) Recuperar periodos
Lista_periodos* Archivos::recuperarPeriodos() {
    Lista_periodos* listaAux = new Lista_periodos();
    string nperiodos; 
    Lista_Cursos* curso; 
    Periodo* periodoAux = nullptr; 
    entrada.open("Archivos/Periodos.txt");
    while (entrada.good()) {
        getline(entrada, nperiodos, '\n');
        curso = recuperarCursosGrupos(convDatos.conversionInt(nperiodos));
        if (!nperiodos.empty()) {
            periodoAux = new Periodo(convDatos.conversionInt(nperiodos)); 
            periodoAux->setPeriodo(convDatos.conversionInt(nperiodos));
            periodoAux->setLista_Cursos(curso);
        }
        if (entrada.good() && periodoAux) {
            listaAux->ingresarPrimero(periodoAux);
        }
    }
    entrada.close(); 
    return listaAux; 
}
