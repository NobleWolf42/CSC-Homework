/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "MileageTrackerNode.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
MileageTrackerNode::MileageTrackerNode() {
   miles = -1;
   date = "";
   nextNodeRef = nullptr;
}

// Destructor
MileageTrackerNode::~MileageTrackerNode() {
   if (nextNodeRef != nullptr) {
      delete nextNodeRef;
   }
}

// Constructor
MileageTrackerNode::MileageTrackerNode(double milesInit, string dateInit) {
   miles = milesInit;
   date = dateInit;
   nextNodeRef = nullptr;
}

/* Insert node after this node.
Before: this -- next
After:  this -- node -- next
*/

void MileageTrackerNode::InsertAfter(MileageTrackerNode* nodeLoc) {
   MileageTrackerNode* tmpNext;
   tmpNext = nextNodeRef;
   nextNodeRef = nodeLoc;
   nodeLoc->nextNodeRef = tmpNext;
}

// Get location pointed by nextNodeRef
MileageTrackerNode* MileageTrackerNode::GetNext() {
   return nextNodeRef;
}

double MileageTrackerNode::GetMiles() {
    return this->miles;
}

string MileageTrackerNode::GetDate() {
    return this->date;
}

void MileageTrackerNode::PrintNodeData() {
   cout << miles << ", " << date << endl;
}
