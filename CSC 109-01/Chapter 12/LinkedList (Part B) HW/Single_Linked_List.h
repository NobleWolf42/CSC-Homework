/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include "Node.h"
#include <stdexcept>

/*<programming_project chapter="4" number="1">*/

#include <stdexcept>

/** Class to implement a single linked list */
template <typename Item_Type>
class Single_Linked_List {
public:

    /** Construct an empty Single_Linked_List */
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {
    }

    /** destructor */
    ~Single_Linked_List() {
        if (head != nullptr) {
            delete head;
        }
    }
    
    /** Insert an item at the front of the list
        @param item The item to be inserted
     */
    void push_front(const Item_Type& item) {
        Node<Item_Type>* temp = new Node<Item_Type>(item, head);
        if (head == nullptr) {
            tail = temp;
        }
        head = temp;
        num_items += 1;
    }

    /** Insert an item at the end of the list
        @param item The item to be inserted
     */
    void push_back(const Item_Type& item) {
        Node<Item_Type>* temp = new Node<Item_Type>(item, nullptr);
        if (head == nullptr) {
            head = temp;
        } else {
            tail->SetNext(temp);
        }
        tail = temp;
        num_items += 1;
    }

    /** Remove the front item of the list 
     * If it is empty list, throw out_of_range with a message 
     * "pop_front on empty list"
     */
    void pop_front() {
        if (num_items == 0) {
            throw(std::out_of_range("pop_front on empty list"));
        }
        
        Node<Item_Type>* temp = head;
        if (num_items == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->GetNext();
        }
        temp->SetNext(nullptr);
        delete temp;
        num_items -= 1;
    }

    /** Remove the last item of the list 
     * If it is empty list, throw out_of_range with a message 
     * "pop_back on empty list"
     */
    void pop_back() {
        if (num_items == 0) {
            throw(std::out_of_range("pop_back on empty list"));
        }

        Node<Item_Type>* temp = head;
        Node<Item_Type>* temp2 = tail;
        if (num_items > 1) {
            for (size_t i = 0; i < num_items - 2; i++) {
                temp = temp->GetNext();
            }
            tail = temp;
            temp->SetNext(nullptr);
        } else {
            head = nullptr;
            tail = nullptr;
        }
        delete temp2;
        num_items -= 1;
    }

    /** Return a reference to the front item of the list
     * If it is empty list, throw out_of_range with a message 
     * "Attempt to take front of empty list")
        @return A reference to the front item of the list
     */
    Item_Type& front() {
        if (num_items == 0) {
            throw(std::out_of_range("Attempt to take front of empty list"));
        }
        return head->GetData();
    }

    /** Return a const reference to the front item of the list
     * If it is empty list, throw out_of_range with a message 
     * "Attempt to take front of empty list")

        @return A const reference to the front item of the list
     */
    const Item_Type& front() const {
        if (num_items == 0) {
            throw(std::out_of_range("Attempt to take front of empty list"));
        }
        return head->GetData();
    }

    /** Return a reference to the back item of the list
     * If it is empty list, throw out_of_range with a message 
     * "Attempt to take back of empty list")
        @return A reference to the back item of the list
     */
    Item_Type& back() {
        if (num_items == 0) {
            throw(std::out_of_range("Attempt to take back of empty list"));
        }
        return tail->GetData();
    }

    /** Return a const reference to the back item of the list
        @return A const reference to the back item of the list
     */
    const Item_Type& back() const {
        if (num_items == 0) {
            throw(std::out_of_range("Attempt to take back of empty list"));
        }
        return tail->GetData();
    }

    /** Determine if the list is empty
     * If it is empty list, throw out_of_range with a message 
     * "Attempt to take back of empty list")
        @return true if the list is empty
     */
    bool empty() const {
        return num_items == 0;
    }

    /** Return the number of items in the list
        @return The number of items in the list
     */
    size_t size() const {
        return num_items;
    }

    /** Insert item at position index (starting at 0).  Insert
        at the end of index is beyond the end of the list.
        @param index The poisition to insert the item
        @param item The item to be inserted
     */
    void insert(size_t index, const Item_Type& item) {
        Node<Item_Type>* temp = head;
        Node<Item_Type>* temp2 = nullptr;
        if (index != 0) {
            for (size_t i = 0; i < index - 1; i++) {
                temp = temp->GetNext();
            }
            temp2 = temp->GetNext();
        }
        if (index == 0) {
            head = new Node<Item_Type>(item, temp2);
        } else if (temp2 == nullptr) {
            temp->SetNext(new Node<Item_Type>(item, temp2));
            tail = temp->GetNext();
        } else {
            temp->SetNext(new Node<Item_Type>(item, temp2));
        }
        num_items += 1;
        
    }

