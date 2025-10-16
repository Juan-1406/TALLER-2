#include "SparseMatrix.h"
using namespace std;
#include <iostream>

SparseMatrix::SparseMatrix() {}

void SparseMatrix::add(int value, int xPos, int yPos) {
    Node* actual = star;

    while (actual != nullptr) {
        if (actual -> x == xPos && actual -> y == yPos) {
            actual -> value = value;
            return;
        }
        actual = actual -> sgt;
    }

    Node* nuevoNodo = new Node(xPos, yPos, value);
    nuevoNodo -> sgt = star;
    star = nuevoNodo;
}

int SparseMatrix::get(int xPos, int yPos) {
    Node* actual = star;

    while (actual != nullptr) {
        if (actual -> x == xPos && actual -> y == yPos) {
            return actual -> value;
        }
        actual = actual -> sgt;
    }
    return 0;
}

void SparseMatrix::remove(int xPos, int yPos) {
    if (star == nullptr) {return;}

    if (star -> x == xPos && star -> y == yPos) {
        Node* temp = star;
        star = star -> sgt;
        delete temp;
        return;
    }

    Node* actual = star;
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
    Node* actual = star;

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