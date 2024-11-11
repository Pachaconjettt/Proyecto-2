#include "Interfaz.h"

Interfaz::Interfaz() {
    archivos = new Archivos(); 
    this->periodo = archivos->recuperarPeriodos(); 
    this->profes = archivos->recuperarProfesores();
    this->estudiantes = archivos->recuperarEstudiante(); 
}

void Interfaz::menu_principal() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "---------------MENU PRINICIPAL--------------" << endl;
        cout << "(1) Submenu Administracion" << endl;
        cout << "(2) Submenu Matricula" << endl;
        cout << "(3) Submenu Busquedas e Informes" << endl;
        cout << "(4) Guardar datos" << endl;
        cout << "(0) Salir " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Digite una opcion del menu: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            submenu_administracion();
            break;
        }
        case 2: {
            system("cls");
            submenu_matricula();
            break;
        }
        case 3: {
            system("cls");
            submenu_busquedaInformes();
            break;
        }
        case 4: {
            system("cls");
            guardar_datos();
            cin.ignore();
            cin.get();
            break;
        }
        case 0: {
            break;
        }
        default: {
            system("cls");
            cout << "Opcion invalida. Presione 'ENTER' para volver al menu anterior." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        }
        system("cls");
    }
    cout << "Saliendo del programa..." << endl;
    exit(0);
}

