#include <iostream>
using namespace std;

// Nombre del estudiante
// DEYMI DAYANA MARTINEZ LOPEZ

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

// Función para insertar al inicio
void insertarInicio(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    cout << "\nIngrese carne: ";
    cin >> nuevo->carne;
    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Ingrese apellido: ";
    getline(cin, nuevo->apellido);

    cout << "Ingrese carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = head;
    head = nuevo;

    cout << "\nEstudiante insertado al inicio.\n";
}

// Función para insertar al final
void insertarFinal(Nodo*& head) {
    Nodo* nuevo = new Nodo();

    cout << "\nIngrese carne: ";
    cin >> nuevo->carne;
    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Ingrese apellido: ";
    getline(cin, nuevo->apellido);

    cout << "Ingrese carrera: ";
    getline(cin, nuevo->carrera);

    nuevo->siguiente = NULL;

    if (head == NULL) {
        head = nuevo;
    } else {
        Nodo* temp = head;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }

    cout << "\nEstudiante insertado al final.\n";
}

// Mostrar estudiantes
void mostrar(Nodo* head) {
    if (head == NULL) {
        cout << "\nLista vacía.\n";
        return;
    }

    Nodo* temp = head;

    while (temp != NULL) {
        cout << "\nCarné: " << temp->carne << endl;
        cout << "Nombre: " << temp->nombre << endl;
        cout << "Apellido: " << temp->apellido << endl;
        cout << "Carrera: " << temp->carrera << endl;
        cout << "-----------------------------\n";

        temp = temp->siguiente;
    }
}

// Buscar estudiante
void buscar(Nodo* head) {
    int carne;
    cout << "\nIngrese carné a buscar: ";
    cin >> carne;

    Nodo* temp = head;

    while (temp != NULL) {
        if (temp->carne == carne) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << temp->nombre << endl;
            cout << "Apellido: " << temp->apellido << endl;
            cout << "Carrera: " << temp->carrera << endl;
            return;
        }
        temp = temp->siguiente;
    }

    cout << "\nEstudiante no encontrado.\n";
}

// Eliminar estudiante
void eliminar(Nodo*& head) {
    int carne;
    cout << "\nIngrese carné a eliminar: ";
    cin >> carne;

    Nodo* temp = head;
    Nodo* anterior = NULL;

    while (temp != NULL && temp->carne != carne) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        cout << "\nEstudiante no encontrado.\n";
        return;
    }

    // Si es el primero
    if (anterior == NULL) {
        head = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }

    delete temp;

    cout << "\nEstudiante eliminado correctamente.\n";
}

// Liberar memoria al final
void liberarLista(Nodo*& head) {
    Nodo* temp;
    while (head != NULL) {
        temp = head;
        head = head->siguiente;
        delete temp;
    }
}

int main() {

    Nodo* head = NULL;
    int opcion;

    cout << "====================================\n";
    cout << " SISTEMA DE ESTUDIANTES\n";
    cout << " Nombre: DEYMI DAYANA MARTINEZ LOPEZ\n";
    cout << "====================================\n";

    do {
        cout << "\nMENU:\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: insertarInicio(head); break;
            case 2: insertarFinal(head); break;
            case 3: mostrar(head); break;
            case 4: buscar(head); break;
            case 5: eliminar(head); break;
            case 6: cout << "\nSaliendo...\n"; break;
            default: cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 6);

    liberarLista(head);

    return 0;
}
