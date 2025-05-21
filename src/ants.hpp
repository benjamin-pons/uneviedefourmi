#ifndef ANTS_HPP
#define ANTS_HPP

#include <iostream>

class Ants {
    public:
        int room = 0;
        int name = 1;
        Ants(int name);
        void changeRoom(int room);
};

#endif