void Interfaz::submenu_administracion() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
        cout << "(1) Ingresar profesor" << endl;
        cout << "(2) Ingresar estudiante" << endl;
        cout << "(3) Ingresar periodo" << endl;
        cout << "(4) Ingresar curso" << endl;
        cout << "(5) Ingresar grupo" << endl;
        cout << "(6) Asignar profesor a grupo" << endl;
        cout << "(0) Regresar al menu principal" << endl << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Digite una opcion del submenu: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            ingresar_profesor();
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            system("cls");
            ingresar_estudiante();
            cin.ignore();
            cin.get();
            break;
        }
        case 3: {
            system("cls");
            ingresar_Periodo();
            cin.ignore();
            cin.get();
            break;
        }
        case 4: {
            system("cls");
            ingresar_curso();
            cin.ignore();
            cin.get();
            break;
        }
        case 5: {
            system("cls");
            ingresar_grupo();
            cin.ignore();
            cin.get();
            break;
        }
        case 6: {
            system("cls");
            asignar_ProfesorAGrupo();
            cin.ignore();
            cin.get();
            break;
        }
        case 0: {
            break;
        }
        default: {
            system("cls");
            cout << "Opcion invalida. Presione 'ENTER' para volver al menu anterior." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        }
        system("cls");
    }
    system("cls");
}
void Interfaz::ingresar_profesor() {
    string nombre, id, email, grado_Academico;
    int telefono, edad;
    Profesor* teacher = nullptr;
    cout << "-------------------------------(1) Ingresar Profesor --------------------------" << endl;
    cout << "Ingrese el nombre: ";
    cin >> nombre; 
    cout << endl; 
    cout << "Ingrese el id: "; 
    cin >> id; 
    cout << endl; 
    cout << "Ingrese el telefono: ";
    cin >> telefono; 
    cout << endl; 
    cout << "Ingrese la edad del Profesor: "; 
    cin >> edad; 
    cout << endl; 
    cout << "Ingrese el email del profesor: ";
    cin >> email; 
    cout << endl; 
    cout << "Ingrese el grado academico: "; 
    cin >> grado_Academico;
    teacher = new Profesor(nombre, id, telefono, edad, email, grado_Academico);
    profes->InsertarInicio(teacher); 
}
void Interfaz::ingresar_estudiante() {
    string nombre, id, email, especialidad; 
    int telefono, edad;
    Estudiante* student = nullptr; 
    cout << "-------------------------------(2) Ingresar Estudiante --------------------------" << endl;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << endl;
    cout << "Ingrese el id: ";
    cin >> id;
    cout << endl;
    cout << "Ingrese el telefono: ";
    cin >> telefono;
    cout << endl;
    cout << "Ingrese la edad del estudiante: ";
    cin >> edad;
    cout << endl;
    cout << "Ingrese el email del estudiante: ";
    cin >> email;
    cout << endl;
    cout << "Ingrese la especialidad: ";
    cin >> especialidad;
    student = new Estudiante(nombre, id, telefono, edad, email, especialidad); 
    estudiantes->insertarInicio(student);
}
void Interfaz::ingresar_Periodo() { 
    cout << "-------------------------------(3) Ingresar Periodo --------------------------" << endl;
    int periodo1; 
    Periodo* period = nullptr; 
    cout << "Periodo 1: Enero a Marzo " << endl; 
    cout << "Periodo 2: Abril a Junio " << endl; 
    cout << "Periodo 3: Julio a Septiembre " << endl; 
    cout << "Periodo 4: Octubre a Diciembre " << endl; 
    cout << "Eliga el periodo por medio del numero correspondiente (1 - 4) "; 
    cin >> periodo1; 
    cout << endl; 
    Periodo* nuevoPeriodo = new Periodo(periodo1);
    periodo->ingresarPrimero(nuevoPeriodo);

    cout << "Periodo ingresado exitosamente." << endl;
}
void Interfaz::ingresar_curso() {
    string nombre, id;
    int horas, precio, estado;
    int periodo1;
    Curso* course = nullptr;
    cout << "-------------------------------(4) Ingresar Curso  --------------------------" << endl;
    cout << periodo->toStringPeriodos() << endl;
    cout << "Ingrese algun periodo de los periodos disponibles para ingresar a este curso " << endl;
    cin >> periodo1;
    cout << "Ingrese el nombre del curso: ";
    cin >> nombre;
    cout << endl;
    cout << "Ingrese el id del curso: ";
    cin >> id;
    cout << endl;
    cout << "Ingrese las horas que tiene el curso: ";
    cin >> horas;
    cout << endl;
    cout << "Ingrese el precio que tiene el curso: ";
    cin >> precio;
    cout << endl;
    cout << "Ingrese el estado del curso (Si esta Disponible : 1 y no Disponible: 0 ): ";
    cin >> estado;
    cout << endl;
    course = new Curso(nombre, id, horas, precio, estado);

    // Verificar si el periodo existe
    Periodo* selectedPeriodo = periodo->getPeriodoXNum(periodo1);
    if (selectedPeriodo != nullptr) {
        selectedPeriodo->getCursos()->insertarInicio(course);
        // Mensaje de depuración
        cout << "Curso añadido: " << course->toString() << endl;
        cout << "Cursos actuales en el periodo " << periodo1 << ":" << endl;
        cout << selectedPeriodo->getCursos()->toStringCursos() << endl;
    }
    else {
        cout << "Periodo no encontrado." << endl;
        delete course;
    }
}

