/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "OakTree.h"

OakTree::OakTree(string species, string location, double diameter) : Tree(species, location) {
    this->diameter = diameter;
}

double OakTree::estimateAge() const {
    return diameter * 1.2;
}
