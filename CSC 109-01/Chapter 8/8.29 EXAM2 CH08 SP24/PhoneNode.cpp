/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "PhoneNode.h"
#include <iostream>
using std::cout;
using std::endl;


PhoneNode::PhoneNode() {
    fName = "";
    lName = "";
    phone = "";
    nextNode = nullptr;
}

PhoneNode::PhoneNode(string phoneNumber, string firstName, string lastName, PhoneNode* nextPtr) {
    fName = firstName;
    lName = lastName;
    phone = phoneNumber;
    nextNode = nextPtr;
}

PhoneNode* PhoneNode::getNextNodePtr() {
    return this->nextNode;
}

void PhoneNode::setNextNodePtr(PhoneNode* nextPtr) {
    this->nextNode = nextPtr;
}

bool PhoneNode::operator<(const PhoneNode &other) const {
    return this->phone < other.phone;
}

bool PhoneNode::operator==(const PhoneNode &other) const {
    return(this->phone == other.phone && this->fName == other.fName && this->lName == other.lName);
}

void PhoneNode::printPhoneNode() {
    cout << phone << " " << fName << " " << lName << endl;
}
