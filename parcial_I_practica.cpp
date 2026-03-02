#include <iostream>
using namespace std;

// Definición de la estructura
struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    // Crear dinámicamente tres nodos
    Nodo* nodo1 = new Nodo();
    Nodo* nodo2 = new Nodo();
    Nodo* nodo3 = new Nodo();

    // Solicitar valores al usuario
    cout << "Ingrese el valor del primer nodo: ";
    cin >> nodo1->dato;

    cout << "Ingrese el valor del segundo nodo: ";
    cin >> nodo2->dato;

    cout << "Ingrese el valor del tercer nodo: ";
    cin >> nodo3->dato;

    // Enlazar los nodos en el orden ingresado
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;
    nodo3->siguiente = nullptr;

    // Mostrar nombre completo del estudiante
    cout << "\nNombre del estudiante: Deymi Dayana Martínez López" << endl;

    // Mostrar valores accediendo mediante punteros
    cout << "\nValores almacenados en la lista:" << endl;

    Nodo* actual = nodo1;
    while (actual != nullptr) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }

    // Liberar memoria
    delete nodo1;
    delete nodo2;
    delete nodo3;

    return 0;
}
