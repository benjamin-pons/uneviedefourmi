#include <iostream>
#include "ants.hpp"
#include "node.hpp"
using namespace std;

void printStepBar (int step) {
    cout << "\n*****E" << step << "*****" << endl;
}

int main() {

    Node room0 = Node(0, 2);
    Node room1 = Node(1);
    Node room2 = Node(2);
    Node room3 = Node(3, 2);

    Ants ant1 = Ants(1);
    Ants ant2 = Ants(2);

    ant1.changeRoom(&room0);
    ant2.changeRoom(&room0);

    cout << "\nPopulation salle 0 : " << room0.population << endl;
    cout << "Population salle 1 : " << room1.population << endl;
    cout << "Population salle 2 : " << room2.population << endl;
    cout << "Population salle 3 : " << room3.population << endl;

    return 0;
}