/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CH11SHOPPINGCLASS_ITEM_H
#define CH11SHOPPINGCLASS_ITEM_H
#include <string>
#include <ostream>


/**
 * The Item class represents an item with a name and a price.
 * It provides methods to access these properties and to output the item details to a stream.
 */
class Item {
public:
    /**
     * Constructs an Item with a specified name and price.
     *
     * @param name The name of the item.
     * @param price The price of the item.
     */
    Item(const std::string& name, double price);

    /**
     * Gets the name of the item.
     *
     * @return The name of the item.
     */
    std::string getName() const;

    /**
     * Gets the price of the item.
     *
     * @return The price of the item.
     */
    double getPrice() const;

    /**
     * Overloads the output stream operator to enable easy printing of Item objects.
     *
     * @param os The output stream.
     * @param item The item to be outputted.
     * @return A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Item &item);

private:
    std::string name; // The name of the item.
    double price;     // The price of the item.
};

#endif //CH11SHOPPINGCLASS_ITEM_H
