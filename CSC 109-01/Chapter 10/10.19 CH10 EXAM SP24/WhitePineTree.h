/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef WHITEPINETREE_H
#define WHITEPINETREE_H

#include "PineTree.h"
 
class WhitePineTree : public PineTree {
    public:
        WhitePineTree(string species, string location, double branchRings);

        double estimateAge() const override;
};

#endif
