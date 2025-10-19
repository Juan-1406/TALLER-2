#include "SparseMatrix.h"
using namespace std;
#include <iostream>

SparseMatrix::SparseMatrix() {
    start = nullptr;
}

void SparseMatrix::add(int value, int xPos, int yPos) {
    Node* actual = start;

    while (actual != nullptr) {
        if (actual -> x == xPos && actual -> y == yPos) {
            actual -> value = value;
            return;
        }
        actual = actual -> sgt;
    }

    Node* nuevoNodo = new Node(xPos, yPos, value);
    nuevoNodo -> sgt = start;
    start = nuevoNodo;
}

int SparseMatrix::get(int xPos, int yPos) {
    Node* actual = start;

    while (actual != nullptr) {
        if (actual -> x == xPos && actual -> y == yPos) {
            return actual -> value;
        }
        actual = actual -> sgt;
    }
    return 0;
}

void SparseMatrix::remove(int xPos, int yPos) {
    if (start == nullptr) {return;}

    if (start -> x == xPos && start -> y == yPos) {
        Node* temp = start;
        start = start -> sgt;
        delete temp;
        return;
    }

    Node* actual = start;
    while (actual -> sgt != nullptr && (actual -> sgt -> x != xPos || actual -> sgt -> y != yPos)) {
        actual = actual -> sgt;
    }

    if (actual -> sgt != nullptr) {
        Node* temp = actual -> sgt;
        actual -> sgt = actual -> sgt -> sgt;
        delete temp;
    }
}

void SparseMatrix::printStoredValues() {
    Node* actual = start;

    cout << "Stored Values:" << endl;
    if (actual == nullptr) {
        cout << "Matrix is empty" << endl;
        return;
    }

    while (actual != nullptr) {
        if (actual -> value != 0) {
            cout << "(" << actual -> x << ", " << actual -> y << ")" << " --> " << actual -> value << endl;
        }
        actual = actual -> sgt;
    }
}

int SparseMatrix::density() {
    Node* actual = start;

    int cantElementos = 0; //LOS ELEMENTOS DISTINTOS DE 0
    int maxX = 0;
    int maxY = 0;

    while (actual != nullptr) {
        if (actual -> value != 0) {
            cantElementos++;
        }
        if (actual -> x > maxX) {
            maxX = actual -> x;
        }
        if (actual -> y > maxY) {
            maxY = actual -> y;
        }
        actual = actual -> sgt;
    }

    if (cantElementos == 0) {return 0;}

    int tamañoTotal = (maxX + 1) * (maxY + 1);
    double densidad = (cantElementos * 100.0) / tamañoTotal;
    return densidad;
}

SparseMatrix *SparseMatrix::multiply(SparseMatrix *second) {
    SparseMatrix* resultado = new SparseMatrix();
    Node* nodoA = start;

    while (nodoA != nullptr) {
        Node* nodoB = second -> start;
        while (nodoB != nullptr) {
            if (nodoA -> y == nodoB ->x) {
                int valor = nodoA -> value * nodoB -> value;
                int posX = nodoA -> x;
                int posY = nodoB -> y;

                int valorActual = resultado -> get(posX, posY);
                resultado -> add(valorActual + valor, posX, posY);
            }
            nodoB = nodoB -> sgt;
        }
        nodoA = nodoA -> sgt;
    }
    return resultado;
}

SparseMatrix *SparseMatrix::crearMatrizB(SparseMatrix* nuevaMatriz) {

    int cant = 0;
    cout << "Creacion Matriz B" << endl;
    cout << "Cantidad de elementos agregar:"; cin >> cant;
    cout<< endl;

    for (int i = 0; i < cant; i++) {
        int x, y, valor;

        cout << "Ingrese Valor:"; cin >> valor;
        cout << "Ingrese xPos:"; cin >> x;
        cout << "Ingrese yPos:"; cin >> y;
        nuevaMatriz -> add(valor, x, y);
        cout << "Elemento agregado" << endl;
        cout<< endl;
    }
    return nuevaMatriz;
}

SparseMatrix::~SparseMatrix() {}