#include "SparseMatrix.h"

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

void SparseMatrix::printStoredValues() {}

int SparseMatrix::density() {}

SparseMatrix *SparseMatrix::multiply(SparseMatrix *second) {}

SparseMatrix::~SparseMatrix() {}