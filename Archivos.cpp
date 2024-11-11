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
    if (salidaAux.good()) {
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
void Archivos::guardarProfesoresGrupo(Lista_Profesores* lis_, int numGrupo) {
    if (salida.good()) {
        Nodo_Profesor* aux = lis_->getPrimero();
        while (aux) {
            salidaAux << numGrupo << "\t";
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
            salida << aux->getGrupo()->get_cuposMaximos() << "\n";
            guardarEstudiantesGrupo(aux->getGrupo()->getGrupoLista(), aux->getGrupo()->get_numGrupo());
            aux = aux->getNext();
        }
    }
    salida.close();
    salidaAux.close();
}

//6) Guardo Grupos de grupos jajajaajaj
void Archivos::guardarGruposNum(Lista_Grupos* lis_, int num) {
    if (salida.good()) {
        Nodo_Grupos* aux = lis_->getPrimero();
        while (aux) {
            salidaAux << num << "\t";
            salidaAux << aux->getGrupo()->get_numGrupo() << "\t";
            salidaAux << aux->getGrupo()->get_cuposMaximos() << "\n";
            aux = aux->getNext();
        }
    }
}

//7) Guardo Cursos
void Archivos::guardarCursos(Lista_Cursos* _lis) {
    salida.open("Archivos/Cursos.txt");
    salidaAux.open("Archivos/gruposDeGrupos.txt");
    salidaAux2.open("Archivos/ProfesoresLista.txt");
    if (salida.good() && salidaAux.good() && salidaAux2.good()) {
        Nodo_Cursos* aux = _lis->getPrimero();
        while (aux) {
            Curso* curso = aux->getTheCurso();
            salida << curso->get_nombre() << "\t";
            salida << curso->get_id() << "\t";
            salida << curso->get_horas() << "\t";
            salida << curso->get_precio() << "\t";
            salida << curso->get_estado() << "\n";

            // Guardar grupos del curso
            Lista_Grupos* grupos = curso->getGrupoLista();
            Nodo_Grupos* nodoGrupo = grupos->getPrimero();
            while (nodoGrupo) {
                Grupo* grupo = nodoGrupo->getGrupo();
                salidaAux << curso->get_id() << "\t";
                salidaAux << grupo->get_numGrupo() << "\t";
                salidaAux << grupo->get_cuposMaximos() << "\n";
                nodoGrupo = nodoGrupo->getNext();
            }

            // Guardar profesores del curso
            Lista_Profesores* profesores = curso->getProfeLista();
            Nodo_Profesor* nodoProfesor = profesores->getPrimero();
            while (nodoProfesor) {
                Profesor* profesor = nodoProfesor->getProfesor();
                salidaAux2 << curso->get_id() << "\t";
                salidaAux2 << profesor->get_nombre() << "\t";
                salidaAux2 << profesor->get_id() << "\t";
                salidaAux2 << profesor->get_numTelefono() << "\t";
                salidaAux2 << profesor->get_edad() << "\t";
                salidaAux2 << profesor->get_email() << "\t";
                salidaAux2 << profesor->get_gradoAcademico() << "\n";
                nodoProfesor = nodoProfesor->getNext();
            }

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
void Archivos::guardarCursosGrupos(Lista_Cursos* _lis){
    if (salida.good()) {
        Nodo_Cursos* aux = _lis->getPrimero(); 
        while (aux) {
            salidaAux << aux->getTheCurso()->get_nombre() << '\t';
            salidaAux << aux->getTheCurso()->get_id() << '\t';
            salidaAux << aux->getTheCurso()->get_horas() << '\t';
            salidaAux << aux->getTheCurso()->get_precio() << '\t';
            salidaAux << aux->getTheCurso()->get_estado() << '\n';
            aux = aux->getNext(); 
        }
    }
}
//9) Guardo Periodos
void Archivos::guardarPeriodos(Lista_periodos* _lis) {
    salida.open("Archivos/Periodos.txt");
    salidaAux.open("Archivos/CursosGrupos.txt");
    if (salida.good()) {
        Nodo_Periodo* aux = _lis->getPrimero();
        while (aux) {
            salida << aux->getPeriodo()->getPeriodo() << '\n';
            aux = aux->getNext();
        }
    }
    salida.close();
    salidaAux.close();
}

//8) Guardo Cursos con Grupos
//void Archivos::guardarCursosGrupos(Lista_Cursos* _lis) {
//    salida.open("Archivos/CursosGrupos.txt");
//    if (salida.good()) {
//        Nodo_Cursos* aux = _lis->getPrimero();
//        while (aux) {
//            Curso* curso = aux->getTheCurso();
//            Lista_Grupos* grupos = curso->getGrupoLista();
//            Nodo_Grupos* nodoGrupo = grupos->getPrimero();
//            while (nodoGrupo) {
//                Grupo* grupo = nodoGrupo->getGrupo();
//                salida << curso->get_id() << "\t";
//                salida << grupo->get_numGrupo() << "\t";
//                salida << grupo->get_cuposMaximos() << "\n";
//                nodoGrupo = nodoGrupo->getNext();
//            }
//            aux = aux->getNext();
//        }
//    }
//    else {
//        std::cerr << "Error al abrir el archivo para guardar los cursos con grupos." << std::endl;
//    }
//    salida.close();
//}

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

Lista_Profesores* Archivos::recuperarProfesoresGrupos(int num) {

    Lista_Profesores* listaAux = new Lista_Profesores();
    entradaAux.open("Archivos/ProfesoresLista.txt");
    string cedula, nombre, telefono, edad, email, gradoAcademico;
    string grupoNum;
    Profesor* eldep = nullptr;
    while (entradaAux.good()) {
        getline(entradaAux, grupoNum, '\t');
        getline(entradaAux, nombre, '\t');
        getline(entradaAux, cedula, '\t');
        getline(entradaAux, telefono, '\t');
        getline(entradaAux, edad, '\t');
        getline(entradaAux, email, '\t');
        getline(entradaAux, gradoAcademico, '\n');
        if (!nombre.empty() && !cedula.empty() && !telefono.empty() && !edad.empty() && !email.empty() && !gradoAcademico.empty()) {
            eldep = new Profesor(nombre, nombre, convDatos.conversionInt(telefono), convDatos.conversionInt(edad), email, gradoAcademico);
        }
        if (entrada.good() && eldep && (num == convDatos.conversionInt(grupoNum)))
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
        getline(entrada, cupoMaximo, '\n');
        estudiantes = recuperarEstudiantesGrupos(convDatos.conversionInt(numeroCurso));
        if (!numeroCurso.empty() && !cupoMaximo.empty()) {
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
Lista_Grupos* Archivos::recuperarGruposGrupos(int num) {
    Lista_Grupos* listagroups = new Lista_Grupos();
    string grupoNum, numeroCurso, cupoMaximo;
    Grupo* grupoAux = nullptr;
    entradaAux.open("Archivos/gruposDeGrupos.txt");

    if (entradaAux.is_open()) {
        while (entradaAux.good()) {
            getline(entradaAux, grupoNum, '\t');
            getline(entradaAux, numeroCurso, '\t');
            getline(entradaAux, cupoMaximo, '\n');

            if (!grupoNum.empty() && !numeroCurso.empty() && !cupoMaximo.empty() && num == convDatos.conversionInt(grupoNum)) {
                grupoAux = new Grupo(convDatos.conversionInt(numeroCurso), convDatos.conversionInt(cupoMaximo));
                listagroups->insertarInicio(grupoAux);
            }
        }
        entradaAux.close();
    }
    else {
        std::cerr << "Error al abrir el archivo para recuperar los grupos." << std::endl;
    }

    return listagroups;
}

//1.7) Recuperar Cursos
Lista_Cursos* Archivos::recuperarCursos() {
    Lista_Cursos* listaCursos = new Lista_Cursos();
    entrada.open("Archivos/Cursos.txt");
    if (entrada.good()) {
        string nombre, id, horas, precio, estado;
        while (entrada.good()) {
            getline(entrada, nombre, '\t');
            getline(entrada, id, '\t');
            getline(entrada, horas, '\t');
            getline(entrada, precio, '\t');
            getline(entrada, estado, '\n');
            if (!nombre.empty() && !id.empty() && !horas.empty() && !precio.empty() && !estado.empty()) {
                Curso* curso = new Curso(nombre, id, convDatos.conversionInt(horas), convDatos.conversionDouble(precio), estado == "1");

                // Recuperar grupos del curso
                Lista_Grupos* listaGrupos = new Lista_Grupos();
                entradaAux.open("Archivos/gruposDeGrupos.txt");
                if (entradaAux.good()) {
                    string numGrupo, cuposMaximos;
                    while (entradaAux.good()) {
                        getline(entradaAux, numGrupo, '\t');
                        getline(entradaAux, cuposMaximos, '\n');
                        if (!numGrupo.empty() && !cuposMaximos.empty()) {
                            Grupo* grupo = new Grupo(convDatos.conversionInt(numGrupo), convDatos.conversionInt(cuposMaximos));
                            listaGrupos->insertarInicio(grupo);
                        }
                    }
                }
                entradaAux.close();
                curso->setGrupoLista(listaGrupos);

                // Recuperar profesores del curso
                Lista_Profesores* listaProfesores = new Lista_Profesores();
                entradaAux2.open("Archivos/ProfesoresLista.txt");
                if (entradaAux2.good()) {
                    string nombreProfesor, idProfesor, telefonoProfesor, edadProfesor, emailProfesor, gradoAcademico;
                    while (entradaAux2.good()) {
                        getline(entradaAux2, nombreProfesor, '\t');
                        getline(entradaAux2, idProfesor, '\t');
                        getline(entradaAux2, telefonoProfesor, '\t');
                        getline(entradaAux2, edadProfesor, '\t');
                        getline(entradaAux2, emailProfesor, '\t');
                        getline(entradaAux2, gradoAcademico, '\n');
                        if (!nombreProfesor.empty() && !idProfesor.empty() && !telefonoProfesor.empty() && !edadProfesor.empty() && !emailProfesor.empty() && !gradoAcademico.empty()) {
                            Profesor* profesor = new Profesor(nombreProfesor, idProfesor, convDatos.conversionInt(telefonoProfesor), convDatos.conversionInt(edadProfesor), emailProfesor, gradoAcademico);
                            listaProfesores->InsertarInicio(profesor);
                        }
                    }
                }
                entradaAux2.close();
                curso->setProfeLista(listaProfesores);

                listaCursos->insertarInicio(curso);
            }
        }
    }
    entrada.close();
    return listaCursos;
}
////1.7) Recuperar cursosGrupos; 
Lista_Cursos* Archivos::recuperarCursosGrupos() {
    Lista_Cursos* listaCursos = new Lista_Cursos();
    string cursoId, nombreCurso, horas, precio, estado;
    Curso* cursoAux = nullptr;
    entradaAux.open("Archivos/CursosGrupos.txt");

    if (entradaAux.is_open()) {
        while (entradaAux.good()) {
            getline(entradaAux, cursoId, '\t');
            getline(entradaAux, nombreCurso, '\t');
            getline(entradaAux, horas, '\t');
            getline(entradaAux, precio, '\t');
            getline(entradaAux, estado, '\n');

            if (!cursoId.empty() && !nombreCurso.empty() && !horas.empty() && !precio.empty() && !estado.empty()) {
                cursoAux = new Curso(nombreCurso, cursoId, convDatos.conversionInt(horas), convDatos.conversionInt(precio), convDatos.conversionInt(estado));
                listaCursos->insertarInicio(cursoAux);
            }
        }
        entradaAux.close();
    }
    else {
        std::cerr << "Error al abrir el archivo para recuperar los cursos." << std::endl;
    }

    return listaCursos;
}

//1.8) Recuperar periodos
Lista_periodos* Archivos::recuperarPeriodos() {
    Lista_periodos* listaAux = new Lista_periodos();
    entrada.open("Archivos/Periodos.txt");
    if (entrada.good()) {
        string periodo;
        while (getline(entrada, periodo)) {
            if (!periodo.empty()) {
                Periodo* nuevoPeriodo = new Periodo();
                nuevoPeriodo->setPeriodo(convDatos.conversionInt(periodo));

                // Recuperar cursos del periodo
                Lista_Cursos* listaCursos = new Lista_Cursos();
                entradaAux.open("Archivos/Cursos.txt");
                if (entradaAux.good()) {
                    string nombre, id, horas, precio, estado;
                    while (entradaAux.good()) {
                        getline(entradaAux, nombre, '\t');
                        getline(entradaAux, id, '\t');
                        getline(entradaAux, horas, '\t');
                        getline(entradaAux, precio, '\t');
                        getline(entradaAux, estado, '\n');
                        if (!nombre.empty() && !id.empty() && !horas.empty() && !precio.empty() && !estado.empty()) {
                            Curso* curso = new Curso(nombre, id, convDatos.conversionInt(horas), convDatos.conversionDouble(precio), estado == "1");
                            listaCursos->insertarInicio(curso);
                        }
                    }
                }
                entradaAux.close();
                nuevoPeriodo->setLista_Cursos(listaCursos);

                listaAux->ingresarPrimero(nuevoPeriodo);
            }
        }
    }
    else {
        std::cerr << "Error al abrir el archivo Periodos.txt para recuperar los periodos." << std::endl;
    }
    entrada.close();
    return listaAux;
}