    /** function to insert a new_node in a sorted list. 
     Insert the new_node in sorted order.
     * @parm new_node Node to be inserted into the sorted linked list.
     */
    
    void sortedInsert(Item_Type& item) {
        Node<Item_Type>* temp = head;
        Node<Item_Type>* temp2 = nullptr;
        bool done = false;
        if (num_items != 0 && this->front() < item) {
            for (size_t i = 0; i < num_items - 1; i++) {
                if (temp->GetNext()->GetData() >= item) {
                    temp2 = temp->GetNext();
                    done = true;
                    break;
                }
                temp = temp->GetNext();
            }
        }
        if (temp2 == nullptr && done) {
            tail = temp->GetNext();
        } else if (num_items == 1 && this->front() < item) {
            tail = new Node<Item_Type>(item, temp2);
            head->SetNext(tail);
        } else if (head == nullptr) {
            head = new Node<Item_Type>(item, temp2);
            tail = head;
        } else if (head == tail) {
            if (temp2 == nullptr && done) {
                temp->SetNext(new Node<Item_Type>(item, temp2));
                tail = temp->GetNext();
            } else {
                head = new Node<Item_Type>(item, temp);
            }
        } else if (this->front() >= item) {
            head = new Node<Item_Type>(item, temp);
        } else if (this->back() < item) {
            temp->SetNext(new Node<Item_Type>(item, temp2));
            tail = temp->GetNext();
        } else {
            temp->SetNext(new Node<Item_Type>(item, temp2));
        }
        num_items += 1;
    }

    /** Return a reference to the item at position index
     *  If index > size, throw a message 
     * "Attempt to get past size in Single_Linked_List"
        @param index The index of the item
        @return A reference to the item at index
     */
    Item_Type& get(size_t index) {
        if (index >= num_items) {
            throw(std::out_of_range("Attempt to get past size in Single_Linked_List"));
        }
        Node<Item_Type>* temp = head;
        for (size_t i = 0; i < index; i++) {
            temp = temp->GetNext();
        }

        return temp->GetData();
    }

    /** Return a const reference to the item at position index
        @param index The index of the item
        @return A const reference to the item at index
     */
    const Item_Type& get(size_t index) const {
        if (index > num_items) {
            throw(std::out_of_range("Attempt to get past size in Single_Linked_List"));
        }
        Node<Item_Type>* temp = head->GetNext();
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->GetNext();
        }

        return temp->GetData();
    }


    /** Remove the item at position index.
     * If index > size, throw a message 
     * "Attempt to get past size in Single_Linked_List"
        @return true if the removal is sucessful; false if index is
        beyond the end of the list
     */
    bool remove(size_t index) {
        if (index > num_items) {
            throw(std::out_of_range("Attempt to get past size in Single_Linked_List"));
            return false;
        }

        Node<Item_Type>* temp = head->GetNext();
        Node<Item_Type>* temp2 = temp->GetNext();
        for (size_t i = 0; i < index - 2; i++) {
            temp = temp->GetNext();
            temp2 = temp2->GetNext();
        }
        Node<Item_Type>* temp3 = temp2->GetNext();
        temp->SetNext(temp3);
        temp2->SetNext(nullptr);
        delete temp2;
        return true;
    }

    /** Return the position of the first occurence of item.
     * If item is not found, throw an "item not found" exception
     * Note: this is a char* exception
        @return The position of the first occurence of the item. Return
        the size of the list if it is not found
     */
    size_t find(const Item_Type& item) {
        Node<Item_Type>* temp = head->GetNext();
        for (size_t i = 0; i < num_items - 1; i++) {
            if (temp->GetData() == item) {
                return i;
            }
            temp = temp->GetNext();
        }
        throw(std::runtime_error("item not found"));
        return num_items;
    }

private:

    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

};
/** 
 * implement the functions that specified in this header file to the section 
 * in below or put them in a separate file.  If you decide to put the code in
 * a separate file, don't use .cpp extension.
 */
// #include "Single_Linked_List.tpp"

#endif /* SINGLE_LINKED_LIST_H */
