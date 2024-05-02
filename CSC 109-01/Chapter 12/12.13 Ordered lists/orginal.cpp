/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
An OrderedList is a vector that keeps elements in sorted order.

Complete template <typename TheType> class OrderedList by defining the following functions:

    1. int Size()
        - Return the size of the list
    2. TheType At(int index)
        - Return the element of the list at parameter index.
    3. int Find(TheType value)
        - Return the index of the first element in the list equal to parameter value.
        - Return -1 if parameter value is not found in the list.
    4. bool Remove(TheType value)
        - Search the list for parameter value. Hint: Use Find().
        - If parameter value is found in the list, remove the element found by moving the subsequent elements towards the beginning of the list. Decrement list size and return true.
        - Return false if parameter value is not found in the list.

Hint: Use any vector functions to simplify the implementations.

The template code provides the implementations of the following functions:

    1. void Insert(TheType value)
        - Search the list for an element that is greater than parameter value.
        - If an element is found, increment list size and move the element and all subsequent elements towards the end of the list to make room for parameter value. Copy parameter value at the location that was occupied by the first element greater than parameter value.
        - If no such element is found, increment list size and add parameter value at the end of the list.
    2. void Print()
        - Output the list, separated by a space character.

A main program is provided as a sample test in the develop mode. Unit tests will be used during a submission.

Ex: if the given main() is executed, the output of the program is

    *Size is correct
    *List is in correct order: 3 7 11 
    *Index of 11 is correct -- 2
    *7 was removed correctly

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* ----------- Template class OrderedList declaration ----------- */
template<typename TheType> class OrderedList {
    public:
        int Size();                                 // Number of elements in the list
        TheType At(int index);                          // Return the element at index

        int Find(TheType value);                    // Return index of first occurrence
                                                    // of value or -1 if not found
        void Insert(TheType value);                 // Insert value at its sorted index
        bool Remove(TheType value);                 // Find the first occurrence of value
                                                    // and remove the value; true if success
        void Print();

    private:
        vector<TheType> list;                       // Elements are stored in list
};

/* ----------- OrderedList function implementations ------------ */

template<typename TheType>
int OrderedList<TheType>::Size() {
    /* Type your code here. */
}

template<typename TheType>
TheType OrderedList<TheType>::At(int index) {
    /* Type your code here. */
}

template<typename TheType>
int OrderedList<TheType>::Find(TheType value) {
    /* Type your code here. */
}

template<typename TheType>
void OrderedList<TheType>::Insert(TheType newItem) {
    unsigned int j;                                // Vector size is unsigned int
    unsigned int k;                                // Vector size is unsigned int
    if (list.size() == 0) {
        list.push_back(newItem);
        return;
    }

    j = 0;
    while (j < list.size() && newItem > list.at(j)) {
        ++j;
    }

    list.resize(list.size() + 1);

    // Now all items after index j are >= newItem
    if (j == list.size()) {
        // If newItem is > last element, just add at end of list
        list.push_back(newItem);
    } else {
        // Now move backwards from the end of the list copying elements to
        // the next higher position; stop at j, where newItem will go
        for (k = list.size() - 1; k > j; --k) {
            list.at(k) = list.at(k-1);
        }
        // finally, insert newItem
        list.at(k) = newItem;
    }
}

// NOTE: Uses Find()
template<typename TheType>
bool OrderedList<TheType>::Remove(TheType oldItem) {
    unsigned int j;
    int indx = Find(oldItem);

    /* Type your code here. */
    
}

template<typename TheType>
void OrderedList<TheType>::Print() {
    for (int j = 0; j < Size(); ++j) {
        cout << list.at(j);
        if (j < Size()) {
            cout << " ";                               // No end line after last element
        }
    }
}

/* --------- End OrderedList function implementations ----------- */

// Demonstration of functions
int main() {
    OrderedList<int> intList;

    intList.Insert(11);
    intList.Insert(3);
    intList.Insert(7);

    if (intList.Size() == 3) {
        cout << "Size is correct" << endl;
    }
    else {
        cout << "Size should be 3" << endl;
    }

    if (intList.At(0) == 3 && intList.At(1) == 7 && intList.At(2) == 11) {
        cout << "List is in correct order: ";
    }
    else {
        cout << "List is out of order: ";
    }
    intList.Print();
    cout << endl;

    int indx = intList.Find(11);
    if (indx == 2) {
        cout << "Index of 11 is correct -- " << indx << endl;
    }
    else {
        cout << "Index of 11 is incorrect -- " << indx << endl;
    }

    intList.Remove(7);
    if (intList.At(0) == 3 && intList.At(1) == 11) {
        cout << "7 was removed correctly" << endl;
    }
    else {
        cout << "7 was not removed correctly" << endl;
    }
}
