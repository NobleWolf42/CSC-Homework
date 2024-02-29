/*
Author: Ben Carpenter
Copyright: 2024
*/

/**
 * @class PhoneList
 * @brief Manages a linked list of PhoneNode objects representing phone records.
 *
 * This class is designed to handle a collection of phone records in a sorted linked list.
 * It supports adding new phone records in sorted order based on the phone number, printing
 * all records in the list, and managing the memory used by the list to prevent leaks.
 
 2. **Implement the `PhoneList` Class**:
   - **Constructor (2 points):** Implement a constructor that initializes the `head` and `tail` pointers to `nullptr`.
   - **Accessors (4 points total):** Implement the `getHead` and `getTail` methods to return the head and tail of the list, respectively (2 points each).
   - **Sorted Insert Method (20 points):** Implement the `insertSort` method to insert a new `PhoneNode` into the list while maintaining the list's sorted order based on the phone numbers. Utilize the `<` operator overloaded in the `PhoneNode` class.
   - **Destructor (10 points):** Implement the destructor to properly deallocate all dynamically allocated `PhoneNode` objects in the list to prevent memory leaks.
   - **Print Method (4 points):** Implement the `printList` method to iterate through the linked list and print each phone record using the `PhoneNode`'s `printPhoneNode` method.
 */

#ifndef PHONE_LIST_H
#define PHONE_LIST_H

#include "PhoneNode.h"
#include <iostream>
#include <string>
using std::string;

class PhoneList {
    private:

        PhoneNode* head, *tail;

    public:

        PhoneList();
        ~PhoneList();
        PhoneNode* getHead();
        PhoneNode* getTail();
        void insertSort(PhoneNode* insertPtr);
        void printList();

};

#endif
