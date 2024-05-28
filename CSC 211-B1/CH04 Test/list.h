/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
#include <cstddef>
#include <iostream>

/** Class list implements a subset of the standard
    list class using a double-linked list.
    @author Koffman and Wolfgang
 */
namespace KW {

    template<typename Item_Type>
    class list {
    private:
        // Insert definition of nested class DNode here.
#include "DNode.h"
    public:
        // Insert definition of nested class iterator here.
#include "list_iterator.h"
        // Give list access to internal values in iterator.
        friend class iterator;
        // Insert definition of nested class const_iterator here.
#include "list_const_iterator.h"
        // Give list access to internal values in const_iterator.
        friend class const_iterator;

        // Data fields
        /** A reference to the head of the list */
        DNode* head;
        /** A reference to the tail of the list */
        DNode* tail;
        /** The size of the list */
        int num_items;
        // Functions
    public:

        /** Construct an empty list. */
        list() {
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        }

        /** Construct a copy of a list. */
        list(const list<Item_Type>& other) {
            list<Item_Type>::const_iterator iter = other.begin();
            list<Item_Type>::const_iterator endIter = other.end();
            head = nullptr;
            tail = nullptr;
            num_items = 0;
            while (iter != endIter) {
                push_back(*iter);
                ++iter;
            }
        }

        /** Construct a list from a sequence */
        template <typename iterator>
        list(iterator begin, iterator end) {
            head = nullptr;
            tail = nullptr;
            num_items = 0;
            for (iterator iter = begin; iter != end; ++iter) {
                push_back(*iter);
            }
        }

        /** list destructor. */
        ~list() {
            while (!empty()) {
                pop_front();
            }
        }

        /** Swap this list contents with another one */
        void swap(list<Item_Type>& other) {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
            std::swap(num_items, other.num_items);
        }

        /** Assign the contents of one list to another. */
        list<Item_Type>& operator=(const list<Item_Type>& other) {
            list<Item_Type> temp(other);
            swap(temp);
            return *this;
        }

        /** Insert an object at the beginning of the list.
            @param item - the item to be added 
         */
        void push_front(const Item_Type& item) {
            DNode* temp = new DNode(item, tail, head);
            if (head != nullptr) {
                head->prev = temp;
            } else {
                tail = temp;
            }
            head = temp;
            head->prev = tail;
            tail->next = head;
            ++num_items;
        }

        /** Insert an object at the end of the list.
            @param item - the item to be added 
         */
        void push_back(const Item_Type& item) {
            DNode* temp = new DNode(item, tail, head);
            if (tail != nullptr) {
                tail->next = temp;
            } else {
                head = temp;
            }
            tail = temp;
            head->prev = tail;
            tail->next = head;
            ++num_items;
        }

        /** Insert an object at a position in the list
            indicated by an iterator.  The new item is
            inserted before the position indicated by
            the iterator.
            @param pos The iterator that references the 
                       position where the item is to be
                       inserted.
            @param item The item to be inserted
            @return An iterator that references the inserted
                    item.
         */
        iterator insert(iterator pos, const Item_Type& item) {
            if (pos == begin()) {
                push_front(item);
                return begin();
            } else if (pos == end()) {
                push_back(item);
                return --end();
            } else {
                DNode* posNode = pos.current;
                DNode* temp = new DNode(item, posNode, posNode->prev);
                posNode->prev->next = temp;
                posNode->prev = temp;
                ++num_items;
                return iterator(this, temp, pos.index);
            }
        }
		
        /*<exercise chapter="4" section="7" type="programming" number="1">*/

        /** Get a reference to the first element in the list.
            This can be used on either side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        Item_Type& front() {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            return head->data;
        }

        /** Get a constant reference to first element in the list.
            This can only be used on the right side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        const Item_Type& front() const {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            return head->data;
        }

        /*<exercise chapter="1" section="7" type="programming" number="2">*/

        /** Get a reference to the last element in the list.
            This can be used on either side of an assignment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        Item_Type& back() {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            return tail->data;
        }

        /** Get a constant reference to the last element in the list.
            This can only be used on the right side of an assignment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        const Item_Type& back() const {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            return tail->data;
        }
        /*</exercise>*/

        /** Query the size of the list
            @return The number of objects in the list 
         */
        int size() const {
            return num_items;
        }

        /** Indicate if the list is empty
            @return true if the list is empty
         */
        bool empty() const {
            return num_items == 0;
        }

        /** Remove the first item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_front() {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            DNode* temp = head;
            --num_items;
            if (num_items != 0) {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            } else {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }

        /** Remove the last item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_back() {
            if (num_items == 0) {
                throw std::invalid_argument("List is empty.");
            }
            DNode* temp = tail;
            --num_items;
            if (num_items != 0) {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            } else {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }

        /** Remove an item referenced by an iterator
            @param pos An iterator referencing the item to
            be removed
            @return An iterator that referenced the item
            following the item being removed
            @throws std::invalid_argument if the list is empty
                    or if pos references end()
         */
        iterator remove(iterator pos) {
            if (num_items == 0) {
                throw std::invalid_argument("Invalid position.");
            }
            DNode* posNode = pos.current;
            iterator temp = pos;
            temp++;
            iterator out(this, temp.current, temp.index - 1);
            if (posNode == head) {
                pop_front();
                return begin();
            } else if (posNode == tail) {
                pop_back();
                return end();
            } else {
                posNode->prev->next = posNode->next;
                posNode->next->prev = posNode->prev;
                delete posNode;
                --num_items;
                return out;
            }
        }
        /*<exercise chapter="4" section="7" type="programming" number="4>*/

        /** Remove all occurences of a value from the list
            @param item The value to be removed
         */
        void remove(const Item_Type& item) {
            iterator iter = begin();
            while (iter != end()) {
                if (*iter == item) {
                    iter = remove(iter);
                } else {
                    ++iter;
                }
            }
        }
        /*</exercise>*/

        /*<exercise chapter="4" section="3" type="programming" number="3">*/

        /** Return an iterator to the beginning of the list
            @return an itertor to the beginning of the list
         */
        iterator begin() {
            return iterator(this, head, 0);
        }

        /** Return a const_iterator to the beginning of
            the list
            @return a const_iterator to the beginning of
            the list
         */
        const_iterator begin() const {
             return const_iterator(this, head, 0);
        }
        /*</exercise>*/

        /** Return an iterator to the end of the list
            @return an iterator to the end of the list
         */
        iterator end() {
             return iterator(this, head, num_items);
        }

        /** Return a const_iterator to the end of the list
            @return a const_iterator to the end of the list
         */
        const_iterator end() const {
             return const_iterator(this, head, num_items);
        }
        /**
         * if found the target, return the iterator to the current position.
         * return NULL if the target is not in the list.
         * @param target
         * @return iterator points to the found target; NULL otherwise.
         */
        
        iterator find(const Item_Type& target) {
            for (iterator iter = begin(); iter != end(); ++iter) {
                if (*iter == target) {
                    return iter;
                }
            }
            return iterator(this, nullptr, 0);
        }
    }; // End list

    
} // End namespace KW

#endif
