/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(std::string name, std::string date) {
    customerName = name;
    currentDate = date;
}

void ShoppingCart::AddItem(ItemToPurchase item1) {
    cartItems.push_back(item1);
}

void ShoppingCart::RemoveItem(std::string name) {
    for (int i = 0; i < GetNumItemsInCart(); ++i) {
        if (cartItems.at(i).GetName() == name) {
           cartItems.erase(cartItems.begin() + i);
        };
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item1) {
    for (int i = 0; i < GetNumItemsInCart(); ++i) {
        if (cartItems.at(i).GetName() == item1.GetName()) {
            cartItems.at(i).SetQuantity(item1.GetQuantity());
        }
    }
}

std::string ShoppingCart::GetCustomerName() const {
    return customerName;
}

std::string ShoppingCart::GetDate() const {
    return currentDate;
}

int ShoppingCart::GetNumItemsInCart() {
    int count = static_cast<int>(cartItems.size());
    return count;
}

int ShoppingCart::GetCostOfCart() {
    int total = 0;

    for (int i = 0; i < GetNumItemsInCart(); ++i) {
        total = total + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }

    return total;
}

void ShoppingCart::PrintTotal() {
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
    std::cout << "Number of Items: " << GetNumItemsInCart() << std::endl << std::endl;
    
    if (GetNumItemsInCart() < 1) {
        std::cout << "SHOPPING CART IS EMPTY" << std::endl;
    } else {
        for (int i = 0; i < GetNumItemsInCart(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    std::cout << std::endl << "Total: $" << GetCostOfCart() << std::endl;
}

void ShoppingCart::PrintDescriptions() {
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
    std::cout << std::endl << "Item Descriptions" << std::endl;

    for (int i = 0; i < GetNumItemsInCart(); ++i) {
        cartItems.at(i).PrintItemDescription();
    }
}