void Interfaz::ingresar_grupo() {
    int cupoMaximo, numGrupo;
    int dia, horas;
    int numPeriodo;
    string id_course;
    string evento;
    bool idValido = false;

    cout << "-------------------------------(5) Ingresar Grupos  --------------------------" << endl;
    cout << periodo->toStringPeriodos() << endl;

    cout << "Ingrese el numero de periodo (1-4) para poner grupo en el curso: ";
    cin >> numPeriodo;

    // Verificar si el periodo existe
    Periodo* selectedPeriodo = periodo->getPeriodoXNum(numPeriodo);
    if (selectedPeriodo == nullptr) {
        cout << "Periodo no encontrado." << endl;
        return;
    }

    // Bucle para validar el ID del curso
    while (!idValido) {
        cout << "Ingrese el id del curso: ";
        cin >> id_course;

        // Verificar si el curso existe en el periodo
        Curso* curso = selectedPeriodo->getCursos()->cursoXId(id_course);
        if (curso != nullptr) {
            idValido = true;
        }
        else {
            cout << "ID del curso no válido. Por favor, intente de nuevo." << endl;
        }
    }

    Curso* curso = selectedPeriodo->getCursos()->cursoXId(id_course);

    cout << "Ingrese el numero del grupo: ";
    cin >> numGrupo;
    while (numGrupo <= 0 || curso->getGrupoLista()->getGrupoXNumero(numGrupo) != nullptr) {
        if (numGrupo <= 0) {
            cout << "Número de grupo inválido. Ingrese un número positivo: ";
        }
        else {
            cout << "Número de grupo ya en uso. Ingrese un número diferente: ";
        }
        cin >> numGrupo;
    }

    cout << "Ingrese el cupo máximo del curso: ";
    cin >> cupoMaximo;
    while (cupoMaximo <= 0) {
        cout << "Cupo máximo inválido. Ingrese un número positivo: ";
        cin >> cupoMaximo;
    }
    cout << endl;

    Grupo* grupooo = new Grupo(numGrupo, cupoMaximo);
    cout << "Ingrese el horario del Grupo: " << endl;
    cout << grupooo->getHorario()->toString() << endl;
    cout << "Ingrese el día (1-5, donde 1=Lun, 2=Mar, 3=Mie, 4=Jue, 5=Vie) o -1 para salir: ";
    cin >> dia;
    cout << "Ingrese la hora (1-5, donde 1=8-10, 2=10-12, 3=12-14, 4=14-16, 5=16-18): ";
    cin >> horas;
    cout << "Ingrese el nombre del curso: ";
    cin >> evento;
    grupooo->getHorario()->ingresar_evento(horas, dia, evento);
    cout << "Horario actual:" << endl;
    cout << grupooo->getHorario()->toString() << endl;

    curso->getGrupoLista()->insertarInicio(grupooo);
}



void Interfaz::asignar_ProfesorAGrupo() {
    string id, CourseID;
    int numGrupo, numPeriodo;
    cout << "-------------------------------(6) Asignar Profesor a Grupo  --------------------------" << endl;
    cout << profes->toString() << endl;
    cout << "Ingrese el id del profesor: ";
    cin >> id;

    Profesor* profesor = profes->getProfesorXId(id);
    if (profesor == nullptr) {
        cout << "ID del profesor no válido. Proceso cancelado." << endl;
        return;
    }

    cout << periodo->toStringPeriodos() << endl;
    cout << "Ingrese el número del periodo: ";
    cin >> numPeriodo;

    Periodo* periodoSeleccionado = periodo->getPeriodoXNum(numPeriodo);
    if (periodoSeleccionado == nullptr) {
        cout << "Número de periodo no válido. Proceso cancelado." << endl;
        return;
    }

    cout << periodoSeleccionado->getCursos()->toStringCursos() << endl;
    cout << "Ingrese el id del Curso que quiere poner al profesor: ";
    cin >> CourseID;

    Curso* curso = periodoSeleccionado->getCursos()->cursoXId(CourseID);
    if (curso == nullptr) {
        cout << "ID del curso no válido. Proceso cancelado." << endl;
        return;
    }

    cout << curso->getGrupoLista()->toString() << endl;
    cout << "Ingrese el número del grupo del curso que quiere meter al profe: ";
    cin >> numGrupo;

    Grupo* grupo = curso->getGrupoLista()->getGrupoXNumero(numGrupo);
    if (grupo == nullptr) {
        cout << "Número de grupo no válido. Proceso cancelado." << endl;
        return;
    }

    grupo->unirProfesorAGrupo(profesor);
    cout << "Proceso completo." << endl;
}


