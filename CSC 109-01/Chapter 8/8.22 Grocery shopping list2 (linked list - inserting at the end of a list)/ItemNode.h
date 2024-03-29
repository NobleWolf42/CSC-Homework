/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CSC109CH0822GROCERY_ITEMNODE_H
#define CSC109CH0822GROCERY_ITEMNODE_H


#include <iostream>
#include <string>
using std::string;

class ItemNode {
private:
    string item;
    ItemNode* nextNodeRef;

public:
    // Constructor
    ItemNode();

    // Constructor
    explicit ItemNode(string itemInit);

    // Insert node after this node.
    void InsertAfter(ItemNode* nodeLoc);

    // TODO: Define insertAtEnd() function that inserts a node
    //       to the end of the linked list
    void InsertAtEnd(ItemNode *a, ItemNode *b);

    // Get location pointed by nextNodeRef
    ItemNode* GetNext();

    string GetItem() const;

    void PrintNodeData();
};

#endif //CSC109CH0822GROCERY_ITEMNODE_H
