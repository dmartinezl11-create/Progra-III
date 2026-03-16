#include <iostream>
using namespace std;

//DEYMI DAYANA MARTINEZ LOPEZ

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    Nodo* head = NULL;
    Nodo* actual = NULL;

    int valor;
    char opcion = 's';

    int cantidad = 0;
    int suma = 0;

    while(opcion == 's') {

        cout << "Ingrese un numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if(head == NULL) {
            head = nuevo;
            actual = nuevo;
        }
        else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }

        cantidad++;
        suma = suma + valor;

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> opcion;
    }

    cout << "\nLista generada:\n";

    Nodo* temp = head;

    while(temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }

    cout << "NULL";

    float promedio = 0;

    if(cantidad > 0) {
        promedio = (float)suma / cantidad;
    }

    cout << "\nCantidad de nodos: " << cantidad;
    cout << "\nSuma de valores: " << suma;
    cout << "\nPromedio: " << promedio;

    return 0;
}
