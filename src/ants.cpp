#include "ants.hpp"
#include "node.hpp"
#include <iostream>

Ants::Ants(int name) {
    this->name = name;
}

void Ants::changeRoom(Node *ptr) {
    if (room != nullptr) {
        room->removeAnt();
    }
    this->room = ptr;
    room->addAnt();

    return;
}