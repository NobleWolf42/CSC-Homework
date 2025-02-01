//
// Created by hloi on 2/8/2021.
//

#ifndef CSC109CH0818INVENTORY_INVENTORYNODE_H
#define CSC109CH0818INVENTORY_INVENTORYNODE_H


#include <iostream>
#include <string>
using namespace std;

class InventoryNode {
private:
    string item;
    int numberOfItems;
    InventoryNode *nextNodeRef;

public:
    InventoryNode();
    InventoryNode(string itemInit, int numberOfItemsInit);
    InventoryNode(string itemInit, int numberOfItemsInit, InventoryNode* nextLoc);
    void InsertAtFront(InventoryNode *a, InventoryNode *b);
    InventoryNode *GetNext();
    void PrintNodeData();

};


#endif //CSC109CH0818INVENTORY_INVENTORYNODE_H
