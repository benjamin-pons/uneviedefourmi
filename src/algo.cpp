#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <bits/stdc++.h>
#include "ants.hpp"
#include "node.hpp"
using namespace std;

void printStepBar (int step) {
    cout << "\n*****E" << step << "*****" << endl;
}

int pathfind(vector<shared_ptr<Node>> anthill, shared_ptr<Node> start, int end) {

    queue<shared_ptr<Node>> current_layer;
    queue<shared_ptr<Node>> next_layer;

    int distance = 0;

    unordered_set<shared_ptr<Node>> visited;

    current_layer.push(start);
    visited.insert(start);

    while (!current_layer.empty()) {
        int current_layer_size = current_layer.size();
        for (int i = 0; i < current_layer_size; i++) {
            shared_ptr<Node> node = current_layer.front();
            current_layer.pop();
            if (node->id == end) {
                return distance;
            }
            
            for (shared_ptr<Node> neighbor : node->neighbors) {

                cout << node->id << endl;

                if (visited.count(neighbor) == 0) {
                    next_layer.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        current_layer = move(next_layer);
        distance++;
    }
    return -1;
}

void algorithm(vector<shared_ptr<Node>> anthill, vector<Ants> ants) {
    int step = 1;
    
    while (!anthill[3]->isFull()) {
        string steps = "";
        for (Ants &ant : ants) {
            if (ant.room->isEnding) {
                continue; // Ant has already arrived, skip to the next
            }

            else {
                // If ending room is a neighbor, go directly to it
                for (shared_ptr<Node> neighbor : anthill[ant.room->id]->neighbors) {
                    if (neighbor->isEnding) {
                        int old_room = ant.room->id;
                        ant.changeRoom(neighbor);
                        steps += "\nf" + to_string(ant.name) + " - S" + to_string(old_room) + " - S" +  to_string(ant.room->id);
                        break;
                    }
                }

                for (shared_ptr<Node> neighbor : anthill[ant.room->id]->neighbors) { 
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

void algorithm2(vector<shared_ptr<Node>> anthill, vector<Ants> ants) {
    cout << pathfind(anthill, anthill[0], 4) << endl;
}