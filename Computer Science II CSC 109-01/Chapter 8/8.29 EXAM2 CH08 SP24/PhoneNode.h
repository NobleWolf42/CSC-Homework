/*
Author: Ben Carpenter
Copyright: 2024
*/

/**
 * @class PhoneNode
 * @brief Represents a node in a linked list for storing phone records.
 *
 * This class encapsulates a phone record, including the phone number,
 * first name, last name, and a pointer to the next node in the linked list.
 * It provides methods for node construction, data access, node comparison,
 * and outputting phone record details.
 
 **Instructions:**

1. **Implement the `PhoneNode` Class**:
   - **Default Constructor (2 points):** Implement a default constructor for the `PhoneNode` class that initializes the `phoneNumber` to an empty string, and the `nextNodePtr` to `nullptr`.
   - **Non-Default Constructor (2 points):** Implement a constructor that initializes the `PhoneNode` with a phone number, first name, last name, and an optional next node pointer (defaulted to `nullptr`). This constructor should properly set the values of the respective private members.
   - **Accessors and Mutators (4 points total):** Implement the `getNextNodePtr` and `setNextNodePtr` methods to get and set the `nextNodePtr`, respectively (2 points each).
   - **Operator Overloading (20 points total):**
     - **Less Than Operator (`<`) (10 points):** Overload the `<` operator to compare `PhoneNode` objects based on their phone numbers only. This will be used to maintain the order in the linked list.
     - **Equality Operator (`==`) (10 points):** Overload the `==` operator to compare `PhoneNode` objects based on their phone numbers, first names, and last names.
   - **Printing Method (2 points):** Implement the `printPhoneNode` method to output the phone number, first name, and last name of a phone record, each separated by a space, followed by a newline character.

 */

#ifndef PHONE_NODE_H
#define PHONE_NODE_H


#include <iostream>
#include <string>
using std::string;

class PhoneNode {
    private:

        string fName, lName, phone;
        PhoneNode* nextNode;

    public:

        PhoneNode();
        PhoneNode(string phoneNumber, string firstName, string lastName, PhoneNode* nextPtr = nullptr);
        PhoneNode* getNextNodePtr();
        void setNextNodePtr(PhoneNode* nextPtr);
        bool operator<(const PhoneNode& other) const;
        bool operator==(const PhoneNode& other) const;
        void printPhoneNode();

};

#endif
