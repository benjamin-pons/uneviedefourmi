#include "ants.hpp"
#include "node.hpp"
#include <iostream>

Ants::Ants(int name) {
    this->name = name;
}

void Ants::changeRoom(std::shared_ptr<Node> ptr) {
    if (room != nullptr) {
        room->removeAnt();
    }
    room = ptr;

    if (room != nullptr) {
        room->addAnt();
    }
}