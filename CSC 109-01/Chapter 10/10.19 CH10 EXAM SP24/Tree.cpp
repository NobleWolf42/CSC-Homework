/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Tree.h"

Tree::Tree(string species, string location) {
    this->species = species;
    this->location = location;
}

void Tree::dislayInfo() {
    cout << "Species: " << species << ", Estimated Age: " << estimateAge() << ", Location: " << location << endl;

}
