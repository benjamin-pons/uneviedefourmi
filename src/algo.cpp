#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include "ants.hpp"
#include "node.hpp"

void printStepBar (int step) {
    std::cout << "\n*****E" << step << "*****" << std::endl;
}

void algorithm(std::vector<std::shared_ptr<Node>> anthill, std::vector<Ants> ants) {
    int step = 1;
    
    while (!anthill[7]->isFull()) {
        std::string steps = "";
        for (Ants &ant : ants) {
            if (ant.room->isEnding) {
                continue; // Ant has already arrived, skip to the next
            }

            else {
                // If ending room is a neighbor, go directly to it
                for (std::shared_ptr<Node> neighbor : anthill[ant.room->id]->neighbors) {
                    if (neighbor->isEnding) {
                        int old_room = ant.room->id;
                        ant.changeRoom(neighbor);
                        steps += "\nf" + std::to_string(ant.name) + " - S" + std::to_string(old_room) + " - S" +  std::to_string(ant.room->id);
                        break;
                    }
                }

                for (std::shared_ptr<Node> neighbor : anthill[ant.room->id]->neighbors) { 
                    if (!neighbor->isFull() && (ant.room->id < neighbor->id)) {
                        int old_room = ant.room->id;
                        ant.changeRoom(neighbor);
                        steps += "\nf" + std::to_string(ant.name) + " - S" + std::to_string(old_room) + " - S" +  std::to_string(ant.room->id);
                        break;
                    }
                }
            }
        }

        // Displays steps in terminal
        printStepBar(step++);
        std::cout << steps << std::endl;

        Sleep(1000);   
        }
}
