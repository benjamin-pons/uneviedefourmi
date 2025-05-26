#ifndef ANTS_HPP
#define ANTS_HPP

#include <iostream>
#include "node.hpp"

class Ants {
    public:
        std::shared_ptr<Node> room;
        int name = 0;
        bool arrived = false;
        Ants(int name);
        void changeRoom(std::shared_ptr<Node> ptr);
};

#endif