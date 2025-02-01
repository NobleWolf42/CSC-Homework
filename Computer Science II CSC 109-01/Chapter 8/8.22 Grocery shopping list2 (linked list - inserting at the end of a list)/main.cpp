/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Given main(), define an InsertAtEnd() member function in the ItemNode class that adds an element to the end of a linked list. DO NOT print the dummy head node.

Ex. if the input is:

    *4
    *Kale 
    *Lettuce 
    *Carrots 
    *Peanuts 
    
where 4 is the number of items to be inserted; Kale, Lettuce, Carrots, Peanuts are the names of the items to be added at the end of the list.

The output is:

    *Kale 
    *Lettuce 
    *Carrots 
    *Peanuts 

*/

#include "ItemNode.h"

int main() {
	ItemNode *headNode;  // Create intNode objects                                                   
	ItemNode *currNode;
	ItemNode *lastNode;

	string item;
	int i;
	int input;

	// Front of nodes list                                                                         
	headNode = new ItemNode();
	lastNode = headNode;

	cin >> input;

	for (i = 0; i < input; i++) {
		cin >> item;
		currNode = new ItemNode(item);
		lastNode->InsertAtEnd(headNode, currNode);
		lastNode = currNode;
	}

	// Print linked list                                                                           

	currNode = headNode->GetNext();
	while (currNode != NULL) {
		currNode->PrintNodeData();
		currNode = currNode->GetNext();
	}
}
