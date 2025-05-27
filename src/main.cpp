#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include "ants.hpp"
#include "node.hpp"
#include "algo.hpp"
using namespace std;

void anthill0() {
    int ANTS_AMOUNT = 2;


    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < 4; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }

    anthill[3]->isEnding = true;

    // Creating Ants in a vector
    vector<Ants> ants;
    for (int i = 1; i < ANTS_AMOUNT+1; i++) {
        ants.push_back(Ants(i));
    }

    // Changing last node capacity to ants amount
    anthill[3]->capacity = ANTS_AMOUNT;

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }
    
    // Links nodes together
    int matrix[4][4] = {{0, 1, 1, 0},
                        {1, 0, 0, 1},
                        {1, 0, 0, 1},
                        {0, 1, 1, 0}};

    for (int n = 0; n < 4; n++) {
        for(int m = 0; m < 4; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}

void anthill1() {
    const int ANTS_AMOUNT = 5;

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < 4; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }

    anthill[3]->isEnding = true;

    // Creating Ants in a vector
    vector<Ants> ants;
    for (int i = 1; i < ANTS_AMOUNT+1; i++) {
        ants.push_back(Ants(i));
    }

    // Changing last node capacity to ants amount
    anthill[3]->capacity = ANTS_AMOUNT;

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }
    


    int matrix[4][4] = {{0, 1, 0, 0},
                        {1, 0, 1, 0},
                        {0,1 , 0, 1},
                        {0, 0, 1, 0}};

    for (int n = 0; n < 4; n++) {
        for(int m = 0; m < 4; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}

void anthill2(){
    const int ANTS_AMOUNT = 5;
    const int ENDING_ROOM = 3;

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < 4; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }

    anthill[ENDING_ROOM]->isEnding = true;

    // Creating Ants in a vector
    vector<Ants> ants;
    for (int i = 1; i < ANTS_AMOUNT+1; i++) {
        ants.push_back(Ants(i));
    }

    for (int i = 0; i < 3; ++i) {
        anthill[i]->capacity = 1;
    }

    // Changing last node capacity to ants amount
    anthill[ENDING_ROOM]->capacity = ANTS_AMOUNT;

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }


    int matrix[4][4] = {{0, 1, 0, 1},
                        {1, 0, 1, 0},
                        {0,1 , 0, 1},
                        {1, 0, 1, 0}};

    for (int n = 0; n < 4; n++) {
        for(int m = 0; m < 4; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}
int main() {
    
    anthill2();

    return 0;
}