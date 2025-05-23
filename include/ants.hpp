#ifndef ANTS_HPP
#define ANTS_HPP

#include <iostream>
#include "node.hpp"

class Ants {
    public:
        Node *room = nullptr;
        int name = 0;
        bool arrived = false;
        Ants(int name);
        void changeRoom(Node *ptr);
};

#endif