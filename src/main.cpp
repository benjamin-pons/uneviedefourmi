#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include "ants.hpp"
#include "node.hpp"
using namespace std;

void printStepBar (int step) {
    cout << "\n*****E" << step << "*****" << endl;
}



void anthill1() {
    int ANTS_AMOUNT = 2;

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < 4; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }

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

    // Initializing step count
    int step = 1;
    
    while (!anthill[3]->isFull()) {
        string steps = "";
        for (Ants &ant : ants) {
            if (ant.room->id == 3) {
                continue; // Ant has already arrived, skip to the next
            }
            else {
                for (std::shared_ptr<Node> neighbor : anthill[ant.room->id]->neighbors) {        
                    if (!neighbor->isFull() && (ant.room->id < neighbor->id)) {
                        int old_room = ant.room->id;
                        ant.changeRoom(neighbor);
                        steps += "\nf" + to_string(ant.name) + " - S" + to_string(old_room) + " - S" +  to_string(ant.room->id);
                        break;
                    }
                }
            }
        }

        // Displays steps in terminal
        printStepBar(step++);
        cout << steps << endl;

        Sleep(1000);
    }
}

int main() {
    
    anthill1();

    return 0;
}