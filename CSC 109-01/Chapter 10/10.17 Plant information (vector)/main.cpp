/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Given a base Plant class and a derived Flower class, complete main() to create a vector called myGarden. The vector should be able to store objects that belong to the Plant class or the Flower class. Create a function called PrintVector(), that uses the PrintInfo() functions defined in the respective classes and prints each element in myGarden. The program should read plants or flowers from input (ending with -1), add each Plant or Flower to the myGarden vector, and output each element in myGarden using the PrintInfo() function.

Ex. If the input is:

    *plant Spirea 10
    *flower Hydrangea 30 false lilac
    *flower Rose 6 false white
    *plant Mint 4
    *-1

the output is:

    *Plant 1 Information:
    *   Plant name: Spirea
    *   Cost: 10
    *
    *Plant 2 Information:
    *   Plant name: Hydrangea
    *   Cost: 30
    *   Annual: false
    *   Color of flowers: lilac
    *
    *Plant 3 Information:
    *   Plant name: Rose
    *   Cost: 6
    *   Annual: false
    *   Color of flowers: white
    *
    *Plant 4 Information:
    *   Plant name: Mint
    *   Cost: 4

*/

#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintVector(vector<Plant*> toPrint) {
    for (size_t i = 0; i < toPrint.size(); i++) {
        cout << "Plant " << i + 1 << " Information:" << endl;
        toPrint.at(i)->PrintInfo();
        cout << endl;
    }
}

int main() {
    vector<Plant*> myGarden;
    string plantName, flowerName, colorOfFlowers;
    int plantCost, flowerCost;
    bool isAnnual;

    string input;

    cin >> input;

    while(input != "-1") {
        if (input == "plant") {
            Plant* tempPlant = new Plant();

            cin >> plantName >> plantCost;

            tempPlant->SetPlantName(plantName);
            tempPlant->SetPlantCost(plantCost);

            myGarden.push_back(tempPlant);

        } else if (input == "flower") {
            Flower* tempFlower = new Flower();

            cin >> flowerName >> flowerCost >> boolalpha >> isAnnual >> colorOfFlowers;

            tempFlower->SetPlantName(flowerName);
            tempFlower->SetPlantCost(flowerCost);
            tempFlower->SetPlantType(isAnnual);
            tempFlower->SetColorOfFlowers(colorOfFlowers);

            myGarden.push_back(tempFlower);
        }

        cin >> input;
    }

    PrintVector(myGarden);

    for (size_t i = 0; i < myGarden.size(); ++i) {
        delete myGarden.at(i);
    }
   
    return 0;
}
