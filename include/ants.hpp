#ifndef ANTS_HPP
#define ANTS_HPP

#include <iostream>
#include "node.hpp"

class Ants {
    public:
        Node *room;
        int name = 1;
        Ants(int name);
        void changeRoom(Node *ptr);
};

#endif