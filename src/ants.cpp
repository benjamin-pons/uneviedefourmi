#include "ants.hpp"
#include "node.hpp"
#include <iostream>

Ants::Ants(int name) {
    this->name = name;
}

void Ants::changeRoom(Node *ptr) {
    room->removeAnt();
    this->room = ptr;
    room->addAnt();
    // std::cout << "Ajout de 1 a room : " << room->id << std::endl;
}