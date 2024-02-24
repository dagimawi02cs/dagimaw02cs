#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node* next;
    void* data;

   Node() : next(nullptr) {}
};

#endif // NODE_H
