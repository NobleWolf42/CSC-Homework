/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CH11SHOPPINGCLASS_SHOPPINGBAGS_H
#define CH11SHOPPINGCLASS_SHOPPINGBAGS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Item.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;


/**
 * The ShoppingBags class is designed to manage combinations of items in a shopping bag using recursion.
 * It allows the creation of various combinations of items based on a maximum limit for the number of items
 * that can be placed in the bag. It also provides functionality to convert these combinations into a string format.
 */
class ShoppingBags {
public:

    /**
     * Constructs a ShoppingBags instance with a specified maximum number of items.
     *
     * @param max_item The maximum number of items that the shopping bag can hold.
     */
    explicit ShoppingBags(size_t max_item);

    /**
     * Generates all possible combinations of items that can be placed in the shopping bag.
     * It uses recursion to explore different combinations.
     *
     * @param currBag The current combination of items in the bag.
     * @param remainingItems The items remaining to be added to the bag.
     * @return A vector of vectors, where each inner vector represents a possible combination of items.
     */
    vector<vector<Item>> ShoppingBagCombinations(vector<Item> currBag, vector<Item> remainingItems);

    /**
     * Converts the list of item combinations into a string format. Optionally starts from a specified index.
     *
     * @param bags The vector of item combinations.
     * @param index The starting index for processing the combinations (default is 0).
     * @return A string representation of the item combinations.
     */
    string to_string(const vector<vector<Item>>& bags, size_t index = 0) const;

private:
    
    size_t max_items_in_bag; // The maximum number of items allowed in the bag.

    /**
     * A helper method for generating combinations of items in the bag. This method loops through
     * items and recursively builds the combinations.
     *
     * @param currBag The current combination of items.
     * @param remainingItems The remaining items to be considered for addition.
     * @param bags The collection of all generated combinations.
     * @param tempBags Temporary storage for current combination processing.
     * @param index The current index in the items list.
     */
    void BagsLoop(const vector<Item> &currBag, const vector<Item> &remainingItems, vector<vector<Item>> &bags,
                  vector<vector<Item>> &tempBags, size_t index);

    /**
     * Converts a single combination of items into a string format and calculates the total price of items in the subset.
     *
     * @param out The output stream to which the string representation is written.
     * @param subset The subset of items to be converted into string format.
     * @param index The current index in the subset.
     * @param totalPrice A reference to an integer that stores the total price of items in the subset.
     * @return The total number of items in the subset.
     */
    int bagString(std::ostringstream &out, const vector<Item> &subset, size_t index, int &totalPrice) const;

};

#endif //CH11SHOPPINGCLASS_SHOPPINGBAGS_H
