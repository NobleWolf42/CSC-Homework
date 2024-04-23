/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
#include <vector>
#include "ShoppingBags.h"
using namespace std;

int main() {
    // Sample items for testing.
    cout << "Enter number of items: ";
    int n;
    cin >> n;
    cout << n << endl;
    cout << "Enter number of items in a bag: ";
    int i;
    cin >> i;
    cout << i << endl;
    std::vector<Item> possibleItems = {
            Item("Item1", 10.0),
            Item("Item2", 15.0),
            Item("Item3", 5.0),
            Item("Item4", 8.0),
            Item("Item5", 12.0)
    };

//    vector<Item> p = possibleItems;
//    p.erase(p.begin()+n-1);
    possibleItems.erase(possibleItems.begin()+n, possibleItems.end());
    // Create a ShoppingBagCombinations instance and find combinations.
    ShoppingBags bagCombinations(i);

    // vector<Item> possibleItems; // Possible shopping items
    vector<Item> shoppingBag;   // Current shopping bag

    vector<vector<Item>> allBags;
    allBags = bagCombinations.ShoppingBagCombinations(shoppingBag, possibleItems);

    cout << "Number of bags: " << allBags.size() << endl;
    cout << bagCombinations.to_string(allBags) << endl;


    return 0;
}