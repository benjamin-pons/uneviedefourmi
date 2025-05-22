#ifndef NODE_HPP
#define NODE_HPP

class Node {
    public:
        int id;
        int capacity = 1;
        int population = 0;
        Node(int roomId);
        Node(int roomId, int capacity);
        int isFull();
        void addAnt();
        void removeAnt();        
};

#endif
