#include <vector>
#include <memory>
#ifndef NODE_HPP
#define NODE_HPP



class Node {
    public:
        int id;
        int capacity = 1;
        int population = 0;
        std::vector<std::shared_ptr<Node>> neighbors;
        
        Node(int roomId);
        Node(int roomId, int capacity);
        int isFull();
        void addAnt();
        void removeAnt();
        void addNeighbor(std::shared_ptr<Node> n);
        void showNeighbor();
};

#endif
