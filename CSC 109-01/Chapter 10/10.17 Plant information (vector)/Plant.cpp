/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Plant.h"
#include <iostream>

using std::cout;
using std::endl;

Plant::~Plant() {};

void Plant::SetPlantName(string userPlantName) {
    plantName = userPlantName;
}

string Plant::GetPlantName() const {
    return plantName;
}

void Plant::SetPlantCost(int userPlantCost) {
    plantCost = userPlantCost;
}

int Plant::GetPlantCost() const {
    return plantCost;
}

void Plant::PrintInfo() const {
    cout << "   Plant name: " << plantName << endl;
    cout << "   Cost: " << plantCost << endl;
}
