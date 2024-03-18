/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "LinkedListLibrary.h"
#include <iostream>

using std::cout;
using std::endl;

LinkedListLibrary::LinkedListLibrary() {
    // Front of nodes list
    headNode = nullptr;
    lastNode = nullptr;
}

LinkedListLibrary::~LinkedListLibrary() {
    while (headNode != nullptr) {
        BookNode* tempNode = headNode->GetNext();
        delete headNode;
        headNode = tempNode;
    }
}

int LinkedListLibrary::InsertSorted(BookNode* newNode, int counter) {
    BookNode* currNode, nextNode;

    // Special case for head node
    if (headNode == nullptr || headNode->GetBookISBN() >= newNode->GetBookISBN()) {
        if (headNode == nullptr) {
            lastNode = newNode;
        }
        newNode->SetNext(headNode);
        headNode = newNode;
    } else {
        // Locate the node before insertion point
        currNode = headNode;

        while (currNode->GetNext() && currNode->GetNext()->GetBookISBN() < newNode->GetBookISBN()) {
            currNode = currNode->GetNext();
        }

        if (currNode == lastNode) {
            lastNode = newNode;
        }
        currNode->insertAfter(newNode);
    }

    ++counter;
    return counter;
}

void LinkedListLibrary::PrintLibrary() const {
    BookNode* currNode;

    currNode = headNode;
    while (currNode != nullptr) {
        currNode->PrintBookInfo();
        cout << endl;
        currNode = currNode->GetNext();
    }
}
