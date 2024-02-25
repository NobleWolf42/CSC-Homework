/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
A linked list is built in this lab. Make sure to keep track of the head node.

Step 1: Define class ContactNode per the following specifications:
    - Private data members
        - string contactName
        - string contactPhoneNumber
        - ContactNode* nextNodePtr
    - Constructor with parameters for name followed by phone number (1 pt)
        - Public member functions
        - GetName() - Accessor (1 pt)
        - GetPhoneNumber() - Accessor (1 pt)
        - InsertAfter(ContactNode* newNode) - Insert newNode after the current node (2 pts)
        - GetNext() - Accessor (1 pt)
        - PrintContactNode() - Output contactName and contactPhoneNumber of the current node according to the format shown in the example below.
Ex: If the name is Roxanne Hughes and the phone number is 443-555-2864, PrintContactNode() outputs:

    *Name: Roxanne Hughes
    *Phone number: 443-555-2864

Step 2: Define main() to read the name and phone number for three contacts and output each contact. Create three ContactNodes and use the nodes to build a linked list. (2 pts)

Ex: If the input is:

    *Roxanne Hughes
    *443-555-2864
    *Juan Alberto Jr.
    *410-555-9385
    *Rachel Phillips
    *310-555-6610

the output is:

    *Person 1: Roxanne Hughes, 443-555-2864
    *Person 2: Juan Alberto Jr., 410-555-9385
    *Person 3: Rachel Phillips, 310-555-6610

Step 3: Output the linked list. Use a loop to call each node's PrintContactNode(). (2 pts)

Ex:

    *CONTACT LIST
    *Name: Roxanne Hughes
    *Phone number: 443-555-2864
    *
    *Name: Juan Alberto Jr.
    *Phone number: 410-555-9385
    *
    *Name: Rachel Phillips
    *Phone number: 310-555-6610
*/

#include <iostream>
using namespace std;

class ContactNode {
public:
   /* Declare member functions here */
   
private:
   /* Declare data members here */
   
};

/* Define member functions here */

int main() {
   /* Type your code here. */
   
   return 0;
}
