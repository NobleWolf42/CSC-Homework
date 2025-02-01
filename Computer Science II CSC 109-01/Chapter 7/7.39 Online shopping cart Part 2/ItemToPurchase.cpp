/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(std::string name, std::string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::SetName(std::string itemName) {
    this->itemName = itemName;
}

void ItemToPurchase::SetDescription(std::string itemDescription) {
    this->itemDescription = itemDescription;
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

std::string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

void ItemToPurchase::PrintItemCost() {
    std::cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << std::endl;
}

void ItemToPurchase::PrintItemDescription() {
    std::cout << itemName << ": " << itemDescription << std::endl;;
}
