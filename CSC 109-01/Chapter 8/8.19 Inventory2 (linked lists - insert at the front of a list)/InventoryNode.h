/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CSC109CH0818INVENTORY_INVENTORYNODE_H
#define CSC109CH0818INVENTORY_INVENTORYNODE_H


#include <iostream>
#include <string>
using std::string;

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
    InventoryNode* GetNext();
    string GetItem();
    int GetNumberOfItems();
    void PrintNodeData();

};


#endif //CSC109CH0818INVENTORY_INVENTORYNODE_H
