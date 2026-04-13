#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

//-----------PILA------------
//INSERTAR PILA (push)
void push(Nodo*& pila, int valor){
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = pila;
    pila = nuevo;
}

//ELIMINAR PILA(POP)
void pop(Nodo*& pila){
    if(pila == NULL){
        cout << "Pila vacia" << endl;
        return;
    }
    Nodo* aux = pila;
    pila = pila ->siguiente;
    delete aux;
}

void peekPila(Nodo* pila){
    if(pila == NULL){
        cout << "Pila vacia\n";
    } else {
        cout << "Tope: " << pila->dato << endl;
    }
}

//MOSTRAR PILA
void mostrarPila(Nodo* pila){
    Nodo* aux = pila;
    while(aux != NULL){
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "NULL\n";
}

// -------------COLA------------------

// INSERTAR EN COLA (enqueue)
void enqueue(Nodo*& frente, Nodo*& final, int valor){
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(frente == NULL){
        frente = nuevo;
    } else {
        final->siguiente = nuevo;
    }
    final = nuevo;
}

// ELIMINAR DE COLA (dequeue)
void dequeue(Nodo*& frente, Nodo*& final){
    if(frente == NULL){
        cout << "Cola vacia\n";
        return;
    }
    Nodo* aux = frente;
    frente = frente->siguiente;

    if(frente == NULL){
        final = NULL;
    }

    delete aux;
}

void peekCola(Nodo* frente){
    if(frente == NULL){
        cout << "Cola vacia\n";
    } else {
        cout << "Frente: " << frente->dato << endl;
    }
}

// MOSTRAR COLA
void mostrarCola(Nodo* frente){
    Nodo* aux = frente;
    while(aux != NULL){
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "NULL\n";
}

// LISTA

// INSERTAR EN LISTA
void insertarLista(Nodo*& lista, int valor){
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = lista;
    lista = nuevo;
}

// MOSTRAR LISTA
void mostrarLista(Nodo* lista){
    Nodo* aux = lista;
    while(aux != NULL){
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "NULL\n";
}

// ORDENAR LISTA (BONUS)
void ordenarLista(Nodo* lista){
    Nodo* actual;
    Nodo* siguiente;
    int temp;

    for(actual = lista; actual != NULL; actual = actual->siguiente){
        for(siguiente = actual->siguiente; siguiente != NULL; siguiente = siguiente->siguiente){

            if(actual->dato > siguiente->dato){
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
        }
    }
}

// ---------------- CLASIFICACION ----------------
void clasificarNumero(int num, Nodo*& pila, Nodo*& frente, Nodo*& final, Nodo*& lista, int& pares, int& impares){

    if(num < 0 && num != -1){
        insertarLista(lista, num);
    }
    else if(num % 2 == 0){
        enqueue(frente, final, num);
        pares++;
    }
    else{
        push(pila, num);
        impares++;
    }
}

// ---------------- LIBERAR MEMORIA ----------------
void liberar(Nodo*& estructura){
    while(estructura != NULL){
        Nodo* aux = estructura;
        estructura = estructura->siguiente;
        delete aux;
    }
}

int main(){
     //MOSTRAR NOMBRE DEL ESTUDIANTE
    cout<<endl;
    cout<< "Nombre: ERICKA DANIELA CALDERA GOMEZ"<<endl;

    Nodo* pila = NULL;
    Nodo* frente = NULL;
    Nodo* final = NULL;
    Nodo* lista = NULL;

    int opcion, num;
    int pares = 0, impares = 0;

    do{
        cout << "\n------ MENU ------" << endl;
        cout << "\n1. Ingresar numero";
        cout << "\n2. Mostrar pila";
        cout << "\n3. Mostrar cola";
        cout << "\n4. Mostrar lista";
        cout << "\n5. Eliminar de pila";
        cout << "\n6. Eliminar de cola";
        cout << "\n7. Peek pila";
        cout << "\n8. Peek cola";
        cout << "\n9. Estadisticas";
        cout << "\n10. Ordenar lista";
        cout << "\n11. Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:
                cout << "Ingrese numero (-1 para terminar): ";
                cin >> num;

                if(num != -1){
                    clasificarNumero(num, pila, frente, final, lista, pares, impares);
                }
                break;

            case 2:
                mostrarPila(pila);
                break;

            case 3:
                mostrarCola(frente);
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 5:
                pop(pila);
                break;

            case 6:
                dequeue(frente, final);
                break;

            case 7:
                peekPila(pila);
                break;

            case 8:
                peekCola(frente);
                break;

            case 9:
                cout << "Pares: " << pares << endl;
                cout << "Impares: " << impares << endl;
                break;

            case 10:
                ordenarLista(lista);
                cout << "Lista ordenada\n";
                break;

        }

    }while(opcion != 11);

    // LIMPIEZA FINAL (BONUS)
    liberar(pila);
    liberar(frente);
    liberar(lista);

    return 0;
}
