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
// Mostrar todos los contactos
void mostrarContactos() {
    cout << "\n--- Lista de Contactos ---\n";
    if (totalContactos == 0) {
        cout << "No hay contactos.\n";
        return;
    }

    for (int i = 0; i < totalContactos; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << telefonos[i] << endl;
    }
}
// Buscar un contacto por nombre o teléfono
void buscarContacto() {
    string buscar;
    bool encontrado = false;

    cout << "Buscar por nombre o telefono: ";
    getline(cin, buscar);

    for (int i = 0; i < totalContactos; i++) {
        if (nombres[i].find(buscar) != string::npos || telefonos[i].find(buscar) != string::npos) {
            cout << "Encontrado: " << nombres[i] << " - " << telefonos[i] << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Contacto no encontrado.\n";
    }
}
// Modificar un contacto
void modificarContacto() {
    string buscar;
    cout << "Nombre o telefono del contacto a modificar: ";
    getline(cin, buscar);

    for (int i = 0; i < totalContactos; i++) {
        if (nombres[i].find(buscar) != string::npos || telefonos[i].find(buscar) != string::npos) {
            cout << "Nuevo nombre: ";
            getline(cin, nombres[i]);
            cout << "Nuevo telefono: ";
            getline(cin, telefonos[i]);
            cout << "Contacto modificado.\n";
            return;
        }
    }

    cout << "Contacto no encontrado.\n";
}
// Eliminar un contacto
void eliminarContacto() {
    string buscar;
    cout << "Nombre o telefono del contacto a eliminar: ";
    getline(cin, buscar);

    for (int i = 0; i < totalContactos; i++) {
        if (nombres[i].find(buscar) != string::npos || telefonos[i].find(buscar) != string::npos) {
            for (int j = i; j < totalContactos - 1; j++) {
                nombres[j] = nombres[j + 1];
                telefonos[j] = telefonos[j + 1];
            }
            totalContactos--;
            cout << "Contacto eliminado.\n";
            return;
        }
    }

    cout << "Contacto no encontrado.\n";
}
// Guardar los contactos en un archivo
void guardarContactos() {
    ofstream archivo("contactos.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < totalContactos; i++) {
            archivo << nombres[i] << endl;
            archivo << telefonos[i] << endl;
        }
        archivo.close();
        cout << "Contactos guardados en el archivo.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar los contactos.\n";
    }
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
        cout << "2. Mostrar contactos\n";
        cout << "3. Buscar contacto\n";
        cout << "4. Modificar contacto\n";
        cout << "5. Eliminar contacto\n";
        cout << "6. Guardar y salir\n";
        cout << "Elige una opcion: ";


        cin >> opcion;
        getline(cin, dummy); // Limpiar el buffer

        switch (opcion) {
            case 1: agregarContacto(); break;
            case 2: mostrarContactos(); break;
            case 3: buscarContacto(); break;
            case 4: modificarContacto(); break;
            case 5: eliminarContacto(); break;
            case 6: guardarContactos();
            cout << "Saliendo...\n";
            break;



            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 6);

    return 0;

}
