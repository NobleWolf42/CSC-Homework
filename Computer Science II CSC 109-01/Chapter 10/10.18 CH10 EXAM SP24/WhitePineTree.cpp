/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "WhitePineTree.h"

WhitePineTree::WhitePineTree(string species, string location, double branchRings) : PineTree(species, location, branchRings) {

}

double WhitePineTree::estimateAge() const {
    return branchRings * 1.2;
}
