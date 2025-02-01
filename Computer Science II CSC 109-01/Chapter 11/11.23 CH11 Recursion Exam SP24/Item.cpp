/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Item.h"

/**
 * Constructs an Item with a specified name and price.
 */
Item::Item(const std::string& name, double price) : name(name), price(price) {

}

/**
 * Gets the name of the item.
 */
std::string Item::getName() const {
    return name;
}

/**
 * Gets the price of the item.
 */
double Item::getPrice() const {
    return price;
}

/**
 * Overloads the output stream operator to enable easy printing of Item objects.
 */
std::ostream &operator<<(std::ostream &os, const Item &item) {
    os << "name: " << item.name << " price: " << item.price;
    return os;
}

