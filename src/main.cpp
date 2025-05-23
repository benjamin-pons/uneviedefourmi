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
    
    Node room0 = Node(0, 2);
    Node room1 = Node(1);
    Node room2 = Node(2);
    Node room3 = Node(3, 2);

    Ants ant1 = Ants(1);
    Ants ant2 = Ants(2);
    // Ants ant3 = Ants(3);

    ant1.changeRoom(&room0);
    ant2.changeRoom(&room0);
    // ant3.changeRoom(&room0);

    int step = 1;
    
    vector<Ants> ants = {ant1, ant2};

    while (!room3.isFull()) {
        string steps = "";
        for (Ants &ant : ants) {
            if (!room1.isFull() && ant.room->id == 0) {
                ant.changeRoom(&room1);
                steps += "\nf" + to_string(ant.name) + " - Sv - S" +  to_string(ant.room->id); 
                continue;
            }

            if (!room2.isFull() && ant.room->id == 0) {
                ant.changeRoom(&room2);
                steps += "\nf" + to_string(ant.name) + " - Sv - S" +  to_string(ant.room->id);
                continue;
            }

            if (ant.room->id == 1 || ant.room->id == 2) {
                int old_room = ant.room->id;
                ant.changeRoom(&room3);
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