void Interfaz::submenu_matricula() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
        cout << "(1) Matricular estudiante" << endl;
        cout << "(2) Desmatricular estudiante" << endl;
        cout << "(0) Regresar al menu principal" << endl << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Digite una opcion del submenu: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            matricular_estudiante();
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            system("cls");
            desmatricular_estudiante();
            cin.ignore();
            cin.get();
            break;
        }
        case 0: {
            break;
        }
        default: {
            system("cls");
            cout << "Opcion invalida. Presione 'ENTER' para volver al menu anterior." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        }
        system("cls");
    }
    system("cls");
}
void Interfaz::matricular_estudiante() {
    string id, idCourse;
    int numGroup, numPeriodo;
    char continuar;

    cout << estudiantes->toString() << endl;
    cout << "Ingrese el id del estudiante que quiere matricular: ";
    cin >> id;

    Estudiante* estudiante = estudiantes->buscarEstudianteXID(id);
    if (!estudiante) {
        cout << "ID del estudiante no válido. Proceso cancelado." << endl;
        return;
    }
    cout << periodo->toStringPeriodos() << endl;
    cout << "\t SOLO PUEDE ESCOGER UN PERIODO PARA LA MATRICULA \t" << endl;
    cout << "Ingrese el número del periodo: ";
    cin >> numPeriodo;

    do {
        Periodo* periodoSeleccionado = periodo->getPeriodoXNum(numPeriodo);
        if (periodoSeleccionado == nullptr) {
            cout << "Número de periodo no válido. Proceso cancelado." << endl;
            continue;
        }

        cout << periodoSeleccionado->toString() << endl;
        cout << "Ingrese el id del curso: ";
        cin >> idCourse;

        Curso* cursoSeleccionado = periodoSeleccionado->getCursos()->cursoXId(idCourse);
        if (cursoSeleccionado == nullptr) {
            cout << "ID del curso no válido. Proceso cancelado." << endl;
            continue;
        }
        cout << periodo->getPeriodoXNum(numPeriodo)->getCursos()->cursoXId(idCourse)->getGrupoLista()->toString();
        cout << endl; 
        cout << "Ingrese el número del grupo: ";
        cin >> numGroup;

        Grupo* grupoSeleccionado = cursoSeleccionado->getGrupoLista()->getGrupoXNumero(numGroup);
        if (grupoSeleccionado == nullptr) {
            cout << "Número de grupo no válido. Proceso cancelado." << endl;
            continue;
        }

        if (grupoSeleccionado->estudianteYaMatriculado(estudiante)) {
            cout << "El estudiante ya está matriculado en este grupo." << endl;
            continue;
        }

        grupoSeleccionado->matricularEstudiante(estudiante);
        cout << "Estudiante matriculado exitosamente." << endl;

        cout << "¿Desea matricular al estudiante en otro curso? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    // Generar y mostrar la factura detallada
    system("cls");
    cout << "\t\t\t\t Cursos matriculados por el estudiante: \t\t\t\t " << endl;
    mostrarFactura(id, numPeriodo);
}
void Interfaz::mostrarFactura(const string & estudianteId, int numPeriodo) {
    Periodo* periodoSeleccionado = periodo->getPeriodoXNum(numPeriodo);
    if (periodoSeleccionado == nullptr) {
        cout << "Número de periodo no válido. Proceso cancelado." << endl;
        return;
    }

    Estudiante* estudiante = estudiantes->buscarEstudianteXID(estudianteId);
    if (estudiante == nullptr) {
        cout << "ID del estudiante no válido. Proceso cancelado." << endl;
        return;
    }

    Lista_Cursos* cursos = periodoSeleccionado->getCursos();
    double subtotal = cursos->PrecioTotal(estudianteId);
    double IVA = 0.13;
    double descuento = cursos->PrecioTotal(estudianteId) - cursos->PrecioConDescuento(estudianteId);
    double total = cursos->PrecioConDescuento(estudianteId);
    double ivaMonto = subtotal * IVA;

    cout << "\t\t\t\t Factura de Matrícula \t\t\t\t" << endl;
    cout << "Curso\t\t" << endl;
    cout << cursos->ListaCursosEstudiante(estudianteId) << endl;

    cout << "Subtotal: " << subtotal << " colones" << endl;
    cout << "IVA (13%): " << ivaMonto << " colones" << endl;
    cout << "Descuento: " << descuento << " colones" << endl;
    cout << "Total a pagar: " << total << " colones" << endl;
}


void Interfaz::desmatricular_estudiante() {
    string id, idCourse;
    int numGroup, numPeriodo;

    cout << estudiantes->toString() << endl;
    cout << "Ingrese el id del estudiante que quiere desmatricular: ";
    cin >> id;

    Estudiante* estudiante = estudiantes->buscarEstudianteXID(id);
    if (!estudiante) {
        cout << "ID del estudiante no válido. Proceso cancelado." << endl;
        return;
    }

    cout << periodo->toStringPeriodos() << endl;
    cout << "Ingrese el número del periodo: ";
    cin >> numPeriodo;

    Periodo* periodoSeleccionado = periodo->getPeriodoXNum(numPeriodo);
    if (periodoSeleccionado == nullptr) {
        cout << "Número de periodo no válido. Proceso cancelado." << endl;
        return;
    }

    cout << periodoSeleccionado->toString() << endl;
    cout << "Ingrese el id del curso: ";
    cin >> idCourse;

    Curso* cursoSeleccionado = periodoSeleccionado->getCursos()->cursoXId(idCourse);
    if (cursoSeleccionado == nullptr) {
        cout << "ID del curso no válido. Proceso cancelado." << endl;
        return;
    }

    cout << "Ingrese el número del grupo: ";
    cin >> numGroup;

    Grupo* grupoSeleccionado = cursoSeleccionado->getGrupoLista()->getGrupoXNumero(numGroup);
    if (grupoSeleccionado == nullptr) {
        cout << "Número de grupo no válido. Proceso cancelado." << endl;
        return;
    }

    if (!grupoSeleccionado->estudianteYaMatriculado(estudiante)) {
        cout << "El estudiante no está matriculado en este grupo." << endl;
        return;
    }

    // Eliminar al estudiante del grupo
    grupoSeleccionado->desmatricularEstudiante(estudiante); 

    cout << "Estudiante desmatriculado exitosamente." << endl;
}


void Interfaz::submenu_busquedaInformes() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
        cout << "(1) Informe de profesores registrados" << endl;
        cout << "(2) Informe de estudiantes registrados" << endl;
        cout << "(3) Informe de cursos registrados por un estudiante" << endl;
        cout << "(4) Informe de profesor especifico" << endl;
        cout << "(5) Informe de periodos habilitados para el annio" << endl;
        cout << "(6) Informe Grupo especifico " << endl; 
        cout << "(0) Regresar al menu principal" << endl << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Digite una opcion del submenu: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            informe_ProfesoresRegistrados();
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            system("cls");
            informe_EstudiantesRegistrados();
            cin.ignore();
            cin.get();
            break;
        }
        case 3: {
            system("cls");
            informe_CursosMatriculados_PorEstudiante();
            cin.ignore();
            cin.get();
            break;
        }
        case 4: {
            system("cls");
            informe_ProfesorEspecifico();
            cin.ignore();
            cin.get();
            break;
        }
        case 5: {
            system("cls");
            informe_PeriodosHabilitados_ParaAnio();
            cin.ignore();
            cin.get();
            break;
        }
        case 6: {
            system("cls");
            informe_GrupoEspecifico();
            cin.ignore();
            cin.get();
            break;
        }
        case 0: {
            break;
        }
        default: {
            system("cls");
            cout << "Opcion invalida. Presione 'ENTER' para volver al menu anterior." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        }
        system("cls");
    }
    system("cls");
}

