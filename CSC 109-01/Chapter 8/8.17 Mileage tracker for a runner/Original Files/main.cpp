/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Given the MileageTrackerNode class containing the number of miles a runner runs on a certain date, complete main() to perform the following tasks:

    1. Read the number of nodes in the linked list from user input, followed by the number of miles and date of each node.
    2. Use the MileageTrackerNode's InsertAfter() function to insert each node according to the input sequence (i.e. insert each node after the last node).
    3. Print the entire linked list using the MileageTrackerNode's PrintNodeData() function. DO NOT print the head node that does not contain user-input values. Hint: PrintNodeData() only outputs values in one node; therefore, iterate through the linked list.

Ex. If the input is:

    *3
    *2.2
    *7/2/18
    *3.2
    *7/7/18
    *4.5
    *7/16/18

the output is:

    *2.2, 7/2/18
    *3.2, 7/7/18
    *4.5, 7/16/18

*/

#include "MileageTrackerNode.h"
#include <string>
#include <iostream>

using namespace std;

int main () {
    // References for MileageTrackerNode objects
    MileageTrackerNode* headNode;
    MileageTrackerNode* currNode;
    MileageTrackerNode* lastNode;
    
    double miles;
    string date;
    int i;
    
    // Front of nodes list
    headNode = new MileageTrackerNode();
    // End of nodes list
    lastNode = headNode;
    
    // TODO: Read in the number of nodes
    
    
    // TODO: For the input number of nodes, read the number of miles and date
    //       from user input. Insert each node into the end of the linked list (after the last node)
    
    
    // TODO: Print the entire linked list with PrintNodeData() function calls     
    
    
    // MileageTrackerNode Destructor deletes all following nodes
    delete headNode;
    
    return 0;
}   