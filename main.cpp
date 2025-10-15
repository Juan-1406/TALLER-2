#include <iostream>
#include "SparseMatrix.h"
using namespace std;

void menu() {
    cout << "-- Sparse Matrix Menu --" << endl;
    cout << "1. Insertar Dato" << endl << "2. Obtener Dato" << endl << "3. Eliminar Dato" << endl;
    cout << "4. Imprimir Elementos" << endl << "5. Obtener Densidad" << endl << "6. Multiplicar Matriz" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opcion:";
}

int main() {
    SparseMatrix* matriz = new SparseMatrix();
    int opcion;

    do {
        menu(); cin >> opcion;
        int x, y, valor;

        switch (opcion) {
            case 0:
                cout << "Saliste con exito!" << endl;
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                cout << "Opcion invalida. Intentalo nuevamente" << endl << endl;
        }
    } while (opcion != 0);

    delete matriz;
    return 0;
}