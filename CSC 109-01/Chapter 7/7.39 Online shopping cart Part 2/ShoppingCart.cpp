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
    std::cout << std::endl << std::endl;
}

void ShoppingCart::RemoveItem(std::string name) {
    for (size_t i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == name) {
           cartItems.erase(cartItems.begin() + i);
        } else if (cartItems.size() == i + 1) {
            std::cout << std::endl << "Item not found in cart. Nothing removed.";
        }
    }
    std::cout << std::endl << std::endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item1) {
    for (size_t i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == item1.GetName()) {
            cartItems.at(i).SetQuantity(item1.GetQuantity());
        } else if (cartItems.size() == i + 1) {
            std::cout << std::endl << "Item not found in cart. Nothing modified.";
        }
    }
    std::cout << std::endl << std::endl;
}

std::string ShoppingCart::GetCustomerName() const {
    return customerName;
}

std::string ShoppingCart::GetDate() const {
    return currentDate;
}

int ShoppingCart::GetNumItemsInCart() {
    int total = 0;

    for (size_t i = 0; i < cartItems.size(); ++i) {
        total = total + cartItems.at(i).GetQuantity();
    }
    
    return total;
}

int ShoppingCart::GetCostOfCart() {
    int total = 0;

    for (size_t i = 0; i < cartItems.size(); ++i) {
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
        for (size_t i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }

    std::cout << std::endl << "Total: $" << GetCostOfCart() << std::endl << std::endl;
}

void ShoppingCart::PrintDescriptions() {
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
    std::cout << std::endl << "Item Descriptions" << std::endl;

    for (size_t i = 0; i < cartItems.size(); ++i) {
        cartItems.at(i).PrintItemDescription();
    }

    std::cout << std::endl;
}
