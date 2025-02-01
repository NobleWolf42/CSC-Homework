/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef LINKEDLISTLIBRARYH
#define LINKEDLISTLIBRARYH

#include "BookNode.h"

class LinkedListLibrary {
    public:
        //Linked list nodes
        BookNode* headNode;
        BookNode* lastNode;

        LinkedListLibrary();

        ~LinkedListLibrary();

        int InsertSorted(BookNode* newNode, int counter);

        void PrintLibrary() const;
};

#endif
