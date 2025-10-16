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

int SparseMatrix::density() {}

SparseMatrix *SparseMatrix::multiply(SparseMatrix *second) {}

SparseMatrix::~SparseMatrix() {}