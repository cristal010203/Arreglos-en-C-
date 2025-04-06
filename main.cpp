#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Limite de contactos
const int MAX_CONTACTOS = 100;

// Arreglos paralelos para los contactos
string nombres[MAX_CONTACTOS];
string telefonos[MAX_CONTACTOS];
int totalContactos = 0;

// Cargar los contactos desde un archivo
void cargarContactos() {
    ifstream archivo("contactos.txt");

    if (archivo.is_open()) {
        while (getline(archivo, nombres[totalContactos]) && getline(archivo, telefonos[totalContactos])) {
            totalContactos++;
            if (totalContactos >= MAX_CONTACTOS) break;  // Limite de contactos
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para cargar los contactos.\n";
    }
}
// Agregar un nuevo contacto
void agregarContacto() {
    if (totalContactos >= MAX_CONTACTOS) {
        cout << "Agenda llena.\n";
        return;
    }

    cout << "Nombre: ";
    getline(cin, nombres[totalContactos]);
    cout << "Telefono: ";
    getline(cin, telefonos[totalContactos]);

    totalContactos++;
    cout << "Contacto agregado.\n";
}


// Menú principal
int main() {
    int opcion;
    string dummy;

    // Cargar los contactos al iniciar el programa
    cargarContactos();
    do {
        cout << "\n=== Agenda de Contactos ===\n";
        cout << "1. Agregar contacto\n";

        cin >> opcion;
        getline(cin, dummy); // Limpiar el buffer

        switch (opcion) {
            case 1: agregarContacto(); break;
           
            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 6);

    return 0;


}
