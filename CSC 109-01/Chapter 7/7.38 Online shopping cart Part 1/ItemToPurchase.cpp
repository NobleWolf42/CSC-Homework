/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

void ItemToPurchase::SetName(std::string itemName) {
    this->itemName = itemName;
}
        
void ItemToPurchase::SetPrice(int itemPrice) {
    this->itemPrice = itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
    this->itemQuantity = itemQuantity;
}

std::string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
