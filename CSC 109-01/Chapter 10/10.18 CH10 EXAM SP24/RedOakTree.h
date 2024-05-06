/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef REDOAKTREE_H
#define REDOAKTREE_H

#include "OakTree.h"
 
class RedOakTree : public OakTree {
    public:
        RedOakTree(string species, string location, double diameter);

        double estimateAge() const override;
};

#endif
