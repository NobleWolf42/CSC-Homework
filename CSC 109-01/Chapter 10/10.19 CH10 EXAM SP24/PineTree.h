/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef PINETREE_H
#define PINETREE_H

#include "Tree.h"

class PineTree : public Tree {
    protected:
        double branchRings;

    public:
        PineTree(string species, string location, double branchRings);

        double estimateAge() const override;
};

#endif
