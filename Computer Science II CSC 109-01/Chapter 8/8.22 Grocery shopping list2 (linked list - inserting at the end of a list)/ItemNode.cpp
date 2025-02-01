/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "ItemNode.h"
using std::cout;
using std::endl;

ItemNode::ItemNode() {
    item = "none";
    nextNodeRef = nullptr;
}

ItemNode::ItemNode(string itemInit) {
    item = itemInit;
    nextNodeRef = nullptr;
}

void ItemNode::InsertAfter(ItemNode* nodeLoc) {
    ItemNode* tempNext = nullptr;

    tempNext = this->nextNodeRef;
    this->nextNodeRef = nodeLoc;
    nodeLoc->nextNodeRef = tempNext;
}

void ItemNode::InsertAtEnd(ItemNode *a, ItemNode *b) {
    this->nextNodeRef = b;
}

ItemNode* ItemNode::GetNext() {
    return this->nextNodeRef;
}

string ItemNode::GetItem() const {
    return this->item;
}

void ItemNode::PrintNodeData() {
    cout << item << endl;
}
