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
                cout << "Ingrese Valor:"; cin >> valor;
                cout << "Ingrese xPos:"; cin >> x;
                cout << "Ingrese yPos:"; cin >> y;
                matriz -> add(valor, x, y);
                cout << "Elemento agregado" << endl;
                cout<< endl;
                break;
            case 2:
                cout << "Ingrese xPos:"; cin >> x;
                cout << "Ingrese yPos:"; cin >> y;
                cout << "Valor en (" << x <<", " << y << ") es: "<< matriz -> get(x, y) << endl;
                cout << endl;
                break;
            case 3:
                cout << "Ingrese xPos:"; cin >> x;
                cout << "Ingrese yPos:"; cin >> y;
                matriz -> remove(x, y);
                cout << "Elemento eliminado" << endl;
                cout << endl;
                break;
            case 4:
                matriz -> printStoredValues();
                cout << endl;
                break;
            case 5:
                cout << "Densidad de la Matriz: " << matriz ->density() << " %" << endl;
                cout << endl;
                break;
            case 6: {
                SparseMatrix* matrizB = new SparseMatrix();
                matrizB ->crearMatrizB(matrizB);

                cout << "Matriz A:" << endl;
                matriz -> printStoredValues();
                cout << endl << "Matriz B:" << endl;
                matrizB ->printStoredValues();

                SparseMatrix* resultado = matriz -> multiply(matrizB);

                cout << endl << "Resultado de A * B:" << endl;
                resultado -> printStoredValues();

                delete matrizB;
                delete resultado;
                cout << endl;
                break;
            }
            default:
                cout << "Opcion invalida. Intentalo nuevamente" << endl << endl;
        }
    } while (opcion != 0);

    delete matriz;
    return 0;
}