#include "Interfaz.h"

Interfaz::Interfaz() {
    this->periodo = new Lista_periodos(); 
    this->profes = new Lista_Profesores(); 
    this->estudiantes = new Lista_Estudiante();  
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
    period = new Periodo(periodo1);
    periodo->ingresarPrimero(period); 
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
    cin >> horas ;
    cout << endl;
    cout << "Ingrese el precio que tiene el curso: ";
    cin >> precio;
    cout << endl;
    cout << "Ingrese el estado del curso (Si esta Disponible : 1 y no Disponible: 0 ): ";
    cin >> estado;
    cout << endl;
    course = new Curso(nombre, id, horas, precio, estado);
    periodo->getPeriodoXNum(periodo1)->getCursos()->insertarInicio(course);
}
void Interfaz::ingresar_grupo() {
    int cupoMaximo, numGrupo;
    int dia, horas;
    string id_course;
    string evento;
    bool idValido = false;

    cout << "-------------------------------(5) Ingresar Grupos  --------------------------" << endl;
    cout << periodo->toStringPeriodos() << endl;

    // Bucle para validar el ID del curso
    while (!idValido) {
        cout << "Ingrese el id del curso: ";
        cin >> id_course;

        // Verificar si el curso existe en el periodo
        Curso* curso = periodo->getPrimero()->getPeriodo()->getCursos()->cursoXId(id_course);
        if (curso != nullptr) {
            idValido = true;
        }
        else {
            cout << "ID del curso no válido. Por favor, intente de nuevo." << endl;
        }
    }

    Curso* curso = periodo->getPrimero()->getPeriodo()->getCursos()->cursoXId(id_course);

    cout << endl;
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
    cout << "Ingrese el curso: ";
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
    int numGroup, numCursos, numPeriodo;

    cout << estudiantes->toString() << endl;
    cout << "Ingrese el id del estudiante que quiere matricular: ";
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

    cout << "Ingrese la cantidad de cursos que quiere matricular: ";
    cin >> numCursos;

    for (int i = 0; i < numCursos; i++) {
        cout << periodoSeleccionado->getCursos()->toStringCursos() << endl;
        cout << "Ingrese el id del curso que quiere matricular: ";
        cin >> idCourse;

        Curso* curso = periodoSeleccionado->getCursos()->cursoXId(idCourse);
        if (!curso) {
            cout << "ID del curso no válido. Proceso cancelado." << endl;
            continue;
        }

        cout << curso->getGrupoLista()->toString() << endl;
        cout << "Ingrese el número del grupo que está disponible para matricular: ";
        cin >> numGroup;

        Grupo* grupo = curso->getGrupoLista()->getGrupoXNumero(numGroup);
        if (!grupo) {
            cout << "Número de grupo no válido. Proceso cancelado." << endl;
            continue;
        }

        // Verificar que el grupo no esté lleno
        if (grupo->get_cantidadEstudiantes() >= grupo->get_cuposMaximos()) {
            cout << "El grupo está lleno. Proceso cancelado." << endl;
            continue;
        }

        // Verificar que el estudiante no esté ya matriculado en otro grupo del mismo curso
        if (grupo->estudianteYaMatriculado(estudiante)) {
            cout << "El estudiante ya está matriculado en otro grupo de este curso. Proceso cancelado." << endl;
            continue;
        }

        grupo->matricularEstudiante(estudiante);
        cout << "Estudiante matriculado exitosamente en el curso " << curso->get_id() << " en el grupo " << grupo->get_numGrupo() << "." << endl;

        // Generar y mostrar la factura detallada
        system("cls");
        cout << periodo->getPrimero()->getPeriodo()->getCursos()->ListaCursosEstudiante(estudiante->get_id());
    }
    cout << "Precio total a pagar : " << endl;
    cout << "Precio: " << periodoSeleccionado->getCursos()->PrecioTotal(id) << " colones" << endl;
}


void Interfaz::desmatricular_estudiante() { cout << "Has desmatriculado un estudiante" << endl; }

void Interfaz::submenu_busquedaInformes() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
        cout << "(1) Informe de profesores registrados" << endl;
        cout << "(2) Infomre de estudiantes registrados" << endl;
        cout << "(3) Informe de cursos registrados por un estudiante" << endl;
        cout << "(4) Informe de profesor especifico" << endl;
        cout << "(5) Informe de periodos habilitados para el annio" << endl;
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
void Interfaz::informe_ProfesoresRegistrados() { cout << "Generando informe de profesores registrados..." << endl; }
void Interfaz::informe_EstudiantesRegistrados() { cout << "Generando informe de estudiantes registrados..." << endl; }
void Interfaz::informe_CursosMatriculados_PorEstudiante() { cout << "Generando informe de cursos matriculados por un estudiante..." << endl; }
void Interfaz::informe_ProfesorEspecifico() { cout << "Generando informe de un profesor específico..." << endl; }
void Interfaz::informe_PeriodosHabilitados_ParaAnio() { cout << "Generando informe de periodos habilitados para el año..." << endl; }
void Interfaz::informe_GrupoEspecifico() { cout << "Generando informe de un grupo específico..." << endl; }

void Interfaz::guardar_datos() { cout << "Has guardado los datos" << endl; }