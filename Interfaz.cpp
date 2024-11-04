#include "Interfaz.h"

Interfaz::Interfaz() {
    this->periodo = new Periodo(); 
    this->profes = new Lista_Profesores(); 
    this->estudiantes = new Lista_Estudiante(); 
    this->cursoos = nullptr; 
    this->groups = nullptr; 
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
    int periodo; 
    Periodo* period = nullptr; 
    cout << "Periodo 1: Enero a Marzo " << endl; 
    cout << "Periodo 2: Abril a Junio " << endl; 
    cout << "Periodo 3: Julio a Septiembre " << endl; 
    cout << "Periodo 4: Octubre a Diciembre " << endl; 
    cout << "Eliga el periodo por medio del numero correspondiente (1 - 4) "; 
    cin >> periodo; 
    cout << endl; 
    period = new Periodo(periodo);
}
void Interfaz::ingresar_curso() { 
    string nombre, id; 
    int horas, precio, estado;
    Curso* course = nullptr; 
    cout << "-------------------------------(4) Ingresar Curso  --------------------------" << endl;
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
    periodo->getCursos()->insertarInicio(course);
}
void Interfaz::ingresar_grupo() {
    int num_Grupos, cupoMaximo;
    int dia, horas;
    string evento;
    cout << "-------------------------------(5) Ingresar Grupos  --------------------------" << endl;
    cout << "Ingrese el numero del curso: ";
    cin >> num_Grupos;
    cout << endl;
    cout << "Ingrese el cupo maximo del curso: ";
    cin >> cupoMaximo;
    cout << endl;

    // Initialize grupooo before using it
    Grupo* grupooo = new Grupo(num_Grupos, cupoMaximo);

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

    // Insert the group into the list
    periodo->getCursos()->getPrimero()->getTheCurso()->getGrupoLista()->insertarInicio(grupooo);
}
void Interfaz::asignar_ProfesorAGrupo() { 
    string id, CourseID ;
    cout << "-------------------------------(6) Asignar Profesor a Grupo  --------------------------" << endl;
    cout << "Ingrese el id del profesor :" << endl; 
    cin >> id; 
    cout << periodo->getCursos()->toStringCursos() << endl;
    cout << "Ingrese el id del Curso que quiere poner al profesor :" << endl; 
    cin >> CourseID;
    cout << periodo->getCursos()->getPrimero()->getTheCurso()->getGrupoLista()->toString() << endl; 
    cout << "Ingrese el id del grupo del curso que quiere meter al profe " << endl;

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
void Interfaz::matricular_estudiante() { cout << "Has matriculado un estudiante" << endl; }
void Interfaz::desmatricular_estudiante() { cout << "Has desmatriculado un estudiante" << endl; }

void Interfaz::submenu_busquedaInformes() {
    int opcion = 1;

    while (opcion != 0) {
        cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
        cout << "(1) Informe de profesores registrados" << endl;
        cout << "(2) Infomre de estudiantes registrados" << endl;
        cout << "(3) Informe de cursos registrados por un estudiante" << endl;
        cout << "(4) Informe de profesor especifico" << endl;
        cout << "(5) Informe de periodos habilitados para el anio" << endl;
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