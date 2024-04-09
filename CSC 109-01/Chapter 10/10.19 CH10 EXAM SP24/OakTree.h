/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef OAKTREE_H
#define OAKTREE_H

#include "Tree.h"
 
class OakTree : public Tree {
    protected:
        double diameter;

    public:
        OakTree(string species, string location, double diameter);

        double estimateAge() const override;
};

#endif
