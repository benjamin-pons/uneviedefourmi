#include "node.hpp"

Node::Node(int roomId) {
    this->capacity = 1;
    this->id = roomId;
}

Node::Node(int roomId, int capacity) {
    this->capacity = capacity;
    this->id = roomId;
}

int Node::isFull() {
    if (population >= capacity) {
        return 1;
    }
    else {
        return 0;
    }
}

void Node::addAnt() {
    this->population++;
}

void Node::removeAnt() {
    this->population--;
}