void Interfaz::informe_ProfesoresRegistrados() {
    cout << "\t\t\t Informe Profesores Registrados \t\t\t" << endl;
    cout << profes->toString() << endl;
}
void Interfaz::informe_EstudiantesRegistrados() { 
    cout << "\t\t\t Informe Estudiantes Registrados \t\t\t" << endl;
    cout << estudiantes->toString() << endl;
}
void Interfaz::informe_CursosMatriculados_PorEstudiante() {
    string id;
    int period;
    cout << "\t\t\t Informe Cursos Matriculados Por Estudiante \t\t\t" << endl;
    cout << estudiantes->toString() << endl; 
    cout << "Ingrese el id del estudiante : " << endl;
    cin >> id;
    cout << "Ingrese el periodo : " << endl;
    cin >> period;
    system("cls");
    cout << "Cursos matriculados por el estudiante : " << endl; 
    cout << periodo->getPeriodoXNum(period)->getCursos()->ListaCursosEstudiante(id) << endl;
}
void Interfaz::informe_ProfesorEspecifico() {
    string id; 
    int period; 
    cout << "\t\t\t Informe Profesores especificos cursos \t\t\t" << endl;
    cout << "Periodo 1: Enero a Marzo " << endl;
    cout << "Periodo 2: Abril a Junio " << endl;
    cout << "Periodo 3: Julio a Septiembre " << endl;
    cout << "Periodo 4: Octubre a Diciembre " << endl;
    cout << "Ingrese el número del periodo: ";
    cin >> period; 
    cout << profes->toString() << endl; 
    cout << "Ingrese el id del profesor que desea ver los cursos " << endl; 
    cin >> id; 
    system("cls");
    cout << "Cursos y grupos que imparte el profesor : " << endl; 
    cout << periodo->getPeriodoXNum(period)->getCursos()->ListaCursosProfesor(id) << endl; 
}


