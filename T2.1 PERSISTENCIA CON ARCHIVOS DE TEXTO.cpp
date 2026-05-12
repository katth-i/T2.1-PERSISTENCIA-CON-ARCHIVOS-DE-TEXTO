#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registrarEstudiante() {
    string nombre, carrera;
    int edad;
    float promedio;


    ofstream archivo;
    archivo.open("estudiantes.txt", ios::app);

    if (archivo.fail()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
    cin.ignore();
    cout << "Nombre completo: ";
    getline(cin, nombre);

    cout << "Carrera: ";
    getline(cin, carrera);


    do {
        cout << "Edad: ";
        cin >> edad;
        if (edad <= 0) cout << "Edad no valida. Intente de nuevo.\n";
    } while (edad <= 0);


    do {
        cout << "Promedio (0-10): ";
        cin >> promedio;
        if (promedio < 0 || promedio > 10) cout << "Promedio fuera de rango.\n";
    } while (promedio < 0 || promedio > 10);


    archivo << "Nombre: " << nombre << " | "
            << "Edad: " << edad << " | "
            << "Carrera: " << carrera << " | "
            << "Promedio: " << promedio << endl;

    archivo.close();
    cout << "¡Datos guardados correctamente!\n";
}

int main() {
    int opcion;

    do {
        cout << "\n==== MENU ESTUDIANTES ====" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 2);

    return 0;
}
