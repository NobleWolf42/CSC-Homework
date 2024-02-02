/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
This program extends the earlier "Online shopping cart (Part 1)" program. (Consider first saving your earlier program).

Step 1: Extend the ItemToPurchase class per the following specifications:

    - Parameterized constructor to assign item name, item description, item price, and item quantity (default values of 0). (1 pt)
    - Public member functions
        - SetDescription() mutator & GetDescription() accessor (2 pts)
        - PrintItemCost() - Outputs the item name followed by the quantity, price, and subtotal
        - PrintItemDescription() - Outputs the item name and description
    - Private data members
        - string itemDescription - Initialized in default constructor to "none"

Ex. of PrintItemCost() output:

    *Bottled Water 10 @ $1 = $10

Ex. of PrintItemDescription() output:

    * Bottled Water: Deer Park, 12 oz.

Step 2: Build three new files:

    - ShoppingCart.h - Class declaration
    - ShoppingCart.cpp - Class definition
    - main.cpp - main() function (Note: main()'s functionality differs from the previous program.)

Build the ShoppingCart class with the following specifications.

    - Default constructor
    - Parameterized constructor which takes the customer name and date as parameters (1 pt)
    - Private data members
        - string customerName - Initialized in default constructor to "none"
        - string currentDate - Initialized in default constructor to "January 1, 2016"
        - vector < ItemToPurchase > cartItems
    - Public member functions
        - GetCustomerName() accessor (1 pt)
        - GetDate() accessor (1 pt)
        - AddItem()
            - Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.
        - RemoveItem()
            - Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
            - If item name cannot be found, output a message: Item not found in cart. Nothing removed.
        - ModifyItem()
            - Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
            - If item cannot be found (by name) in cart, output a message: Item not found in cart. Nothing modified.
        - GetNumItemsInCart() (2 pts)
            - Returns quantity of all items in cart. Has no parameters.
        - GetCostOfCart() (2 pts)
            - Determines and returns the total cost of items in cart. Has no parameters.
        - PrintTotal()
            - Outputs total of objects in cart.
            - If cart is empty, output a message: SHOPPING CART IS EMPTY
        - PrintDescriptions()
            - Outputs each item's description.
            - If cart is empty, output a message: SHOPPING CART IS EMPTY

Ex. of PrintTotal() output:

    *John Doe's Shopping Cart - February 1, 2016
    *Number of Items: 8
    *
    *Nike Romaleos 2 @ $189 = $378
    *Chocolate Chips 5 @ $3 = $15
    *Powerbeats 2 Headphones 1 @ $128 = $128
    *
    *Total: $521

Ex. of PrintDescriptions() output:

    *John Doe's Shopping Cart - February 1, 2016
    *
    *Item Descriptions
    *Nike Romaleos: Volt color, Weightlifting shoes
    *Chocolate Chips: Semi-sweet
    *Powerbeats 2 Headphones: Bluetooth headphones

Step 3: In main(), prompt the user for a customer's name and today's date. Output the name and date. Create an object of type ShoppingCart. (1 pt)

Ex:

    *Enter customer's name:
    *John Doe
    *Enter today's date:
    *February 1, 2016
    *
    *Customer name: John Doe
    *Today's date: February 1, 2016

Step 4: Implement the PrintMenu() function

    - PrintMenu()
        - Prints the following menu of options to manipulate the shopping cart. (1 pt)

Ex:

    *MENU
    *a - Add item to cart
    *d - Remove item from cart
    *c - Change item quantity
    *i - Output items' descriptions
    *o - Output shopping cart
    *q - Quit

    - ExecuteMenu()
        -Takes 2 parameters: a character representing the user's choice and a shopping cart. Performs the menu options described below in step 5, according to the user's choice. (1 pt)

Step 5: Implement the menu options

Step 5a: In main(), call PrintMenu() and prompt for the user's choice of menu options. Each option is represented by a single character.

If an invalid character is entered, continue to prompt for a valid choice. When a valid option is entered, execute the option by calling ExecuteMenu(). Then, print the menu and prompt for a new option. Continue until the user enters 'q'. (1 pt)

Hint: Implement Quit before implementing other options.

Ex:

    *a - Add item to cart
    *d - Remove item from cart
    *c - Change item quantity
    *i - Output items' descriptions
    *o - Output shopping cart
    *q - Quit

    *Choose an option:

Step 5b: Implement "Output shopping cart" menu option in ExecuteMenu(). (3 pts)

Ex:

    *OUTPUT SHOPPING CART
    *John Doe's Shopping Cart - February 1, 2016
    *Number of Items: 8

    *Nike Romaleos 2 @ $189 = $378
    *Chocolate Chips 5 @ $3 = $15
    *Powerbeats 2 Headphones 1 @ $128 = $128

    *Total: $521

Step 5c: Implement "Output items' descriptions" menu option in ExecuteMenu(). (2 pts)

Ex:

    *OUTPUT ITEMS' DESCRIPTIONS
    *John Doe's Shopping Cart - February 1, 2016
    *
    *Item Descriptions
    *Nike Romaleos: Volt color, Weightlifting shoes
    *Chocolate Chips: Semi-sweet
    *Powerbeats 2 Headphones: Bluetooth headphones

Step 5d: Implement "Add item to cart" menu option in ExecuteMenu(). (3 pts)

Ex:

    *ADD ITEM TO CART
    *Enter the item name:
    *Nike Romaleos
    *Enter the item description:
    *Volt color, Weightlifting shoes
    *Enter the item price:
    *189
    *Enter the item quantity:
    *2

Step 5e: Implement "Remove item from cart" menu option in ExecuteMenu(). (4 pts)

Ex:

    *REMOVE ITEM FROM CART
    *Enter name of item to remove:
    *Chocolate Chips

Step 5f: Implement "Change item quantity" menu option in ExecuteMenu(). (5 pts)

Hint: Make new ItemToPurchase object and use ItemToPurchase modifiers before using ModifyItem() method.

Ex:

    *CHANGE ITEM QUANTITY
    *Enter the item name:
    *Nike Romaleos
    *Enter the new quantity:
    *3

*/

#include <iostream>
#include "ShoppingCart.h"

using namespace std;

void ExecuteMenu(char &uIn, ShoppingCart &userCart) {
    ItemToPurchase item;
    string name, description;
    int price, quantity;

    switch (uIn) {
        case 'q':
            break;

        case 'a':
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:";
            getline(cin, name);
            cout << endl << "Enter the item description:";
            cin.ignore();
            getline(cin, description);
            cout << endl << "Enter the item price:";
            cin >> price;
            cout << endl << "Enter the item quantity:";
            cin >> quantity;
            item.SetName(name);
            item.SetDescription(description);
            item.SetPrice(price);
            item.SetQuantity(quantity);
            userCart.AddItem(item);
            break;

        case 'd':
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:";
            getline(cin, name);
            userCart.RemoveItem(name);
            break;

        case 'c':
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:";
            cin >> name;
            cout << endl << "Enter the new quantity:";
            cin >> quantity;
            item.SetName(name);
            item.SetQuantity(quantity);
            userCart.ModifyItem(item);
            break;

        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            userCart.PrintDescriptions();
            break;

        case 'o':
            cout << "OUTPUT SHOPPING CART" << endl;
            userCart.PrintTotal();
            break;
    
        default:
            cout << "Choose an option:" << endl;
            cin >> uIn;
            ExecuteMenu(uIn, userCart);
            break;
    }
}

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
}

int main() {
    
    //Initializing user variables
    string userName, userDate;
    char uIn;
    bool running = true;

    //Getting User Input
    cout << "Enter customer's name:";
    getline(cin, userName);
    cout << endl << "Enter today's date:";
    getline(cin, userDate);

    //Storing cart info
    ShoppingCart userCart(userName, userDate);

    //Outputting user's name and date
    cout << endl << endl << "Customer name: " << userCart.GetCustomerName() << endl;
    cout << "Today's date: " << userCart.GetDate() << endl;

    //Menu stuff
    while (running) {
        PrintMenu();
        cout << "Choose an option:" << endl;
        cin >> uIn;
        ExecuteMenu(uIn, userCart);
        if (uIn == 'q') {
            running = false;
        }
    }
    
    return 0;
}
