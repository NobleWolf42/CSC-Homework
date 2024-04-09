/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Tree {
    protected:
        string species, location;

    public:

        Tree(string species, string location);

        virtual ~Tree() {}

        virtual double estimateAge() const = 0;

        void dislayInfo();
};

#endif
