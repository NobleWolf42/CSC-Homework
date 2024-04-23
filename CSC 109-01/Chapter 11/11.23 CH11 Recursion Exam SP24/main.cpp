/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Exam Name: Recursive Shopping Bag Combination

Instructions:

General Guidelines:
    - Carefully read and follow these instructions for the implementation of the ShoppingBag and Item classes.
    - You are expected to implement the classes in C++.

Implement the Item class according to the following specifications:
     - The class should have private data members to store the name and price of an item.
     - Provide a constructor to initialize these data members.
     - Overload the stream (<<) operator to enable the conversion of an Item object to a string in the format: "name: ItemName price: ItemPrice".
    
Implement the ShoppingBag class according to the following specifications:
     - The class should have private data members to store a maximum number of items in a bag.
     - Create a constructor that set maximum number of items per bag.
     - Implement a recursive ShoppingBagCombinations function within the class to generate all possible combinations of three (3) or more items from the provided vector without using loops. Ensure that the function returns a vector of item combinations.
     - Implement a to_string member function that returns a string representation of the ShoppingBagCombination. The string representation should include all the items in the combination, with each item on a separate line, formatted as specified in the Item class.
     - Emphasize that no loops are allowed for any part of the implementation. You may use private helper functions within your class to assist with recursive operations.

Additional Requirements:
    - Ensure that your implementation strictly follows the rules of recursion. The use of loops is not allowed for any part of the exam.
    - You may use private helper functions within your classes to assist with recursive operations.
    - Your code should be well-structured and maintainable, with proper commenting and indentation.
    - You must return a vector<vector<Item>> from your ShoppingBagCombination method. The vector<vector<Item>> can then be printed using the to_string function. Do not make any changes to the main.cpp.
    - If your ShoppingBagCombination function only prints out combinations of items like the code in the book, you will receive zero for the exam even if your code passes all the tests in Zybooks.
    - Your logic must exclude ineligible items on-the-fly, as you generate combinations, rather than creating a complete list of combinations first and filtering it afterward.

Testing:
    - After implementing both classes, create test cases to verify that your code works correctly.
    - Test the overloaded operators and ensure that they produce the expected results.
    - Test your ShoppingBagCombination class with different sets of items to confirm that it generates all possible combinations of three (3) or more items correctly.

Submission:
    - Submit your C++ code, including both the Item and ShoppingBagCombination classes, through the Zybooks and Web-CAT submission process. Each submission accounts for 50% of your grade.
    - Make sure your code is well-documented and easy to understand.
    - Back up your work regularly to prevent loss of work. If you lost your work, you will not allowed to retake the exam.

Note: Your code will be tested using additional test cases to assess correctness, adherence to recursive principles, and proper use of operator overloading. Make sure to follow the instructions closely and practice incremental development to achieve a successful implementation.

Good luck with your exam!
*/

#include <iostream>
#include <vector>
#include "ShoppingBags.cpp"
#include "Item.cpp"

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