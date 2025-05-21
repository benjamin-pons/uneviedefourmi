#include <iostream>
#include "ants.hpp"
using namespace std;

void printStepBar (int step) {
    cout << "\n*****E" << step << "*****" << endl;
}


int main() {
    Ants obj = Ants(1);
    obj.changeRoom(2);



    int step = 1;
    printStepBar(step);
    cout << "f" << obj.name <<" - S1 - S" << obj.room << endl;
    cout << "f2 - S2 - S3" << endl;
    step ++;
    printStepBar(step);
    cout << "f" << obj.name <<" - S2 - S3" << endl;
    cout << "f2 - S3 - Sd" << endl;
    return 0;
}