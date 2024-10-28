#include "Interfaz.h"

Interfaz::Interfaz() {}

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
            submenu_administarcion();
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

void Interfaz::submenu_administarcion() {
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
    //Profesor* profe_1 = new Profesor("chris", "1-18980608", 71840668, 20, "chrisblanco.2004@gmail.com", "Doctorado");

    cout << "Has ingresado un profesor" << endl << endl;
    //cout << "-------------------Info profesor-------------------" << endl;
    //cout << profe_1->toString() << endl;
    //delete profe_1;
}
void Interfaz::ingresar_estudiante() {
    //Estudiante* estudiante_1 = new Estudiante("josu", "1-1234567", 98765432, 19, "josher.16@gmail.com", "Ingenieria");

    cout << "Has ingresado un estudiante" << endl << endl;
    //cout << "-------------------Info estudiante-------------------" << endl;
    //cout << estudiante_1->toString() << endl;
    //delete estudiante_1;
}
void Interfaz::ingresar_Periodo() { cout << "Has ingresado un bloque o periodo" << endl; }
void Interfaz::ingresar_curso() { cout << "Has ingresado un curso" << endl; }
void Interfaz::ingresar_grupo() { cout << "Has ingresado un grupo" << endl; }
void Interfaz::asignar_ProfesorAGrupo() { cout << "Has asignado un profesor a un grupo" << endl; }

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