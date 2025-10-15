#include "SparseMatrix.h"
using namespace std;
#include <iostream>

SparseMatrix::SparseMatrix() {}

void SparseMatrix::add(int value, int xPos, int yPos) {}

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

void SparseMatrix::remove(int xPos, int yPos) {}

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