#include "Node.h"

Node::Node(int x, int y, int value) {
    this -> x = x;
    this -> y = y;
    this -> value = value;
    this -> sgt = nullptr;
}

int Node::getX() {return x;}

int Node::getY() {return y;}

int Node::getValue() {return value;}

Node *Node::getSgt() {return sgt;}

void Node::setValue(int v) {value = v;}

void Node::setSgt(Node *n) {sgt = n;}