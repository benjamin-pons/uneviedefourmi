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
    const int ENDING_ROOM = 3;

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
    anthill[ENDING_ROOM]->capacity = ANTS_AMOUNT;

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

void anthill3(){
        const int ANTS_AMOUNT = 6;
        const int ENDING_ROOM = 5;

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < 6; i++) {
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

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }


    int matrix[6][6] = {{0, 1, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1},
                        {0, 0, 0, 0, 1 ,0}};

    for (int n = 0; n < 6; n++) {
        for(int m = 0; m < 6; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}

void anthill4(){
        const int ANTS_AMOUNT = 10;
        const int ENDING_ROOM = 7;
        const int SIZE = 8;

    // Creating Nodes in a vector
    std::vector<std::shared_ptr<Node>> anthill;
    for (int i = 0; i < SIZE ; i++) {
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
    anthill[1]->capacity = 2;
    anthill[4]->capacity = 2;

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }


    int matrix[SIZE][SIZE] = {{0, 1, 0, 0, 0, 0, 0, 0},
                        {1, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1 , 0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1, 0},
                        {0, 0, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 0, 0, 1, 1, 0}};

    for (int n = 0; n < SIZE; n++) {
        for(int m = 0; m < SIZE ; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}

void anthill5(){
    const int ANTS_AMOUNT = 50;
    const int ENDING_ROOM = 15;
    const int SIZE = 16;

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
    anthill[1]->capacity = 8;
    anthill[2]->capacity = 4;
    anthill[3]->capacity = 2;
    anthill[4]->capacity = 4;
    anthill[5]->capacity = 2;
    anthill[6]->capacity = 4;
    anthill[7]->capacity = 2;
    anthill[8]->capacity = 5;
    anthill[13]->capacity = 4;
    anthill[14]->capacity = 2;

    // Putting ants in starting room
    for (Ants& ant : ants) {
        ant.changeRoom(anthill[0]);
    }

    int matrix[SIZE][SIZE] = {
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

    for (int n = 0; n < SIZE; n++) {
        for(int m = 0; m < SIZE; m++) {
            if (matrix[n][m] == 1) {
                anthill[n]->addNeighbor(anthill[m]);
            }
        }
    }
    algorithm(anthill, ants);
}

int main() {
    int rep = -1;
    cout<<"0. fourmiliere 0 \n1. fourmiliere 1\n2. fourmiliere 2\n3. fourmiliere 3\n4. fourmiliere 4\n5. fourmiliere 5" << endl;
    cin >> rep;
    if (rep == 0){
        anthill0();
    }
    else if (rep == 1){
        anthill1();
    }
    else if (rep == 2){
        anthill2();
    }
    else if (rep == 3){
        anthill3();
    }
    else if (rep == 4){
        anthill4();
    }
    else if (rep == 5){
        anthill5();
    }
}