void Interfaz::informe_PeriodosHabilitados_ParaAnio() { 
    cout << "\t\t\t Informe Periodos habilitados para el annio 2024 \t\t\t" << endl;
    cout << periodo->toStringPeriodos() << endl; 
}
void Interfaz::informe_GrupoEspecifico() {
    int numPeriodo;
    string idCourse;
    cout << "Periodo 1: Enero a Marzo " << endl;
    cout << "Periodo 2: Abril a Junio " << endl;
    cout << "Periodo 3: Julio a Septiembre " << endl;
    cout << "Periodo 4: Octubre a Diciembre " << endl;

    cout << "Ingrese el número del periodo: ";
    cin >> numPeriodo;

    Periodo* periodoSeleccionado = periodo->getPeriodoXNum(numPeriodo);
    if (periodoSeleccionado == nullptr) {
        cout << "Número de periodo no válido. Proceso cancelado." << endl;
        return;
    }

    cout << periodoSeleccionado->toString() << endl;
    cout << "Ingrese el id del curso: ";
    cin >> idCourse;

    Curso* cursoSeleccionado = periodoSeleccionado->getCursos()->cursoXId(idCourse);
    if (cursoSeleccionado == nullptr) {
        cout << "ID del curso no válido. Proceso cancelado." << endl;
        return;
    }

    cout << cursoSeleccionado->getGrupoLista()->toString() << endl;
    cout << "Ingrese el número del grupo: ";
    int numGroup;
    cin >> numGroup;

    Grupo* grupoSeleccionado = cursoSeleccionado->getGrupoLista()->getGrupoXNumero(numGroup);
    if (grupoSeleccionado == nullptr) {
        cout << "Número de grupo no válido. Proceso cancelado." << endl;
        return;
    }
    system("cls");
    cout << grupoSeleccionado->toString() << endl;
}

void Interfaz::guardar_datos() { 
    int i;
    string id; 
    archivos->guardarEstudiantes(estudiantes); 
    archivos->guardarProfesores(profes);
    cout << "Elige un num de periodo para guardar los cursos" << endl; 
    cin >> i; 
    archivos->guardarPeriodos(periodo); 
    archivos->guardarCursos(periodo->getPeriodoXNum(i)->getCursos());
    cout << periodo->toStringPeriodos() << endl;
    cout << "Elige el id del curso para guardar los grupos "<< endl;
    cin >> id; 
    archivos->guardarGrupos(periodo->getPeriodoXNum(i)->getCursos()->cursoXId(id)->getGrupoLista());
    cout << "Has guardado los datos" << endl; 
}