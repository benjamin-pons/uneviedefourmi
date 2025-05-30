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

vector<shared_ptr<Node>> pathfind(shared_ptr<Node> start, shared_ptr<Node> end) {
    unordered_map<int, shared_ptr<Node>> parent;
    queue<shared_ptr<Node>> queue_path;
    unordered_set<int> visited;

    queue_path.push(start);
    visited.insert(start->id);
    parent[start->id] = nullptr;

    while (!queue_path.empty()) {
        shared_ptr<Node> current = queue_path.front();
        queue_path.pop();

        if (current == end) {
            // Return path
            vector<shared_ptr<Node>> path;
            while (current != nullptr) {
                path.push_back(current);
                current = parent[current->id];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (shared_ptr<Node> neighbor : current->neighbors) {
            if (visited.find(neighbor->id) == visited.end()) {
                visited.insert(neighbor->id);
                parent[neighbor->id] = current;
                queue_path.push(neighbor);
            }
        }
    }
    return {}; // If no path is found
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

void algorithm_ant(vector<shared_ptr<Node>> anthill, vector<Ants> ants, const int ENDING_ROOM) {

    for (Ants &ant : ants) {
        ant.path = pathfind(ant.room, anthill[ENDING_ROOM]);
        ant.pathIndex = 0;
    }

    int step = 1;

    while (!anthill[ENDING_ROOM]->isFull()) {
        string steps = "";
        for (Ants &ant : ants) {
            if (ant.room->isEnding) {
                continue; // Ant has already arrived, skip to the next
            }

            if (ant.pathIndex + 1 < ant.path.size()) {
                shared_ptr<Node> nextRoom = ant.path[ant.pathIndex + 1];

                if (!nextRoom->isFull()) {
                    int old_room = ant.room->id;
                    ant.changeRoom(nextRoom);
                    ant.pathIndex++;

                    steps += "\nf" + to_string(ant.name) + " - S" + to_string(old_room) + " - S" +  to_string(nextRoom->id);
                }
            }
        }
        printStepBar(step++);
        cout << steps << endl;
        Sleep(1000);
    }
}