/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Implement a Sorted Linked List of Phone Records

Objective: The purpose of this exam is to assess your ability to implement and manipulate linked lists, specifically through the creation of a sorted linked list that manages phone records. Your task involves implementing the PhoneNode and PhoneList classes according to the specifications provided below. This exam will evaluate your understanding of object-oriented programming concepts such as class design, constructors, accessors (getters and setters), operator overloading, and memory management in C++.

Instructions:

    1. Implement the PhoneNode Class:

        - Default Constructor (2 points): Implement a default constructor for the PhoneNode class that initializes the phoneNumber to an empty string, and the nextNodePtr to nullptr.
        - Non-Default Constructor (2 points): Implement a constructor that initializes the PhoneNode with a phone number, first name, last name, and an optional next node pointer (defaulted to nullptr). This constructor should properly set the values of the respective private members.
        - Accessors and Mutators (4 points total): Implement the getNextNodePtr and setNextNodePtr methods to get and set the nextNodePtr, respectively (2 points each).
        - Operator Overloading (20 points total):
        - Less Than Operator (<) (10 points): Overload the < operator to compare PhoneNode objects based on their phone numbers only. This will be used to maintain the order in the linked list.
        - Equality Operator (==) (10 points): Overload the == operator to compare PhoneNode objects based on their phone numbers, first names, and last names.
        - Printing Method (2 points): Implement the printPhoneNode method to output the phone number, first name, and last name of a phone record, each separated by a space, followed by a newline character.

    2. Implement the PhoneList Class:

        - Constructor (2 points): Implement a constructor that initializes the head and tail pointers to nullptr.
        - Accessors (4 points total): Implement the getHead and getTail methods to return the head and tail of the list, respectively (2 points each).
        - Sorted Insert Method (20 points): Implement the insertSort method to insert a new PhoneNode into the list while maintaining the list's sorted order based on the phone numbers. Utilize the < operator overloaded in the PhoneNode class.
        - Destructor (10 points): Implement the destructor to properly deallocate all dynamically allocated PhoneNode objects in the list to prevent memory leaks.
        - Print Method (4 points): Implement the printList method to iterate through the linked list and print each phone record using the PhoneNode's printPhoneNode method.

    - Additional Requirement:

        - Compilation Requirement (Mandatory): Your submission must compile without errors. No partial credit will be given for non-compiling code. Ensure that your code is free of syntax and logical errors before submission.

    - Submission Guidelines:

        - Ensure your code is well-commented to explain the logic where necessary.
        - Follow proper coding conventions and standards for clarity and maintenance.
        - Test your implementation thoroughly to ensure correctness.
        - Submit your source code files (.cpp and .h) as per the submission instructions provided by your instructor.

    - Evaluation Criteria:

        - Correct implementation of class constructors, methods, and destructors.
        - Proper use of dynamic memory management.
        - Efficient and correct implementation of the sorted insert algorithm.
        - Correctness in overloading operators as specified.
        - Code readability, commenting, and adherence to provided specifications.
        - Ability to compile without errors.

Note: Pay close attention to the handling of edge cases, such as inserting into an empty list or deleting the last element in the list. Your implementation should not cause any memory leaks or segmentation faults.

Please note that the grades provided with your submission are for your reference only and should not be considered final. The instructor will thoroughly review each exam and may adjust grades based on a comprehensive evaluation of your work. The final grade assigned by the instructor will take into account all aspects of your performance on the exam.
*/

#include <iostream>
#include <sstream>
#include "PhoneNode.h"
#include "PhoneList.h"

using namespace std;


int main() {

    PhoneList list1;
    string phoneno;
    string firstName;
    string lastName;
    for (int i=0; i<10; i++) {
        cin >> phoneno;
        cin >> firstName;
        cin >> lastName;

        PhoneNode* node = new PhoneNode(phoneno, firstName, lastName);
        list1.insertSort(node);

    }
    list1.printList();

    return 0;
}
