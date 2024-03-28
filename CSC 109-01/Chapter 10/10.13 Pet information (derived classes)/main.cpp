/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
The base class Pet has protected data members petName, and petAge. The derived class Cat extends the Pet class and includes a private data member for catBreed. Complete main() to:

    - create a generic pet and print information using PrintInfo().
    - create a Cat pet, use PrintInfo() to print information, and add a statement to print the cat's breed using the GetBreed() function.

Ex. If the input is:

    *Dobby
    *2
    *Kreacher
    *3
    *Scottish Fold

the output is:

    *Pet Information: 
    *   Name: Dobby
    *   Age: 2
    *Pet Information: 
    *   Name: Kreacher
    *   Age: 3
    *   Breed: Scottish Fold

*/

#include <iostream>
#include<string>
#include "Cat.h"

using namespace std;

int main() {
    
    string petName, catName, catBreed;
    int petAge, catAge;
    
    Pet myPet;
    Cat myCat;
    
    getline(cin, petName);
    cin >> petAge;
    cin.ignore();
    getline(cin, catName);
    cin >> catAge;
    cin.ignore();
    getline(cin, catBreed);
    
    // TODO: Create generic pet (using petName, petAge) and then call PrintInfo       
    myPet.SetName(petName);
    myPet.SetAge(petAge);
    myPet.PrintInfo();
    
    // TODO: Create cat pet (using catName, catAge, catBreed) and then call PrintInfo
    myCat.SetName(catName);
    myCat.SetAge(catAge);
    myCat.SetBreed(catBreed);
    myCat.PrintInfo();
    
    // TODO: Use GetBreed(), to output the breed of the cat
    cout << "   Breed: " << myCat.GetBreed() << endl;

}
