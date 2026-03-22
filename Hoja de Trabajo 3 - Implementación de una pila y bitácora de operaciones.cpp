#include <iostream>
using namespace std;

// DEYMI DAYANA MARTINEZ LOPEZ

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función push (insertar)
void push(Nodo*& tope, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Elemento insertado correctamente.\n";
}

// Función pop (eliminar)
void pop(Nodo*& tope) {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia.\n";
        return;
    }

    Nodo* aux = tope;
    cout << "Elemento eliminado: " << aux->dato << endl;
    tope = tope->siguiente;
    delete aux;
}

// Función peek (ver tope)
void peek(Nodo* tope) {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia.\n";
    } else {
        cout << "Elemento en el tope: " << tope->dato << endl;
    }
}

// Mostrar pila
void mostrar(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    Nodo* actual = tope;
    cout << "Elementos de la pila:\n";

    while (actual != NULL) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }
}

// Contar elementos
int contarElementos(Nodo* tope) {
    int contador = 0;
    Nodo* actual = tope;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

// Buscar elemento
void buscarElemento(Nodo* tope, int valor) {
    if (tope == NULL) {
        cout << "Error: La pila esta vacia.\n";
        return;
    }

    Nodo* actual = tope;
    int posicion = 1;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == valor) {
            cout << "Elemento encontrado en la posicion: " << posicion << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "Elemento no encontrado.\n";
    }
}

// Vaciar pila
void vaciarPila(Nodo*& tope) {
    if (tope == NULL) {
        cout << "La pila ya esta vacia.\n";
        return;
    }

    while (tope != NULL) {
        Nodo* aux = tope;
        tope = tope->siguiente;
        delete aux;
    }

    cout << "Pila vaciada correctamente.\n";
}

// Menú principal
int main() {
    Nodo* tope = NULL;
    int opcion, valor;

    cout << "=====================================\n";
    cout << " DEYMI DAYANA MARTINEZ LOPEZ\n";
    cout << " SISTEMA DE PILA DINAMICA\n";
    cout << "=====================================\n";

    do {
        cout << "\nMENU:\n";
        cout << "1. Insertar (push)\n";
        cout << "2. Eliminar (pop)\n";
        cout << "3. Ver tope (peek)\n";
        cout << "4. Mostrar pila\n";
        cout << "5. Contar elementos\n";
        cout << "6. Buscar elemento\n";
        cout << "7. Vaciar pila\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                push(tope, valor);
                break;

            case 2:
                pop(tope);
                break;

            case 3:
                peek(tope);
                break;

            case 4:
                mostrar(tope);
                break;

            case 5:
                cout << "Cantidad de elementos: " << contarElementos(tope) << endl;
                break;

            case 6:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                buscarElemento(tope, valor);
                break;

            case 7:
                vaciarPila(tope);
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 8);

    return 0;
}
