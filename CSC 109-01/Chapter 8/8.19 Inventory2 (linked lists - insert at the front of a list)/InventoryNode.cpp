/*
Author: Ben Carpenter
Copyright: 2024
*/


#include "InventoryNode.h"

using std::cout;
using std::endl;

InventoryNode::InventoryNode() {
    item = "none";
    numberOfItems = -1;
    nextNodeRef = nullptr;
}

InventoryNode::InventoryNode(string itemInit, int numberOfItemsInit) {
    item = itemInit;
    numberOfItems = numberOfItemsInit;
    nextNodeRef = nullptr;
}

void InventoryNode::InsertAtFront(InventoryNode *a, InventoryNode *b) {
    InventoryNode* tempLoc = a->GetNext();
    a->nextNodeRef = b;
    b->nextNodeRef = tempLoc;
}

InventoryNode* InventoryNode::GetNext() {
    return this->nextNodeRef;
}

string InventoryNode::GetItem() {
    return this->item;
}

int InventoryNode::GetNumberOfItems() {
    return this->numberOfItems;
}

void InventoryNode::PrintNodeData() {
    cout << numberOfItems << " " << item << endl;
}
