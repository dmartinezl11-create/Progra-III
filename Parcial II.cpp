#include <iostream>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {

    cout << "Nombre: DEYMI DAYANA MARTÌNEZ LÒPEZ" << endl;
    cout << "----------------------------------" << endl;

    Nodo* primero = nullptr;
    Nodo* anterior = nullptr;

    for (int i = 0; i < 4; i++) {

        Nodo* nuevo = new Nodo;

        cout << "Ingrese codigo: ";
        cin >> nuevo->data.codigo;

        cout << "Ingrese nombre: ";
        cin >> nuevo->data.nombre;

        cout << "Ingrese precio: ";
        cin >> nuevo->data.precio;

        nuevo->siguiente = nullptr;

        if (primero == nullptr) {
            primero = nuevo;
        } else {
            anterior->siguiente = nuevo;
        }

        anterior = nuevo;

        cout << "--------------" << endl;
    }

    Nodo* actual = primero;
    double total = 0;

    while (actual != nullptr) {

        cout << "Codigo: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "--------------------" << endl;

        total += actual->data.precio;

        actual = actual->siguiente;
    }

    cout << "Total acumulado: Q" << total << endl;

    actual = primero;

    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual ->siguiente;
        delete temp;
    }

    primero = nullptr;

    return 0;
}
