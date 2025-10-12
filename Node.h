#pragma once

class Node {
    private:
        int x, y, value;
        Node* sgt;

    public:
        Node(int x, int y, int value);

        int getX();
        int getY();
        int getValue();
        Node* getSgt();

        void setValue(int v);
        void setSgt(Node* n);
};
