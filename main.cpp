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

// Menú principal
int main() {
    int opcion;
    string dummy;

    // Cargar los contactos al iniciar el programa
    cargarContactos();
}