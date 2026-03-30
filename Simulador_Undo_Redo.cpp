#include <iostream>
using namespace std;

// Nombre del estudiante
// DEYMI DAYANA MARTINEZ LOPEZ

// Estructura del nodo
struct Nodo {
    string accion;
    Nodo* siguiente;
};

// Función push (insertar en pila)
void push(Nodo*& pila, string accion) {
    Nodo* nuevo = new Nodo();
    nuevo->accion = accion;
    nuevo->siguiente = pila;
    pila = nuevo;
}

// Función pop (eliminar de pila)
string pop(Nodo*& pila) {
    if (pila == NULL) {
        return "";
    }

    Nodo* temp = pila;
    string accion = temp->accion;
    pila = pila->siguiente;
    delete temp;

    return accion;
}

// Mostrar pila
void mostrar(Nodo* pila) {
    if (pila == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* actual = pila;
    while (actual != NULL) {
        cout << "- " << actual->accion << endl;
        actual = actual->siguiente;
    }
}

// Limpiar pila completa
void limpiar(Nodo*& pila) {
    while (pila != NULL) {
        pop(pila);
    }
}

int main() {

    Nodo* acciones = NULL;  // pila principal
    Nodo* rehacer = NULL;  // pila de redo

    int opcion;
    string accion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Realizar accion\n";
        cout << "2. Deshacer (UNDO)\n";
        cout << "3. Rehacer (REDO)\n";
        cout << "4. Mostrar acciones actuales\n";
        cout << "5. Mostrar pila de rehacer\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {

            case 1:
                cout << "Ingrese la accion: ";
                getline(cin, accion);

                push(acciones, accion);
                limpiar(rehacer); // limpiar pila redo
                cout << "Accion realizada.\n";
                break;

            case 2:
                if (acciones == NULL) {
                    cout << "No hay acciones para deshacer.\n";
                } else {
                    string accionDeshecha = pop(acciones);
                    push(rehacer, accionDeshecha);
                    cout << "Accion deshecha: " << accionDeshecha << endl;
                }
                break;

            case 3:
                if (rehacer == NULL) {
                    cout << "No hay acciones para rehacer.\n";
                } else {
                    string accionRehecha = pop(rehacer);
                    push(acciones, accionRehecha);
                    cout << "Accion rehecha: " << accionRehecha << endl;
                }
                break;

            case 4:
                cout << "\nAcciones actuales:\n";
                mostrar(acciones);
                break;

            case 5:
                cout << "\nPila de rehacer:\n";
                mostrar(rehacer);
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    // Liberar memoria antes de salir
    limpiar(acciones);
    limpiar(rehacer);

    return 0;
}
