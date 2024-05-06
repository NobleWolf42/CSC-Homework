/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Flower.h"
#include <iostream>

using std::cout;
using std::endl;

void Flower::SetPlantType(bool userIsAnnual) {
    isAnnual = userIsAnnual;
}

bool Flower::GetPlantType() const {
    return isAnnual;
}

void Flower::SetColorOfFlowers(string userColorOfFlowers) {
    colorOfFlowers = userColorOfFlowers;
}

string Flower::GetColorOfFlowers() const {
   return colorOfFlowers;
}

void Flower::PrintInfo() const {
    cout << "   Plant name: " << plantName << endl;
    cout << "   Cost: " << plantCost << endl;
    cout << "   Annual: " << std::boolalpha << isAnnual << endl;
    cout << "   Color of flowers: " << colorOfFlowers << endl;
}
