/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "RedOakTree.h"

RedOakTree::RedOakTree(string species, string location, double diameter) : OakTree(species, location, diameter) {
    
}

double RedOakTree::estimateAge() const {
    return diameter * 1.5;
}
