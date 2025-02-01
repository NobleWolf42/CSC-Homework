/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "PhoneList.h"
#include <iostream>
using std::cout;
using std::endl;

PhoneList::PhoneList() {
    head = nullptr;
    tail = nullptr;
}

PhoneList::~PhoneList() {
    PhoneNode* temp = head;
    while (temp != nullptr) {
        PhoneNode* tempNode = temp;
        temp = temp->getNextNodePtr();
        delete tempNode;
    }
    head = nullptr;
    tail = nullptr;
}

PhoneNode* PhoneList::getHead() {
    return this->head;
}

PhoneNode* PhoneList::getTail() {
    return this->tail;
}

void PhoneList::insertSort(PhoneNode* insertPtr) {
    PhoneNode* temp = head;
    if (head == nullptr || *insertPtr < *head) {
        if (head == nullptr) {
            head = insertPtr;
            tail = insertPtr;
        } else {
            insertPtr->setNextNodePtr(temp);
            head = insertPtr;
        }
    } else if (!(*insertPtr < *tail)) {
        tail->setNextNodePtr(insertPtr);
        tail = insertPtr;
    } else {
        while (temp->getNextNodePtr() != nullptr) {
            if (*insertPtr < *(temp->getNextNodePtr())) {
                insertPtr->setNextNodePtr(temp->getNextNodePtr());
                temp->setNextNodePtr(insertPtr);
                break;
            }

            temp = temp->getNextNodePtr();
        }
    }
}

void PhoneList::printList() {
    PhoneNode* temp = head;
    temp->printPhoneNode();
    while (temp->getNextNodePtr() != nullptr) {
        temp = temp->getNextNodePtr();
        temp->printPhoneNode();
    }
}
