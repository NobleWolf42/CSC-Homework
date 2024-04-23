/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "ShoppingBags.h"

ShoppingBags::ShoppingBags(size_t max_item) {
    max_items_in_bag = max_item;
}

    /**
     * Generates all possible combinations of items that can be placed in the shopping bag.
     * It uses recursion to explore different combinations.
     *
     * @param currBag The current combination of items in the bag.
     * @param remainingItems The items remaining to be added to the bag.
     * @return A vector of vectors, where each inner vector represents a possible combination of items.
     */
vector<vector<Item>> ShoppingBags::ShoppingBagCombinations(vector<Item> currBag, vector<Item> remainingItems) {
    vector<vector<Item>> bags;
    vector<vector<Item>> tempBags;

    BagsLoop(currBag, remainingItems, bags, tempBags, 0);
    return bags;    
}

    /**
     * Converts the list of item combinations into a string format. Optionally starts from a specified index.
     *
     * @param bags The vector of item combinations.
     * @param index The starting index for processing the combinations (default is 0).
     * @return A string representation of the item combinations.
     */
string ShoppingBags::to_string(const vector<vector<Item>>& bags, size_t index) const {
    if (index >= bags.size()) {
        return "";
    }

    std::ostringstream out;
    int totalPrice = 0;
    int numItems = bagString(out, bags[index], 0, totalPrice);
    out << " = Total Price: $" << totalPrice << std::endl;

    return out.str() + to_string(bags, index + 1);
}

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
void ShoppingBags::BagsLoop(const vector<Item> &currBag, const vector<Item> &remainingItems, vector<vector<Item>> &bags, vector<vector<Item>> &tempBags, size_t index) {

    vector<Item> temp;
    vector<Item> temp2;

    temp = currBag;
    temp2 = remainingItems;

    if (currBag.size() == max_items_in_bag) {
        bags.push_back(currBag);
        return;
    } else if (index == remainingItems.size()) {
        return;
    }

    // Include the current item
    temp2.erase(temp2.begin()+index);
    temp.push_back(remainingItems[index]);
    //BagsLoop(temp, remainingItems, bags, tempBags, index + 1);
    BagsLoop(temp, temp2, bags, tempBags, index);
    temp.pop_back();

    // Exclude the current item
    //BagsLoop(temp, remainingItems, bags, tempBags, index + 1);
    BagsLoop(temp, temp2, bags, tempBags, index);
}

    /**
     * Converts a single combination of items into a string format and calculates the total price of items in the subset.
     *
     * @param out The output stream to which the string representation is written.
     * @param subset The subset of items to be converted into string format.
     * @param index The current index in the subset.
     * @param totalPrice A reference to an integer that stores the total price of items in the subset.
     * @return The total number of items in the subset.
     */
int ShoppingBags::bagString(std::ostringstream &out, const vector<Item> &subset, size_t index, int &totalPrice) const {
    if (index == subset.size()) {
        return 0;
    }

    out << subset[index] << " ";
    totalPrice += subset[index].getPrice();

    return 1 + bagString(out, subset, index + 1, totalPrice);
}
