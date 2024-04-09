/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "PineTree.h"

PineTree::PineTree(string species, string location, double branchRings) : Tree(species, location){
    this->branchRings = branchRings;
}

double PineTree::estimateAge() const {
    return branchRings;
}
