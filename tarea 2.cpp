#include <iostream>
using namespace std;

int main() {

    int* p = new int;

    *p = 50;

    cout << "Direccion almacenada en el puntero (contenido de p): " << p << endl;
    cout << "Valor almacenado en esa direccion (*p): " << *p << endl;
    cout << "Direccion del puntero (&p): " << &p << endl;

    delete p;

    p = nullptr;

    return 0;
}
