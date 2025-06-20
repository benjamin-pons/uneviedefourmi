#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <map>
#include "ants.hpp"
#include "node.hpp"
#include "algo.hpp"
using namespace std;

vector<vector<int>> a0 = {{0, 1, 1, 0},
                          {1, 0, 0, 1},
                          {1, 0, 0, 1},
                          {0, 1, 1, 0}};

vector<vector<int>> a1 = {{0, 1, 0, 0},
                          {1, 0, 1, 0},
                          {0, 1, 0, 1},
                          {0, 0, 1, 0}};

vector<vector<int>> a2 = {{0, 1, 0, 1},
                          {1, 0, 1, 0},
                          {0,1 , 0, 1},
                          {1, 0, 1, 0}};

vector<vector<int>> a3 = {{0, 1, 0, 0, 0, 0},
                          {1, 0, 1, 0, 1, 0},
                          {0, 1, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 1, 0, 0, 0, 1},
                          {0, 0, 0, 0, 1 ,0}};

vector<vector<int>> a4 = {{0, 1, 0, 0, 0, 0, 0, 0},
                          {1, 0, 1, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 1, 1, 0},
                          {0, 0, 0, 0, 1, 0, 0, 1},
                          {0, 0, 0, 0, 1, 0, 0, 1},
                          {0, 0, 0, 0, 0, 1, 1, 0}};

map<int, int> a4_map = {
    {1 , 2},
    {4 , 2}
};

vector<vector<int>> a5 = {
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }
    };

map<int, int> a5_map = {
    {1 , 8},
    {2 , 4},
    {3 , 2},
    {4 , 4},
    {5 , 2},
    {6 , 4},
    {7 , 2},
    {8 , 5},
    {13 , 4},
    {14 , 2}
};


void generate_anthill(int ants_amount, int ending_room, std::vector<std::vector<int>>& matrix, map <int, int> m = {}){
    const int ANTS_AMOUNT = ants_amount;
    const int SIZE = matrix.size();
    const int ENDING_ROOM = ending_room;
    
    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < SIZE; i++) {
        anthill.push_back(std::make_shared<Node>(i));;
    }
    
    anthill[ENDING_ROOM]->isEnding = true;

    // Creating Ants in a vector
    vector<Ants> ants;
    for (int i = 1; i < ANTS_AMOUNT+1; i++) {
        ants.push_back(Ants(i));
    }

    // Changing last node capacity to ants amount
    anthill[ENDING_ROOM]->capacity = ANTS_AMOUNT;

    // Changing other rooms capacity
    for (auto& j : m) {
        anthill[j.first]->capacity = j.second;
        cout << j.first << " : " << j.second << endl;
    }

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }

    for (int n = 0; n < SIZE; n++) {
        for(int m = 0; m < SIZE; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }

    algorithm_ant(anthill, ants, ENDING_ROOM);
}


int main() {
    int rep = -1;
    cout << "0. fourmiliere 0 \n1. fourmiliere 1\n2. fourmiliere 2\n3. fourmiliere 3\n4. fourmiliere 4\n5. fourmiliere 5" << endl;
    cout << "Quel fourmiliere utiliser ? : ";
    cin >> rep;
    if (rep == 0){
        generate_anthill(2, 3, a0);
    }
    else if (rep == 1){
        generate_anthill(5, 3, a1);
    }
    else if (rep == 2){
        generate_anthill(5, 3, a2);
    }
    else if (rep == 3){
        generate_anthill(5, 5, a3);
    }
    else if (rep == 4){
        generate_anthill(10, 7, a4, a4_map);
    }
    else if (rep == 5){
        generate_anthill(50, 15, a5, a5_map);
    }
    else {
        cout << "\nReponse invalide\n" << endl;
        return main();
    }
}