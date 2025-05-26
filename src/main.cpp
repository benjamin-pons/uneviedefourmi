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

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i; i < 4; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }

    // Creating Ants in a vector
    vector<Ants> ants;
    for (int i; i < 2; i++) {
        ants.push_back(Ants(i));
    }

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }

    // Initializing step count
    int step = 1;
    
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

    anthill[0]->showNeighbor();
    cout << endl;
    anthill[1]->showNeighbor();
    cout << endl;
    anthill[2]->showNeighbor();
    cout << endl;
    anthill[3]->showNeighbor();
    cout << endl;

    

    while (!anthill[3]->isFull()) {
        string steps = "";
        for (Ants &ant : ants) {
            if (!anthill[1]->isFull() && ant.room->id == 0) {
                ant.changeRoom(anthill[1]);
                steps += "\nf" + to_string(ant.name) + " - Sv - S" +  to_string(ant.room->id); 
                continue;
            }

            if (!anthill[2]->isFull() && ant.room->id == 0) {
                ant.changeRoom(anthill[2]);
                steps += "\nf" + to_string(ant.name) + " - Sv - S" +  to_string(ant.room->id);
                continue;
            }

            if (ant.room->id == 1 || ant.room->id == 2) {
                int old_room = ant.room->id;
                ant.changeRoom(anthill[3]);
                steps += "\nf" + to_string(ant.name) + " - S" + to_string(old_room) + " - S" +  to_string(ant.room->id);
                continue;
            }
        }

        printStepBar(step++);
        cout << steps << endl;

        Sleep(1000);
    }
}

int main() {

    anthill1();

    return 0;
}