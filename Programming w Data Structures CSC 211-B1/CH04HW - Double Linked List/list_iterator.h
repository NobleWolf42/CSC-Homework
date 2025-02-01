/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

// Nested class iterator.
class iterator {
  // Give the parent class access to this class.
  friend class list<Item_Type>;
 private:
  // Data fields
  /** A reference to the parent list */
  list<Item_Type>* parent;
  /** A pointer to the current DNode */
  typename list<Item_Type>::DNode* current;
  // Member functions
  /** Constructs an iterator that references a specific DNode.
      Note: this constructor is private. Only the list class
      can create one from scratch.
      @param my_parent A reference to the list
      @param position A pointer to the current DNode
  */
  iterator(list<Item_Type>* my_parent, DNode* position) :
    parent(my_parent), current(position) {}
  
 public:
  /** Returns a reference to the currently referenced item.
      @return A reference to the currently referenced item
      @throws std::invalid_argument if this iterator is at end
  */ 
  Item_Type& operator*() const {
    if (current == nullptr) {
      throw std::invalid_argument("Iterator is at end");
    }
    return current->data;
  }
  
  /** Returns a pointer to the currently referenced item.
      Item_Type must be a class or struct. This restriction
      is enforced by the compiler.
      @return A pointer to the currently referenced item
      @throws std::invalid_argument If this iterator is at end
  */
  Item_Type* operator->() const {
    if (current == nullptr) {
      throw std::invalid_argument("Iterator is at end");
    }
    return &(current->data);
  }
  
  /** Advances the iterator forward.
      @return A modified version of this iterator that now 
      references the next forward position
      @throws std::invalid_argument If this iterator is at end
  */
  iterator& operator++() {
    if (current == nullptr) {
      throw std::invalid_argument("Iterator is at end");
    }
    current = current->next;
    return *this;
  }
  
  /** Moves the iterator backward.
      @return A modified version of this iterator that
      now references the previous position
      @throws std::invalid_argument If this iterator is at begin
  */
  iterator& operator--() {
    if (current == nullptr) {
      current = parent->tail;
    } else {
      current = current->prev;
    }
    if (current == nullptr) {
      throw std::invalid_argument("Iterator is at begin");
    }
    return *this;
  }
  
  /** Postfix increment operator.
      @return A copy of this iterator before being advanced
  */
  iterator operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }
  
  /** Postfix decrement operator.
      @return A copy of this iterator before moving backward
  */
  iterator operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
  }
  
  // Compare for equality.
  bool operator==(const iterator& other) {
    return current == other.current;
  }
  
  // Not equal
  bool operator!=(const iterator& other) {
    return current != other.current;
  }
  
}; // End iterator

#endif
